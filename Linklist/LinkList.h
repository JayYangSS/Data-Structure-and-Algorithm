#pragma once
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct Node
{
	int data;
	Node *next;
}Node;

class LinkList
{
public:
	LinkList(void);
	~LinkList(void);
	Node* SetupLinkList(void);
	// //display the data of link list
	void display(Node* head);
	//input the value and setup the ordered linklist
	Node* SetupOrderedLinkList(bool down);

	//insert the node after the node pp
	void Insert(Node* pp,Node *newNode);
	// 将两个单链表按顺序合并为一个单链表
	Node* Merge(Node* first, Node* second);
	// copy one link list to another one
	void copyto(Node* src, Node* dst);
	// merge two ordered linklist(method 2)
	Node* Merge2(Node* first, Node* second);
	// find the middle of the linklist
	Node* FindMid(Node* head);
	// 使用归并排序法实现链表排序
	Node* SortLinkList(Node* head);
};

