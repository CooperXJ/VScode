#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct  node * next;
    
}LinkList;

LinkList* create_List()
{
    puts("input the number of the LinkList:");
    int len;
    scanf("%d",&len);

    LinkList *head,*end,*node;
    head = (LinkList*)malloc(sizeof(LinkList));
    end = head;

    for(int i =0;i<len;i++)
    {
        node = (LinkList*)malloc(sizeof(LinkList));
        int val;
        scanf("%d",&val);
        node->val = val;
        end->next = node;
        end = node;
    }

    end->next = NULL;
    return head;
}

void search_List(LinkList *head,int pos)
{
    LinkList *p = head;
    int i =0;
    while(p!=NULL&&i<pos)
    {
        p = p->next;
        i++;
    }
    if(p==NULL)
    {
        puts("your position is wrong!");
    }
    else
    {
        printf("The node is %d\n",p->val);
    }
    
}

void insert_List(LinkList *head,int pos)
{
    LinkList * p = head;
    LinkList *node = (LinkList*)malloc(sizeof(LinkList));
    int i = 1;
    while(p!=NULL&&i<pos)
    {
        p = p->next;
        i++;
    }

    if(p==NULL)
    {
        puts("your position is wrong!");
    }
    else
    {
        int val;
        puts("input your value:");
        scanf("%d",&val);
        node->val = val;
        node->next = p->next;
        p->next = node;
    }
    
}

void delete_List(LinkList* head,int pos)
{
    LinkList *p = head;
    LinkList *in;
    int i = 0;
    while(i<pos&&p!=NULL)
    {
        in = p;
        p = p->next;
        i++;
    }

    if(p==NULL)
    {
        puts("your position is wrong!");
    }
    else
    {
        in->next = p->next;
        free(p);
    }
    
}

void show_List(LinkList *head)
{
    LinkList *p = head->next;//这里一定要注意
    while(p!=NULL)
    {
        printf("%d ",p->val);//顺序不能改变否则会读到NULL指针！！
        p = p->next;
    }

    printf("\n");
}

void change_List(LinkList *head,int pos)
{
    LinkList* p = head;
    int i = 0;
    while(p!=NULL&&i<pos)
    {
        p = p->next;
        i++;
    }

    if(p==NULL)
    {
        puts("your position is wrong!");
    }
    else
    {
        int val;
        puts("input your changed value:");
        scanf("%d",&val);
        p->val = val;
    }
    
}


int main()
{   
    LinkList *head;
    head = create_List();
    show_List(head);
    insert_List(head,7);
    show_List(head);
    search_List(head,7);
    change_List(head,7);
    show_List(head);
    delete_List(head,7);
    show_List(head);
    system("pause");
}