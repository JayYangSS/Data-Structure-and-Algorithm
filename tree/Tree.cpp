#include"Tree.h"
#include<queue>

Node* Tree::create(Node* head){
	
	int input;
	cin>>input;
	//if the input is -1,make the node null
	if(input==-1){
		head=NULL;
		return NULL;
	}
	head=new Node;
	head->val=input;
	cout<<"left child:"<<endl;
	head->lchild=create(head->lchild);
	cout<<"right child:"<<endl;
	head->rchild=create(head->rchild);
	return head;
}


void Tree::preOrder(Node* const head){
	if(head==NULL)return;
	cout<<head->val<<endl;

	if(head->lchild)
		preOrder(head->lchild);
	if(head->rchild)
		preOrder(head->rchild);
}


void Tree::inOrder(Node* const head){
	if(head==NULL)return;
	if (head->lchild)
		inOrder(head->lchild);
	cout<<head->val<<endl;
	if (head->rchild)
		inOrder(head->rchild);
}

void Tree::postOrder(Node* const head){
	if(head==NULL)return;
	if (head->lchild)
		postOrder(head->lchild);
	if (head->rchild)
		postOrder(head->rchild);
	cout<<head->val<<endl;
}

int Tree::getDepth(Node* head){
	if (head==NULL)return 0;
	int lDepth=getDepth(head->lchild);
	int rDepth=getDepth(head->rchild);
	int max=lDepth>rDepth?lDepth:rDepth;
	return max+1;
}


void Tree::BFS(Node* head){

}

int main(int argc, char const *argv[])
{
	Node *node;
	Tree t;
	node=t.create(node);

	//get the depth of the tree
	int depth=t.getDepth(node);
	cout<<"the depth of tree:"<<depth<<endl;

	//preOrder search
	cout<<"preOrder:"<<endl;
	t.preOrder(node);

	//inOrder search
	cout<<"inOrder:"<<endl;
	t.inOrder(node);

	//inOrder search
	cout<<"postOrder:"<<endl;
	t.postOrder(node);
	return 0;
}
