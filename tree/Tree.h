#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

struct Node{
	int val;
	Node* lchild;
	Node* rchild;
	Node(int x):val(x),lchild(NULL),rchild(NULL){}
};

class Tree
{
private:
	Node* head;
	char *p_str;//the pointer used in Deserialize method

public:
	Tree();
	//~Tree();
	Node* create(Node* head);
	int getDepth(Node* head);
	//DFS(depth first search)
	void preOrder(Node* const head);
	void inOrder(Node* const head);
	void postOrder(Node* const head);
	//BFS(broad first search)
	void BFS(Node* head);
	Node* reConstructBinaryTree(vector<int> pre,vector<int> in);
	Node* Deserialize(char *str);
};