#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
   int data;
   struct Node *next; 
}LinkList;

LinkList * InitLinkList(LinkList *head)
{
    LinkList * node,*rear;
    head = (LinkList*)malloc(sizeof(LinkList));
    rear = head; 

    for(int i =0;i<6;i++)
    {
        node = (LinkList*)malloc(sizeof(LinkList));
        node->data = i+1;
        rear->next = node;
        rear = node;
    }
    rear->next = NULL;
    return head;
}

void showList(LinkList *head)
{
    LinkList *p = head;
    while(p->next)
    {
        p = p->next;
        cout<<p->data<<" ";
    }
    cout<<endl;
    return;
}

void InsertList(LinkList *head,int pos,int e)
{
    LinkList *p = head;//这个我如果写成p = head->next  如果插入的是第一个点的话就会失败
    int i = 1;
    while (p&&i<pos)
    {
        i++;
        p = p->next;
    }
    
    LinkList *node = (LinkList*)malloc(sizeof(LinkList));
    node->data = e;
    node->next = p->next;
    p->next = node;
    return;
}

void DeleteLinkList(LinkList *head,int pos)
{
    LinkList *p = head;
    int i = 1;
    while(p&&i<pos)
    {
        i++;
        p = p->next;
    }

    LinkList *q = p->next;
    p->next = q->next;
    free(q);
}

int main()
{
    LinkList *p;
    LinkList *head = InitLinkList(p);
    showList(head);
    InsertList(head,1,10);
    showList(head);
    DeleteLinkList(head,6);
    showList(head);
    system("pause");
}