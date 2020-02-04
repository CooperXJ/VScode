#include <iostream>
#include <malloc.h>
using namespace std;

#define MAXSIZE 20

typedef struct{
    int *data;//用数组表示顺序表
    int length;//线性表当前长度 当前长度用来反映线性表当前元素个数
    int List_size;
}SqList;

void InitList(SqList *L)
{
    L->data = (int*)malloc(sizeof(int)*MAXSIZE);
    if(L->data==NULL)
    {
        cout<<"malloc fail!"<<endl;
        exit(0);
    }
    L->length = 0;
    L->List_size = MAXSIZE;
}

void GetElem(SqList L,int i,int *e)
{
    if(L.length==0||i<1||i>L.length)
    {
        cout<<"your position is wrong!"<<endl;
        return;
    }

    *e = L.data[i-1];
    return;
}

void ListInsert(SqList *L,int i,int e)
{
    if(L->length==L->List_size)
    {
        cout<<"full!"<<endl;
        return;
    }
    if(i<1||i>L->length+1)
    {
        cout<<"your position is wrong!"<<endl;
        return;
    }
    for(int k = L->length;k>=i-1;k--)
    {
        L->data[k+1] = L->data[k];
    }
    L->data[i] = e;
    L->length++;
    return;
}

void ListDelete(SqList *L,int i,int *e)
{
    if(L->length==0)
    {
        cout<<"your list is empty!"<<endl;
        return;
    }
    if(i<1||i>L->length)
    {
        cout<<"your position is wrong!"<<endl;
        return;
    }

    *e = L->data[i-1];
    for(int k =i;k<L->length;k++)
    {
        L->data[k-1] = L->data[k];
    }

    L->length--;
    return;
}

void ListLength(SqList L)
{
    cout<<"your List have "<<L.length<<" elements!"<<endl;
    return;
}

void LocateElem(SqList L,int e)
{
    for(int i =0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            cout<<e<<" is equal to List's "<<i+1<<" element!"<<endl;
            return;
        }
    }

    cout<<"There is no "<<e<<" in the List！"<<endl;
    return;
}

void ListEmpty(SqList *L)
{
    free(L);
    cout<<"Your List doesn't exits any more!"<<endl;
    return;
}

void ShowList(SqList L)
{
    if(L.length==0)
    {
        cout<<"Your List is empty!"<<endl;
        return;
    }

    for(int i =0;i<L.length;i++)
    {
        cout<<L.data[i]<<" ";
    }

    cout<<endl;
    return;
}

int main()
{
    SqList *L;
    InitList(L);
    ShowList(*L);
}