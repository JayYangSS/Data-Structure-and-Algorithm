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
	// //diaplay the data of link list
	void diaplay(Node* head);
	// 输入数值，建立有序的链表
	Node* SetupOrderedLinkList(bool down);
	// 将元素插入到pp所指节点后
	void Insert(Node* pp,Node *newNode);
	// 将两个单链表按顺序合并为一个单链表
	Node* Merge(Node* first, Node* second);
	// 将链表复制到另一条链表上
	void copyto(Node* src, Node* dst);
	// 合并两条有序链表的方法二
	Node* Merge2(Node* first, Node* second);
	// 寻找单链表的中间节点
	Node* FindMid(Node* head);
	// 使用归并排序法实现链表排序
	Node* SortLinkList(Node* head);
};

