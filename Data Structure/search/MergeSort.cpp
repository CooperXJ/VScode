#include <iostream>
using namespace std;

int B[10];
void Merge(int A[],int low,int mid,int high)//递归排序
{
    int i,j,k;
    for(k = low;k<=high;k++)//将A数组的内容复制到B数组中
    {
        B[k] = A[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
    {
        if(B[i]<=B[j])
            A[k] = B[i++];
        else
        {
            A[k] = B[j++];
        }
        
    }

    while(i<=mid) A[k++] = B[i++];//前一个较长没有比较完
    while(j<=high) A[k++] = B[j++];//后一个较长没有比较完
}

void MergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);//组合两个有序的顺序表
    }
}

int main()
{
    int A[10] = {10,3,4,5,2,1,6,8,7,9};
    MergeSort(A,0,9);

    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    system("pause");
}