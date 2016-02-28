#include<iostream>
using namespace std;

struct Node{
	int val;
	Node* lchild;
	Node* rchild;
};

class Tree
{
private:
	Node* head;
public:
	//Tree();
	//~Tree();
	Node* create(Node* head);
	int getDepth(Node* head);
	//DFS(depth first search)
	void preOrder(Node* const head);
	void inOrder(Node* const head);
	void postOrder(Node* const head);
	//BFS(broad first search)
	void BFS(Node* head);
};