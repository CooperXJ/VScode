#include <stdio.h>
#include <stdlib.h>
typedef struct LST
{
	int num; 
	struct LST *next;
} LST;

LST *create()
{
	LST *head,*node,*end;
	head = (LST*)malloc(sizeof(LST));
	end = head;
	printf("请输入链表数据(整型)并以空格空开,以-1为最后一个数,回车结尾:\n");
	for(;;)
	{
		int val;
		scanf("%d",&val);
		if(val==-1)
		{
			break;
		}
		else
		{
			node = (LST*)malloc(sizeof(LST));
			node->num = val;
		
			end->next = node;
			end = node;
		}
	}
	
	end->next = NULL;
	return head;
}

void show(LST *list)
 {
 	LST *t = list->next;
 	while(t!=NULL)
 	{
 		printf("%d ",t->num);
 		t = t->next;
	}
	printf("\n");
 }
 
void delet(LST *head)
{
	LST *t = head;
	while(t!=NULL)
	{
		if(t->next->num==1)
		{
			t->next = t->next->next;
			break;
		}
	}
}

void check_repeated(LST *head1,LST *head2)
{
	LST *t1 = head1;
	LST *t2 = head2;
	while(t1!=NULL)
	{
		while(t2!=NULL)
		{
			if(t1->next->num==t2->next->num)
			{
				printf("%d\n",t1->next->num);
				t1->next = t1->next->next;
				break;
			}
			t2 = t2->next;
			puts("123");
		}
		t1 = t1->next;
	}

}

int main()
{
	LST *head1 = create();
	LST *head2 = create();
	//show(head1);
	//show(head2);
	//delet(head1);
	//show(head1);
	check_repeated(head1,head2);
	show(head1);
	return 0; 
 } 
