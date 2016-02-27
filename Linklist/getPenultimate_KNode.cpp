#include<stdio.h>
#include<iostream>

using namespace std;

struct Node 
{
	int val;
	Node* next;
};


//获取链表倒数第K个节点
Node* getPenulmate_KNode(Node* const p,int k)
{
	if(p==NULL||k<=0){
		cout<<"Invalid input."<<endl;
		return NULL;
	}
	Node *p1,*p2;
	p1=p2=p;
	int count=0;
	while(p1->next!=NULL)
	{
		p1=p1->next;
		count++;
		if(count>=k)
		{
			p2=p2->next;
		}
	}
	if(count<k){
		cout<<"the length of link list is not longer than Penulmate number."<<endl;
		return NULL;
	}
		
	}
	return p2;
}




class LinkList{
private:
	Node* head;
public:
	LinkList();
	void create();
	void show();
	Node* getHead();
};

LinkList::LinkList(){
	head=new Node;
	head->next=NULL;
}

void LinkList::create(){
	int temp;
	cin>>temp;
	Node* p=head;

	while(temp!=-1){
		Node *newNode=new Node;
		newNode->val=temp;
		newNode->next=NULL;

		//connect to link list
		p->next=newNode;
		p=p->next;
		//otherwise, it will in a infinite loop
		cin>>temp;
	}
}

void LinkList::show(){
	Node* p=head->next;
	cout<<"show the LinkList:"<<endl;
	while(p!=NULL){
		cout<<p->val<<endl;
		p=p->next;
	}
}


Node* LinkList::getHead(){
	return head;
}


int main(int argc, char const *argv[])
{
	//LinkList link=LinkList();
	int number=0;
	LinkList link;
	link.create();
	link.show();
 	
 	cout<<"input the Penulmate number:"<<endl;
 	cin>>number;

	Node* firstNode=link.getHead()->next;
	Node* n=getPenulmate_KNode(firstNode,number);
	cout<<"result:"<<n->val<<endl;

	return 0;
}

/*
int main()
{
	//create link list
	Node node0;
	Node* node=&node0;
	node0.val=0;
	/*for(int i=1;i<5;i++)
	{
		Node nodei;
		nodei.val=i;
		node->next=&nodei;
		node=node->next;
	}*/

/*	Node node1;
	node1.val=1;
	node->next=&node1;
	node=node->next;

	Node node2;
	node2.val=2;
	node->next=&node2;
	node=node->next;

	node->next=NULL;

//	Node* Penulmate_K=getPenulmate_KNode(node,2);
//	printf("%i\n",Penulmate_K->val);

	printf("link list:\n");

	Node* cur=&node0;
	while(cur!=NULL){
		printf("%i\n",cur->val);
		cur=cur->next;
	}

}*/