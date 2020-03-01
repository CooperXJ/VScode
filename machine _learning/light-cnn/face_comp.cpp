/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2018, Open AI Lab
 * Author: minglu@openailab.comm
 *
 */
#include "mipi_cam.hpp"
#include <string>
#include <sys/time.h>
#include "mtcnn.hpp"
#include "lightcnn.hpp"
#include "mtcnn_utils.hpp"

const string wintitle = "mipi-camera";
static const char *short_options = "m:t:w:h:r:VHc:";

#define COLOR_GREEN fcv::Scalar(0, 255, 0)
#define COLOR_RED   fcv::Scalar(0, 0, 255)
#define COLOR_BLUE  fcv::Scalar(255, 0, 0)
#define COLOR_YELLOW  fcv::Scalar(0, 255, 255)
#define COLOR_MAGENTA fcv::Scalar(255, 0, 255)
#define COLOR_CYAN    fcv::Scalar(255, 255, 0)

static struct option long_options[] = {
    {"mipi", required_argument, NULL, 'm'},
    {"type", required_argument, NULL, 't'},
    {"width", required_argument, NULL, 'w'},
    {"height", required_argument, NULL, 'h'},
    {"rotate", required_argument, NULL, 'r'},
    {"vflip", no_argument, NULL, 'V'},
    {"hflip", no_argument, NULL, 'H'},
    {"crop", required_argument, NULL, 'c'},
    {NULL, 0, NULL, 0}
};

/* calculate cosine distance of two vectors */
float cosine_dist(float* vectorA, float* vectorB, int size)
{
    float Numerator=0;
    float Denominator1=0;
    float Denominator2=0;
    float Similarity;
    for (int i = 0 ; i < size ; i++)
    {
        Numerator += (vectorA[i] * vectorB[i]);
        Denominator1 += (vectorA[i] * vectorA[i]);
        Denominator2 += (vectorB[i] * vectorB[i]);
    }

    Similarity = Numerator/sqrt(Denominator1)/sqrt(Denominator2);

    return Similarity;
}

/* get face image with face detection results */
void get_face_image(fcv::Mat& img,std::vector<face_box>& face_list, fcv::Mat& faceImg)
{
    float boxSize=0;
    float maxWidth=0;
    int maxI = 0;
    float faceWidth = 0;
    fcv::Size faceSize(FACEWIDTH,FACEHEIGHT);


    /* Select face with largest size */
    for ( unsigned int i = 0; i < face_list.size(); i++)
    {
        face_box &box = face_list[i];
        boxSize = box.x1 - box.x0;
        if (boxSize>maxWidth)
        {
            maxWidth = boxSize;
            maxI = i;
        }
    }
    face_box &box = face_list[maxI];

    /* calculate face width in oringal image */
    faceWidth = (box.landmark.x[1] - box.landmark.x[0])/0.53194925;

    /* calculate face roi for image cropping */
    fcv::Rect roi;
    roi.x = box.landmark.x[0]-(0.224152*faceWidth);
    roi.y = (box.landmark.y[0]+box.landmark.y[1])/2-(0.2119465*faceWidth);
    roi.width = faceWidth;
    roi.height = faceWidth;

    std::cout << "FaceWidth=" << faceWidth << endl;

    /* crop face image */
    fcv::Mat cropA = img(roi);

    /* resize image for lcnn input */
    fcv::resize(cropA,faceImg,faceSize);

}

static void parse_crop_parameters(char *crop, __u32 *cropx, __u32 *cropy, __u32 *cropw, __u32 *croph)
{
    char *p, *buf;
    const char *delims = ".,";
    __u32 v[4] = {0,0,0,0};
    int i = 0;

    buf = strdup(crop);
    p = strtok(buf, delims);
    while(p != NULL) {
        v[i++] = atoi(p);
        p = strtok(NULL, delims);

        if(i >=4)
            break;
    }

    *cropx = v[0];
    *cropy = v[1];
    *cropw = v[2];
    *croph = v[3];
}

static void usage(char **argv)
{
    printf(
        "Usage: %s [Options]\n\n"
        "Options:\n"
        "-m, --mipi                   Mipi camera: 1 -- mipi1 cmaera; 2 -- mipi2 camera, default: 1"
        "-t, --type                   Mipi camera type: ov9750 or imx258, default: ov9750"
        "-w, --width                  Destination images's width\n"
        "-h, --height                 Destination images's height\n"
        "-r, --rotate                 Image rotation degree, the value should be 90, 180 or 270\n"
        "-V, --vflip                  Vertical Mirror\n"
        "-H, --hflip                  Horizontal Mirror\n"
        "-c, --crop                   Crop, format: x,y,w,h\n"
        "\n",
        argv[0]);
}

