/***********************************************************************************
for details,please see my blog:http://blog.csdn.net/jiyangsb/article/details/44523319
**************************************************************************************/
#include "LinkList.h"

LinkList::LinkList(void)
{
}


LinkList::~LinkList(void)
{
}


Node* LinkList::SetupLinkList(void)
{
	
	Node *head,*p,*q;
	cout<<"input the data(input '-1' to end):"<<endl;
	head=new Node;
	head->next=	NULL;
	q=head->next;
	while (1)
	{
		int a;
		cout<<"input data:";
		cin>>a;
		
		if (a==-1)break;
		else{
			p=new Node;
			if (head->next==NULL)
			{
				head->next=p;
				p->data=a;
				p->next=NULL;
				q=p;
			}
			else
			{
				p->data=a;
				q->next=p;
				q=p;
				q->next=NULL;
			}
		}
		
	}
	return head;
}



// //display the data of link list
void LinkList::display(Node* head)
{
	Node *p;
	if (head == NULL)
		cout << "The head of the LinkList is NULL!" << endl;
	else if (head->next==NULL)
	{
		cout<<"Linklist is empty!"<<endl;
	}
    else{
		p=head->next;
		while(p!=NULL)
		{
			cout<<p->data<<endl;
			p=p->next;
		}
	}
}


// 输入数值，建立有序的链表
Node* LinkList::SetupOrderedLinkList(bool down)
//down=true时为降序排列，down=false时为升序排列
{
	Node *head,*p,*q;
	cout<<"input the data(input '-1' to end):"<<endl;
	head=new Node;
	head->next=	NULL;
	q=head->next;
	while (1)
	{
		int a;
		cout<<"input data:";
		cin>>a;

		if (a==-1)break;
		else{
			p=new Node;
			p->data=a;
			//创建第一个元素
			if (head->next==NULL)
			{
				head->next=p;
				p->next=NULL;
				q=p;
			}
			else
			{
				Node *search,*pre;
				search=head->next;
				pre=head;
				while(pre->next!=NULL)
				{
					
					if (down==false)//升序排列
					{
						//比较待插入链表的数据与当前链表中的元素大小
						//若待插入元素大于当前节点，比较下一节点


						//若待插入元素小于当前节点，插入到该节点之前
						if (a>=search->data)
						{
							if (search->next==NULL)Insert(search,p);
							pre=pre->next;
							search=search->next;

						}
						else
						{
							Insert(pre,p);
							break;
						}
					}

					else//降序排列
					{
						if (a<=search->data)
						{
							if (search->next==NULL)Insert(search,p);
							pre=pre->next;
							search=search->next;

						}
						else
						{
							Insert(pre,p);
							break;
						}
					}
				}
			}
		}

	}
	return head;
}


// 将元素插入到pp所指节点后
void LinkList::Insert(Node* pp,Node *newNode)
{
	if (pp->next==NULL)
	{
		pp->next=newNode;
		newNode->next=NULL;
	}
	else{
		Node *tmp=pp->next;
		pp->next=newNode;
		newNode->next=tmp;
	}
}


// 将两个单链表按顺序合并为一个单链表
Node* LinkList::Merge(Node* first, Node* second)
{
	if(first->next==NULL)
		return second;
	else if (second->next==NULL)
		return first;
	else{
		
		Node *d,*head;//存储合并好的新的链表
		Node *p1,*p2,*pre;

		head=new Node;
		copyto(first,head);//新的链表头
		
		//p1=head->next;
		//pre=head;
		p2=second->next;

		while(p2!=NULL)
		//while(((p2->next!=NULL)&&p2!=NULL)|((p2!=NULL)&&(p2->next==NULL)))
		{
			p1=head->next;
			pre=head;
			while(pre!=NULL)
			{

				if ((p2->data>=p1->data)&&(p1->next!=NULL))
				{
					p1=p1->next;
					pre=pre->next;
					if ((p1->next==NULL)&&(p2->data>=p1->data))
					{
						Insert(p1,p2);
						p1=p1->next;
						pre=pre->next;
						p2=p2->next;
						break;
					}
				}					
				
				else
				{
					d=new Node;
					d->data=p2->data;
					Insert(pre,d);
					if (p2->next==NULL){p2=p2->next;break;}
					p2=p2->next;
					pre=pre->next;


					break;
				}

			}
		}
		return head;
	}
}


// 将链表复制到另一条链表上
void LinkList::copyto(Node* src, Node* dst)
{
	Node *p,*q,*tmp;
	q=new Node;
	dst->next=q;
	p=src->next;

	do
	{
		
		q->data=p->data;
		p=p->next;
		if(p!=NULL){		
			tmp=new Node;
			q->next=tmp;
			q=q->next;
			q->next=NULL;
		}
	
	}while(p!=NULL);

}


// 合并两条有序链表的方法二,不会影响原来的链表，合并好的链表存储在新的位置
Node* LinkList::Merge2(Node* first, Node* second)
{
	Node *head,*tail;
	head=new Node;
	tail=head;
	first=first->next;
	second=second->next;
	if(first==NULL)
		return second;
	if(second==NULL)
		return first;
	while(first&&second)
	{
		if (first->data>second->data)
		{
			Node* tmp=new Node;
			tmp->data=second->data;
			tail->next=tmp;
			tail=tail->next;
			tail->next=NULL;
		//	delete tmp;
			second=second->next;
		}
		else
		{
			Node* tmp=new Node;
			tmp->data=first->data;
			tail->next=tmp;
			tail=tail->next;
			tail->next=NULL;
			//delete tmp;
			first=first->next;
		}
	}

	if(first==NULL)
	{
		while(second)
		{
			Node *tmp=new Node;
			tmp->data=second->data;
			tail->next=tmp;
			tail=tail->next;
			tail->next=NULL;
			second=second->next;
		}
		
	}
	
	else
	{
		while(first)
		{
			Node *tmp=new Node;
			tmp->data=first->data;
			tail->next=tmp;
			tail=tail->next;
			tail->next=NULL;
			first=first->next;
		}
	}
		
	return head;
}


// 寻找单链表的中间节点
Node* LinkList::FindMid(Node* head)
{
	if(!head)return NULL;
	if(!head->next)return head;
	Node *slow,*fast;
    slow=head;
	fast=head;
	while(fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;//游标slow移动一步，fast移动两步，当fast移动到末尾，则slow正好移动到中点
	}
	return slow;
}


// 使用归并排序法实现链表排序
Node* LinkList::SortLinkList(Node* head)
{
	if (!head)return NULL;
	if (!head->next)return head;
	Node *mid,*next=NULL,*head2;
	mid=FindMid(head);
	if (mid->next != NULL)
	{
		next = mid->next;
		//为后半部分添加链表头
		head2 = new Node;
		head2->next = next;
		mid->next = NULL;
		return Merge2(SortLinkList(head), SortLinkList(head2)); //使用递归调用
	}
	else
		return head;
}


// 使用归并排序法实现链表排序
void LinkList::QuickSort(Node* head,Node* tail){
	if(head==NULL||head->next==tail||head==tail)return;

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
	
}