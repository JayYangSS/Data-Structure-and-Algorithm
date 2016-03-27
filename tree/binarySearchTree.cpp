#include "Tree.h"

class BinarySearchTree{
public:
	bool search(Node* root,int val);
	Node* getKthNode(Node *root,int *k);
};


bool BinarySearchTree::search(Node* root,int val){
	bool result=false;
	if(root==NULL)return false;
	if(root->val==val)return true;
	
	else if(val<root->val){
		if(search(root->lchild,val))
			return true;
	}
	else
		return search(root->rchild,val);
}


Node* BinarySearchTree::getKthNode(Node *root,int *k){
	if(root==NULL||*k==0)return NULL;

	Node *result=NULL;
	if(root->lchild!=NULL)
		result=getKthNode(root->lchild,k);
	if(result==NULL){
		(*k)--;
		if(*k==0)result=root;
	}
	if(*k!=0&&root->rchild!=NULL)
		result=getKthNode(root->rchild,k);

	return result;
}

int main(){
	Tree t;
	Node *root;
	root=t.create(root);
	BinarySearchTree binarySearchTree;
	

	bool result=binarySearchTree.search(root,2);

	if(result)
		cout<<"find"<<endl;

	cout<<"find the Kth node in the binarySearchTree:"<<endl;
	int k=1;
	Node *node=binarySearchTree.getKthNode(root,&k);
	cout<<node->val<<endl;
}

