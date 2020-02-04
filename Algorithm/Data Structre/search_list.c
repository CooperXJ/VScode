#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	int val;
	struct node *next;
}LinkList;

LinkList *create_List()
{
	int len = 6;
	LinkList *head,*end,*node;
	head = (LinkList*)malloc(sizeof(LinkList));
	end = head;
	
	printf("输入数组%d个元素的值。\n",len);
	int i;
	for(i = 0;i<len;i++)
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

void change_val(LinkList *head)
{
	printf("输入要删除的数据x: ");
	int val;
	scanf("%d",&val);
	
	LinkList *p = head->next;
	LinkList *in = head; 
	while(p!=NULL)
	{
		//p = p->next;如果这里出现NULL的话会使得下面的p->val 无法执行！！！ 
		if(p->val==val)
		{
			break;
		}
		p = p->next;
		in = in->next;
	}
	
	if(p!=NULL)
	{
		in->next = p->next;
	}
	else
	{
		in->next = NULL;
	}
	free(p);
 }
 
 void show_List(LinkList *head)
 {
 	LinkList *p = head->next;
 	while(p!=NULL)
 	{
 		printf("%d ",p->val);
 		p = p->next;
	}
	
	printf("\n");
}
  
   
int main()
{
	LinkList *head;
    head = create_List();
    printf("此链表各个结点的数据域为：");
    show_List(head); 
    change_val(head);
    printf("删除后链表各个结点的数据域为：");
    show_List(head);
}