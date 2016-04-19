#include <iostream>

using namespace std;


struct Node
{
	int data;
	Node *next;
	Node(int val):data(val),next(NULL){};
};


Node* QuickSort(Node* head,Node* tail){
	if(head==NULL||head->next==tail||head==tail)return head;

	Node* p=head;
	Node* q=p->next;
	int key=head->data;

	while(q!=tail){
		if(q->data<key){
			p=p->next;
			//swap
			int tmp=p->data;
			p->data=q->data;
			q->data=tmp;
		}
		q=q->next;

	}

	//swap the partition point
	head->data=p->data;
	p->data=key;

	
	QuickSort(head,p);
		
	QuickSort(p->next,q);
	

	return head;
}


void display(Node* head){
	while(head!=NULL){
		cout<<head->data<<endl;
		head=head->next;
	}
}


int main(){
	Node *n1=new Node(2);
	Node *n2=new Node(1);
	Node *n3=new Node(7);
	Node *n4=new Node(3);
	Node *n5=new Node(1);

	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;

	Node* p=QuickSort(n1,NULL);

	display(p);
}