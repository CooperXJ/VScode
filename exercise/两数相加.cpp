#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct listNode{
	int val;
	listNode *next;
	//listNode(int x):val(x),next(NULL){
	//}
}ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(!l1)
    	return l2;
    	if(!l2)
    	return l1;
    	
    	ListNode *L1 = l1->next;
		ListNode *L2 = l2->next;
		 
    	ListNode *head;
    	head = (ListNode*)malloc(sizeof(ListNode));
		
		ListNode *rear;
		rear = head; 
    	int carry = 0;
    	while(L1&&L2)
    	{
    		ListNode *L = (ListNode*)malloc(sizeof(ListNode));
    		if(carry ==0)
    		{
    			L->val = 0;
			}
    	
    		
    		if(carry!=0)
    		{
    			L->val = 1;
    			//cout<<"ÒÑ¾­¼Ó1"<<endl; 
			}
    		
    		carry = (L1->val+L2->val)/10;
    		
    		if(carry==0)
    		{
    			L->val += (L1->val+L2->val)%10; 
    			//cout<<"l1 :"<<L1->val<<"  L2  :"<<L2->val<<endl;
			} 
    			//->val += (L1->val+L2->val)%10;
    		
    		if(carry!=0)
    		{
    			L->val += (L1->val+L2->val)%10;
    			//cout<<"carry:  "<<carry<<endl;
    			//cout<<"l1 :"<<L1->val<<"  L2  :"<<L2->val<<endl;
    			//cout<<L->val<<endl;
			}
			//cout<<L->val<<endl;
			
			rear->next = L;
			rear = L;
			
    		L1 = L1->next;
    		L2 = L2->next;
		}
		
		if(carry ==1)
		{
			ListNode *L = (ListNode*)malloc(sizeof(ListNode));
			L->val = carry;
			rear->next = L;
			rear = L;	
		}
		
		rear->next = NULL;
		return head;
    }
    
};

ListNode * createList(ListNode *L,int len)
{
	ListNode  *rear = L; 
	
	for(int i =0;i<len;i++)
	{
		ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		//cout<<"i: "<<i<<endl;
		cin>>p->val;
		
		rear->next = p;
		rear = p;
	 }
	 //cout<<"1"<<endl;
	 rear->next = NULL;
	 //cout<<"L: "<<L->next->next->next->val<<endl;
	 return L; 
}

void showList(ListNode *L)
{
	ListNode *p = L->next;
	int n = 1;
	while(p)
	{
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
 } 
 
int main()
{
	ListNode l1;
	createList(&l1,3);
	//showList(&l1);
	ListNode l2;
	createList(&l2,3);
	//showList(&l2);
	
	Solution s;
	ListNode *L = s.addTwoNumbers(&l1,&l2);
	showList(L);
	return 0;
}














