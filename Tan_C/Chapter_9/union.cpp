#include <iostream>
#include <math.h>
using namespace std;

/*
    1.union的作用就是使得结构体中的所有变量都从同一个地址开始存储
    比如此例子中的age，name，f
    如果是struct则占用4+1+8个字节
    如果是union的话则占用max(4,1,8),即8个字节

    2.注意事项：
    不能对union中所有的成员进行赋值，例如
    union test
    {
        int age;
        char name;
        double f;
    }t{1，‘A’,1.0};
    这样是错误的，因为union只占用最大变量的内存空间

    union test
    {
        int age;
        char name;
        double f;
    }f{16};这样是正确的
*/
union test
{
    int age;
    char name;
    double f;
};

int main()
{
    union test t1;
    cout<<sizeof(t1)<<endl;;
    
    system("pause");
}