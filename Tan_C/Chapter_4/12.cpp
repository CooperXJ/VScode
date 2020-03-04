#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int judge(float x,float y)
{
    //vector存放pair需要声明pair的类型
    vector<pair<float,float>> point;
    pair<float,float> point1(-2,2);
    point.push_back(point1);
    pair<float,float> point2(2,2);
    point.push_back(point2);
    pair<float,float> point3(2,-2);
    point.push_back(point3);
    point.push_back(make_pair(-2,-2));

    for(int i =0;i<4;i++)
    {
        float distance = sqrt(pow((point[i].first-x),2)+pow((point[i].second-y),2));
        if(distance<=1)
            return 10;
        else
        {
            return 0;
        }       
    }
}

int main()
{
    cout<<judge(-2,3.14)<<endl;
    system("pause");
}