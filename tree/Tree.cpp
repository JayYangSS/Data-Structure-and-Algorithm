#include"Tree.h"
#include<queue>


//judge is the two trees has the same root node and the same part
bool hasTree(Node* p1,Node* p2){
	if (p2==NULL)return true;
	if(p1==NULL)return false;

	if(p1->val!=p2->val)return false;

	bool result=false;
	result=hasTree(p1->lchild,p2->lchild)&&hasTree(p1->rchild,p2->rchild);
	return result;
}


//judge if the two trees has the same part
bool isHaveSubTree(Node* p1,Node* p2){
	if(p2==NULL)return true;
	if(p1==NULL)return false;
	bool result=false;
	result=hasTree(p1,p2);
	if(!result)
		result=isHaveSubTree(p1->lchild,p2->lchild);
	if(!result)
		result=isHaveSubTree(p1->rchild,p2->rchild);
	return result;
}

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

	//test the function isHaveSubTree
	Tree t2;
	Node *node2;
	node2=t2.create(node2);
	if(isHaveSubTree(node,node2))
		cout<<"the two trees have same part"<<endl;
	else
		cout<<"the two trees don't have same part"<<endl;
	return 0;
}
