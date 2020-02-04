#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node{
    int val;
    struct Node* next;
}ListNode;

ListNode * Create(int len)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *h = head;
    for(int i = 0;i<len;i++)
    {
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        int val;
        scanf("%d",&val);
        p->val = val;
        h->next = p;
        h = p;
    }
    h->next = NULL;
    return head;
}

void Insert(ListNode *head,int pos,int val)
{
    pos = pos -1;
    int i = 0;
    ListNode *p = head;
    while(pos!=i++)
    {
        p = p->next;
    }
    ListNode *aim = (ListNode*)malloc(sizeof(ListNode));
    aim->val = val;

    aim->next = p->next;
    p->next = aim;
}

void Delete(ListNode *head,int val)
{
    ListNode *pre,*p;
    p = head;

    while(p->val!=val)
    {
        pre = p;
        p = p->next;
    }

    pre->next = p->next;
    free(p);
}

void Show_List(ListNode *head)
{
    ListNode *p = head->next;
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *head = Create(3);
    Show_List(head);
    Insert(head,3,10);
    Show_List(head);
    Delete(head,3);
    Show_List(head);
    system("pause");
}