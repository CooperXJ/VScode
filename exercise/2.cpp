/*2018/7/31 19点17分 */ 
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;	
	ListNode(int x):val(x),next(NULL){}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *l = NULL;
    	ListNode *curr = l;
    	ListNode *p = l1,*q = l2;
    	int carry = 0;
        while(p->next!=NULL||q->next!=NULL)
        {
        	int x = (p!=NULL)?p->val:0;
        	int y = (q!=NULL)?q->val:0;
        	int sum = carry+x+y;
        	carry = sum/10;
        	curr->next->val = carry;
        	curr = curr->next;
        	if(p!=NULL) p = p->next;
			if(q!=NULL) q = q->next; 
		}
		
		if(carry>0)//进一位的数字 
		{
			curr->next->val = carry;
		}
		
		return l;
    }
};

int main()
{
	ListNode *l1,*l2;
	l1->val = 2;
	l1->next->val = 4;
	l1->next->next->val = 3;
	l2->val = 5;
	l2->next->val = 6;
	l2->next->next->val = 4;

	Solution s;
	ListNode *l = s.addTwoNumbers(l1,l2);
	cout<<l->val;
	cout<<l->next->val;
	cout<<l->next->next->val;
	cout<<endl;
 } 