int main(int argc,char** argv)
{
    int ret, c, r;
    char v4l2_dev[64], isp_dev[64];
    char index = -1;
    pthread_t id;
    Mat image;
    struct timeval t0, t1;
	
	cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0,&mask);

    /*default image pair for comparing*/
    std::string imgA_name = "./images/George_W_Bush_0009.jpg";
    //std::string imgB_name = "./images/George_W_Bush_0031.jpg";

     std::string saveA_name = "./faceA.jpg";
    // std::string saveB_name = "./faceB.jpg";

    /* Variable definition */
    fcv::Mat faceImage;

    float *featureA = (float*)malloc(sizeof(float)*FEATURESIZE);
    float *featureB = (float*)malloc(sizeof(float)*FEATURESIZE);

    std::string model_dir = "./models/";
    std::vector<face_box> face_info;

    if(argc<=2)//此处的argc 是在make文件输入的吗？
    {
        std::cout<<"[usage]: "<<argv[0]<<" <imageA.jpg> <imageB.jpg> <model_dir>\n";
    }
    if(argc >=3 )
    {
        imgA_name=argv[1];
    }
    if(argc >=4 ) model_dir=argv[2];


    fcv::Mat imageA = fcv::imread(imgA_name);
    if (imageA.empty())
    {
        std::cerr<<"fcv::imread "<<imgA_name<<" failed\n";
        return -1;
    }


    /* Tengine -- initialization */
    if (init_tengine_library()<0)
    {
	std::cout << " init tengine failed\n";
	return 1;
    }

    if(request_tengine_version("0.1")<0)
    {
        release_tengine_library();
        return -2;
    }

    /* MTCNN -- default value */
    int min_size=60;
    float conf_p=0.6;
    float conf_r=0.7;
    float conf_o=0.8;
    //Pnet Rnet Onet  阈值
    float nms_p=0.5;  
    float nms_r=0.7;
    float nms_o=0.7;

    /* MTCNN -- initialization */
     mtcnn* det = new mtcnn(min_size,conf_p,conf_r,conf_o,nms_p,nms_r,nms_o);
   
    /* MTCNN -- load models */
    det->load_3model(model_dir);

    /* LightCNN -- initialization */
    lightcnn l;
    l.init(model_dir);

    float timeAlgo;

    
    gettimeofday(&t0, NULL);
    /* MTCNN -- detect faces in image */
    face_info.clear();
    det->detect(imageA, face_info);

    gettimeofday(&t1, NULL);
    timeAlgo = (float)((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec)) / 1000;
    std::cout <<  "Time on face detection(image A) is " << timeAlgo << "ms" << endl;

    if (face_info.size()==0)
    {
        std::cout <<  "Can not detect face in " << imgA_name << endl;
        release_tengine_library();
        return -2;
    }

    /* Get face from original image */    
    get_face_image(imageA,face_info,faceImage);
    fcv::imwrite(saveA_name,faceImage);

    gettimeofday(&t0, NULL);
    /* extract feature from face image with light cnn*/
    l.featureExtract(faceImage,featureA);

    gettimeofday(&t1, NULL);
    timeAlgo = (float)((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec)) / 1000;
    std::cout <<  "Time on feature extraction (image A) is " << timeAlgo << "ms" << endl;

    /* Window -- create */
    fcv::namedWindow(wintitle);
    fcv::moveWindow(wintitle, 720, 480);

    /* MIPI Camera -- default values */
    int mipi = 1;    /* main camera */
    enum CAM_TYPE type = CAM_OV9750; /* HD camera sensor: OV9750 */
    __u32 width = 640, height = 480; /* resolution: 640x480 */
    RgaRotate rotate = RGA_ROTATE_NONE; /* No rotation */
    __u32 cropx = 0, cropy = 0, cropw = 0, croph = 0;
    int vflip = 0, hflip = 0; /* no flip */

    while((c = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        switch (c) {
        case 'm':
            mipi = atoi(optarg);
            break;
        case 't':
            if(strncmp(optarg, "ov9750", 6) == 0)
                type = CAM_OV9750;
            if(strncmp(optarg, "imx258", 6) == 0)
                type = CAM_IMX258;
            break;
        case 'w':
            width = atoi(optarg);
            break;
        case 'h':
            height = atoi(optarg);
            break;
        case 'r':
            r = atoi(optarg);
            switch(r) {
            case 0:
                rotate = RGA_ROTATE_NONE;
                break;
            case 90:
                rotate = RGA_ROTATE_90;
                break;
            case 180:
                rotate = RGA_ROTATE_180;
                break;
            case 270:
                rotate = RGA_ROTATE_270;
                break;
            default:
                printf("roate %d is not supported\n", r);
                return -1;
            }
            break;
        case 'V':
            vflip = 1;
            break;
        case 'H':
            hflip = 1;
            break;
        case 'c':
            parse_crop_parameters(optarg, &cropx, &cropy, &cropw, &croph);
            break;
        default:
            usage(argv);
            return 0;
        }
    }

    if (type == CAM_IMX258)
    {
        type = CAM_OV9750;
        printf ("IMX258 is not supported currently. Use OV9750 instead!\n");
    }

    /* V4L2 device */
    sprintf(v4l2_dev, "/dev/video%d", 4 * (mipi - 1) + 2);
    sprintf(isp_dev, "/dev/video%d", 4 * (mipi - 1) + 1);

    printf("width = %u, height = %u, rotate = %u, vflip = %d, hflip = %d, crop = [%u, %u, %u, %u]\n",
           width, height, rotate, vflip, hflip, cropx, cropy, cropw, croph);



    /* MIPI Camera -- initialization */
    v4l2Camera v4l2(width, height, rotate, vflip, hflip, cropx, cropy, cropw, croph, V4L2_PIX_FMT_NV12);
    image.create(cv::Size(RGA_ALIGN(width, 16), RGA_ALIGN(height, 16)), CV_8UC3);
    ret = v4l2.init(v4l2_dev, isp_dev, type);
    if(ret < 0)
    {
        printf("v4l2Camera initialization failed.\n");
        return ret;
    }

    /* MIPI Camera -- open stream */
    ret = v4l2.streamOn();
    if(ret < 0)
        return ret;

     while(1) {
        gettimeofday(&t0, NULL);
        /* MIPI Camera -- read video frame */
        if(ret = v4l2.readFrame(V4L2_PIX_FMT_RGB24,image) < 0)
            return ret;

        /* Algorithm -- detect faces in image */
        face_info.clear();//这行如果不删除的话，会使得上一帧的人脸检测的窗口重复显示
        det->detect(image, face_info);
       

        gettimeofday(&t1, NULL);

        std::cout << "detected face num: " << face_info.size() << "\n";
        /* Algorithm -- drawing results	*/
        for (unsigned int i = 0; i < face_info.size(); i++)
        {
            face_box &box = face_info[i];
            std::printf("Face box(%d):( %g , %g ),( %g , %g )\n", i, box.x0, box.y0, box.x1, box.y1);
            fcv::rectangle(image, fcv::Point(box.x0, box.y0), fcv::Point(box.x1, box.y1), COLOR_GREEN, 1);
            for (int l = 0; l < 5; l++)
            {
                fcv::circle(image, fcv::Point(box.landmark.x[l], box.landmark.y[l]), 1, COLOR_MAGENTA, 2);
            }

             
        }

        
        /* Window -- drawing frame */
        fcv::imshow(wintitle, image, NULL);
        gettimeofday(&t1, NULL);
        fcv::waitKey(1);
        long elapse = ((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec)) / 1000;
        
        // /* Get face from original image */
         get_face_image(image,face_info,faceImage);
         l.featureExtract(faceImage,featureB);


         float similarity = cosine_dist(featureA, featureB, FEATURESIZE);
         std::cout << "user"<<"["<<i<<"]"<<"    Similarity: " << similarity << endl;
        //cout <<"fastcv::imshow costs "<< elapse <<" miliseconds"<< endl;

    }

    // gettimeofday(&t0, NULL);
    // /* MTCNN -- detect faces in image */
    // face_info.clear();
    // det->detect(imageB, face_info);
    
    // gettimeofday(&t1, NULL);

    // timeAlgo = (float)((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec)) / 1000;
    // std::cout <<  "Time on face detection(image B) is " << timeAlgo << "ms" << endl;

    // if (face_info.size()==0)
    // {
    //     std::cout <<  "Can not detect face in " << imgB_name << endl;
    //     release_tengine_library();
    //     free(featureA);
    //     return -2;
    // }

    // /* Get face from original image */
    // get_face_image(imageB,face_info,faceImage);
    // fcv::imwrite(saveA_name,faceImage);

    // gettimeofday(&t0, NULL);

    // /* extract feature from face image with light cnn*/
    // l.featureExtract(faceImage,featureB);

    // gettimeofday(&t1, NULL);
    // timeAlgo = (float)((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec)) / 1000;
    // std::cout <<  "Time on feature extraction (image B) is " << timeAlgo << "ms" << endl;





    // /* calculte similarity of two face features */
    // float similarity = cosine_dist(featureA, featureB, FEATURESIZE);
    // std::cout << "Similarity: " << similarity << endl;

    /* Tengine -- deinitialization */
    release_tengine_library();

    /* MIPI Camera -- close stream */
    ret = v4l2.streamOff();

    free(featureA);
    free(featureB);


    return  0;
}
