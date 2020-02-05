#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

//vector是单口容器

void test0()
{
    vector<int> v1;
    int arr[] = {10,20,30,40};
    vector<int> v2(arr,arr+sizeof(arr)/sizeof(int));//数组初始化
    vector<int> v3(v2.begin(),v2.end());//vector初始化
    vector<int> v4(v3);//复制构造函数
}


//vector 复制操作
void test1()
{
    int arr[] = {10,20,30,40};
    vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
    
    //调用成员函数
    vector<int> v2;
    v2.assign(v1.begin(),v2.end());
    
    //重载操作符=
    vector<int> v3;
    v3 = v2;

    //交换（内部指针互换，并非是内部元素相互互换）
    int arr1[] = {100,200,300,400};
    vector<int> v4(arr,arr+sizeof(arr)/sizeof(int));

    v4.swap(v3);
    
}

void print_vector(int i)
{
    cout<<i<<" ";
}

//vector resize、size和capacity
void test2()
{
    //容量与size可能是不相同的，因为每次动态申请内存的时候不可能有一个就申请一个空间
    //他是一次性申请一块空间，有可能size正好和capacity相同，但是也有可能不相同
    vector<int> v1(10);
    v1.resize(11,1);//resize 
    //当resize指定空间较小时，会自动删除后面的元素
    //当resize指定空间较大时，会自动填补默认值0（如果没有指定的话）
    cout<<v1.capacity()<<endl;
    cout<<v1.size()<<endl;

    for_each(v1.begin(),v1.end(),print_vector);
}

//vector 访问
void test3()
{
    //fornt返回第一个元素，back返回最后一个元素
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    v.insert(v.begin(),30);
    v.insert(v.end(),40);

    v.insert(v.begin()+1,50);//insert支持随机访问
    for_each(v.begin(),v.end(),print_vector);

    cout<<endl;

    v.erase(v.begin()+1,v.end());//删除操作
    for_each(v.begin(),v.end(),print_vector);
    v.clear();//清楚所有
}

//使用swap所见空间
void test4()
{
    //vector添加元素他会自动增长，但是删除元素的时候，他不会自动减少
    vector<int> v1;
    for(int i =0;i<10000;i++)
    {
        v1.push_back(i);
    }
    cout<<v1.capacity()<<endl;
    v1.resize(100);//删除了之后不会自动减少内存空间
    cout<<v1.capacity()<<endl;

    vector<int>(v1).swap(v1);
    /*
    思路：
    先初始化一个匿名对象，匿名对象初始化是使用v1来初始化的，匿名对象会根据v1中的实际
    个数来初始化他自身，因此匿名对象的内存空间是实际v1的大小，swap之后就会将v1的指针指向匿名
    对象，而匿名对象的指针指向原来的v1内存空间，从而达到转换作用
    */
    cout<<v1.capacity()<<endl;
}

//vector 申请空间  
//使用情况：
//当所要申请的空间比较大并且大概知道大小的时候，可以使用该函数，这样的话的可以节约时间
void test5()
{
    vector<int> v;
    v.reserve(1000);//reserve只是开辟内存空间，并没有初始化
    //resize之后可以直接使用了，因为它有默认值
}


int main()
{
    test5();
    system("pause");
}