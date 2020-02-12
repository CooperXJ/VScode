#include <iostream>
#include <math.h>
#include <deque>
#include <algorithm>
using namespace std;

void print_deque(int i)
{
    cout<<i<<" ";
}

void test0()
{
    deque<int> d;
    int arr[] = {1,2,3,4,5};

    d.assign(arr,arr+sizeof(arr)/sizeof(int));
    d.push_front(1);
    d.push_back(10);
    d.pop_front();
    for_each(d.begin(),d.end(),print_deque);
    cout<<endl;
}

int main()
{
    test0();
    system("pause");
 }