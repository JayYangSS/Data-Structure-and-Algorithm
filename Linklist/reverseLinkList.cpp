#include "LinkList.h"

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
