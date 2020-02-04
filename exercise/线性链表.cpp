/*19��58��   2018.11.6*/ 
#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}Node,*Linklist;

void createList(Linklist l,int len)
{
	Linklist list;
	list = l;
	
	for(int i = 0;i<len;i++)
	{
		Node *r = (Linklist)malloc(sizeof(Node));
		cin>>r->data;
		//cout<<"1"<<endl;
		list->next = r;//���ֱ�ӿ�ͷ����һ��ָ��Ļ�   ����ͻ������  ��Ϊ���ָ��û��next 
		list = r;
	}
	
	list->next = NULL;
}

void show(Linklist l)
{
	Linklist list;
	list = l->next;
	while(list)
	{
		//cout<<"1"<<endl;
		cout<<list->data<<" ";
		//cout<<"2"<<endl;
		list = list->next;
		//cout<<"1"<<endl;
	}
	
	cout<<endl;
}

int get(Linklist l,int i)
{
	Node *p;
	p = l->next;
	int j = 1;
	while(j<i)
	{
		p = p->next;
		j++;	
	}
	return p->data;
 } 
 
void insert(Linklist l,int i,int val)
{
	int j = 1;
	l = l->next;//ͷ��������˵� 
	while(j<i-1)
	{
		l = l->next;
		j++;
	}
	
	Node *p = (Node*)malloc(sizeof(node));
	p->data = val;
	
	p->next = l->next;
	l->next = p;
	cout<<"lָ�������"<<l->data<<endl; 
}

void del(Linklist l,int i)
{
	int j = 1;
	l = l->next;
	while(j<i-1)
	{
		l = l->next;
		j++;
	}
	
	Node * p = l->next;
	l->next = p->next;
	l = l->next;
	//free(l);
 } 
 
int main()
{
	Node n;//���   �����n��ͷ��㣬������ӵĻ��ͻᱨ��  ��Ϊָ���޷���Ϊһ��ʵ��node��Ҳ��û��data 
	Linklist list;
	list = &n;
	createList(list,5);
	show(list);
	cout<<get(list,4)<<endl;
	insert(list,3,6);
	//show(list);
	del(list,4);
	show(list);
	return 0;
}
