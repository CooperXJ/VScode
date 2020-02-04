#include <stdio.h>
#include <stdlib.h>
int len = 0;

typedef struct node{
	int val;
	struct node *next;
}LinkList;

LinkList *createList()
{
	LinkList *head,*end,*node;
	head = (LinkList*)malloc(sizeof(LinkList));
	end = head;
	
	printf("\n请输入链表（非数表示结束）\n");
	while(1)
	{
		printf("结点值：");
		int val;
		if(!scanf("%d",&val))
		{
			break;
		}
		else
		{
			node = (LinkList*)malloc(sizeof(LinkList));
			node->val = val;
		
			end->next = node;
			end = node;
			len++;
		}
		
	}
	
	end->next = NULL;
	return head;
 } 
 
 void showList(LinkList *head)
 {
 	LinkList *p = head->next;
 	while(p!=NULL)
 	{
 		printf("%4d",p->val);
 		p = p->next;
	}
 }
 
 LinkList* inverseList(LinkList* head)
 {
 	LinkList *rear = (LinkList*)malloc(sizeof(LinkList));
 	LinkList *q  = rear;
 	LinkList *p = head->next;
 	int *arr = (int*)malloc(sizeof(int)*len);
 	int k = len-1;
 	while(p!=NULL)
 	{
 		arr[k] = p->val;
 		p = p->next;
 		k--;
	}
	
	k = 0;
	while(k<len)
	{
		LinkList *node = (LinkList*)malloc(sizeof(LinkList));
		node->val = arr[k++];
		q->next = node;
		q = node; 
	}
	q->next = NULL;
	return rear;
 }
 
 
void inverse(LinkList* head)
 {
 	LinkList *pCurr = head;
 	LinkList *pRev = NULL;
 	LinkList *t = NULL;
 	while(pCurr!=NULL)
 	{
 		t = pCurr;
 		pCurr = pCurr->next;
 		t->next = pRev;
 		pRev = t;
	}
	
	 LinkList *p = pRev;
	 while(p!=NULL&&p->next!=NULL)
	 {
	 	printf("%d ",p->val);
	 	p = p->next;
	 }
	 printf("\n");
 }
 
 
int main()
{
	LinkList *head = createList();
	printf("\n原来表：\n");
	showList(head);
	printf("\n\n");
	inverse(head);
	//printf("\n\n反转表：\n");
	//showList(rear);
 } 
