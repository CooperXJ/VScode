#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
}LinkList;

LinkList* create_List(int len)
{
    LinkList *head,*node,*end;
    head = (LinkList*)malloc(sizeof(LinkList));
    end = head;//使得end指向head头节点
    int i;
    for(i =0;i<len;i++)
    {
        node = (LinkList*)malloc(sizeof(LinkList));
        int val;
        scanf("%d",&val);
        node->val = val;
        end->next = node;
        end = node;//end指向node
    }

    end->next = NULL;
    return head;
}

//以下都是用 p = head的原因为head最好为固定的值，因为一旦发生变化的话，会使得下面对链表的难以进行
void show_List(LinkList *head)
{
    LinkList *p = head->next;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p = p->next;//这里的顺序不能反，因为此处需要指向end的下一个为空
    }
    printf("\n");
}

void change(LinkList *head,int pos)
{
    LinkList *p = head->next;
    int i = 1;
    while(p!=NULL&&i<pos)
    {
        p = p->next;
        i++;
    }

    if(p!=NULL)
    {
        puts("input your new value");
        int val;
        scanf("%d",&val);
        p->val = val;
    }
    else
    {
        puts("the node not exist!");
    }    
}

void insert_List(LinkList *head,int pos,int len)
{
    if(pos>len+1||pos<1)
    {
        puts("Your position is invalid!");
        return;
    }
    else
    {
        LinkList *p = head;
        int i = 1;
        while(i<pos)
        {
            p = p->next;
            i++;
        }

        LinkList *new_node = (LinkList*)malloc(sizeof(LinkList));
        int val;
        puts("Please input the value of the inserted node: ");
        scanf("%d",&val);
        new_node->val = val;

        new_node->next = p->next;
        p->next = new_node;
    }
    
}

void delete_List(LinkList *head,int pos,int len)
{
    if(pos>len||pos<1)
    {
        puts("Your positon is invalid!");
        return;
    }
    else
    {
        LinkList *p = head;
        LinkList *q;//为了删除节点,采用q表示pos的前一个结点
        int i = 0;
        while(i<pos)
        {
            q = p;
            p = p->next;
            i++;
        }

        q->next = p->next;
        free(p);
    }
    
}

void search_list(LinkList *head,int pos)
{
    LinkList *p = head;
    int i = 0;
    while(i<pos&&p!=NULL)
    {
        p = p->next;
        i++;
    }
    printf("%d\n",p->val);
}

int main()
{
    printf("你好\n");
    LinkList *head = create_List(6);
    show_List(head);
    change(head,7);
    show_List(head);
    insert_List(head,7,6);
    show_List(head);
    delete_List(head,7,7);
    show_List(head);
    search_list(head,6);
    system("pause");
}

