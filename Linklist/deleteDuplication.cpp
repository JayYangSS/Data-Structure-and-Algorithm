#include<iostream>
using namespace std;


/*delete all duplicated node in the link list, the dulplication is not reserved
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


//recursive method
//two conditions
ListNode* deleteDuplication(ListNode* pHead)
{
	if ((pHead == NULL) || (pHead->next == NULL))return pHead;
	if (pHead->val == pHead->next->val){
		ListNode* cur = pHead->next->next;
		while ((cur != NULL) && (pHead->val == cur->val)){
			cur = cur->next;
		}

		return deleteDuplication(cur);
	}
	else{
		pHead->next = deleteDuplication(pHead->next);
		return pHead;
	}

}


int main(){

	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(4);
	ListNode *n7 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	deleteDuplication(n1);

}