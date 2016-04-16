#include "LinkList.h"

//non recursive
Node* reverse(Node* const head){
	Node *p,*pre,*next;
	p=head;
	pre=NULL;
	next=head;
	//reverse option
	while(p!=NULL){
		next=p->next;
		if(p!=pre)p->next=pre;
		pre=p;
		p=next;
	}

	return pre;
}


//recursive version
Node* ReverseList2(Node* pHead) {
         
         
    if(pHead==NULL||pHead->next==NULL)return pHead;
         
         
    Node* head=ReverseList2(pHead->next);
    pHead->next->next=pHead;
    pHead->next=NULL;
    return head;
}



int main(int argc, char const *argv[])
{
	LinkList list;

	//setup a linklist with head node
	Node *head = list.SetupLinkList();
	cout<<"before reverse:"<<endl;
	list.display(head);

	//reverse the linklist
	Node*p = reverse(head->next);
	head->next=p;
	cout<<"after reverse:"<<endl;
	list.display(head);

	return 0;
}
