#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

typedef struct node{
    int val;
    struct node *next;
}Node;

Node* Create_LinkList(int count)
{
    Node *head = (Node*)malloc(sizeof(Node));
    Node *tail = head;
    tail->next = NULL;

    for(int i=0;i<count;i++)
    {
        Node *p = (Node*)malloc(sizeof(Node));
        p->val = i+1;
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }

    return head;
}

void show(Node *head)
{
    Node *p = head->next;
    //这里一定要使用while 不能使用if
    while (p!=NULL)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

void delete_Node(Node *head,int pos)
{
    Node *p = head;
    int count = 1;

    //这里不需要写成count!=pos-1  因为我数数本来就是从head开始的
    while (count!=pos&&p!=NULL)
    {
        p = p->next;
        count++;
    }
    
    Node *del_p = p->next;
    p->next = del_p->next;
    free(del_p);
}

int count_len(Node *head)
{
    Node *p = head;
    int len = -1;
    while (p!=NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//处理这段代码的时候一定注意到p=NULL的情况，因为在这种情况下会出现p->val无法读取的情况，因此在进行val读取时一定要先判断是否为null
void f(Node *head,int len)
{
   Node *p = head->next;
   
   int i = 0;
   while (len!=1)
   {
        i++;
        while (p!=NULL&&p->val==0)
        {
            p = p->next;
        }
        
        if(i==3&&p!=NULL)
        {
            cout<<p->val<<" ";
            p->val=0;
            i = 0;
            len--;
        }

        if(p==NULL)
        {
            p = head->next;
            //这里要i--是因为p==NULL也使得i++了一次
            i--;
        }
        else
        {
            p = p->next;
        }
        
   }
   
   cout<<endl;

   p = head->next;
   while (p!=NULL)
   {
       if(p->val!=0)
        cout<<p->val<<endl;

       p = p->next;
   }
   
}

int main()
{
    cout<<"input your count"<<endl;
    int count;
    cin>>count;

    Node *head = Create_LinkList(count);
    // show(head);
    // cout<<count_len(head)<<endl;
    // delete_Node(head,1);
    // show(head);
    // cout<<count_len(head)<<endl;
    f(head,count);
    system("pause");
}