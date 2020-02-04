#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class MyException{
    public:
        MyException(char *error)
        {
            this->error = new char[strlen(error)+1];//此处只是声明了内存空间，但是error所代表的字符串是空的
            strcpy(this->error,error);//将error中的内容拷贝到error中
        }

        MyException(const MyException& ex)
        {
            this->error = this->error = new char[strlen(ex.error)+1];
            strcpy(error,ex.error);
        }

        MyException& operator=(const MyException& ex)
        {
            if(error!=NULL)
            {
                delete[] error;
                error = NULL;
            }
            this->error = this->error = new char[strlen(ex.error)+1];
            strcpy(error,ex.error);
        }

        ~MyException()
        {
           if(error!=NULL)
           {
               delete[] error;//这里要注意删除写的是delete[]  而不是delete
               cout<<"finished"<<endl;
           }
        }

        void show()
        {
            cout<<error<<endl;
        }

    private:
        char *error;
};

void test()
{
    throw MyException("This is my exception class!");//此处匿名对象有一个error指针
}

int main()
{
    try{
        test();
    }catch(MyException &e)//此处也有一个error指针  所以析构函数会被调用两次
    //加上&的话就指向了前面的匿名对象 因此析构函数指挥调用一次  
    //如果不加&的话就会执行两次析构函数
    {
        e.show();
    }


    system("pause");
}