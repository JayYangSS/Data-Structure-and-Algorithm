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
	// ������ֵ���������������
	Node* SetupOrderedLinkList(bool down);
	// ��Ԫ�ز��뵽pp��ָ�ڵ��
	void Insert(Node* pp,Node *newNode);
	// ������������˳��ϲ�Ϊһ��������
	Node* Merge(Node* first, Node* second);
	// �������Ƶ���һ��������
	void copyto(Node* src, Node* dst);
	// �ϲ�������������ķ�����
	Node* Merge2(Node* first, Node* second);
	// Ѱ�ҵ�������м�ڵ�
	Node* FindMid(Node* head);
	// ʹ�ù鲢����ʵ����������
	Node* SortLinkList(Node* head);
};

