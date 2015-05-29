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



// //diaplay the data of link list
void LinkList::diaplay(Node* head)
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


// ������ֵ���������������
Node* LinkList::SetupOrderedLinkList(bool down)
//down=trueʱΪ�������У�down=falseʱΪ��������
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
			//������һ��Ԫ��
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
					
					if (down==false)//��������
					{
						//�Ƚϴ���������������뵱ǰ�����е�Ԫ�ش�С
						//��������Ԫ�ش��ڵ�ǰ�ڵ㣬�Ƚ���һ�ڵ�


						//��������Ԫ��С�ڵ�ǰ�ڵ㣬���뵽�ýڵ�֮ǰ
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

					else//��������
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


// ��Ԫ�ز��뵽pp��ָ�ڵ��
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


// ������������˳��ϲ�Ϊһ��������
Node* LinkList::Merge(Node* first, Node* second)
{
	if(first->next==NULL)
		return second;
	else if (second->next==NULL)
		return first;
	else{
		
		Node *d,*head;//�洢�ϲ��õ��µ�����
		Node *p1,*p2,*pre;

		head=new Node;
		copyto(first,head);//�µ�����ͷ
		
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


// �������Ƶ���һ��������
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


// �ϲ�������������ķ�����,����Ӱ��ԭ���������ϲ��õ�����洢���µ�λ��
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


// Ѱ�ҵ�������м�ڵ�
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
		fast=fast->next->next;//�α�slow�ƶ�һ����fast�ƶ���������fast�ƶ���ĩβ����slow�����ƶ����е�
	}
	return slow;
}


// ʹ�ù鲢����ʵ����������
Node* LinkList::SortLinkList(Node* head)
{
	if (!head)return NULL;
	if (!head->next)return head;
	Node *mid,*next=NULL,*head2;
	mid=FindMid(head);
	if (mid->next != NULL)
	{
		next = mid->next;
		//Ϊ��벿���������ͷ
		head2 = new Node;
		head2->next = next;
		mid->next = NULL;
		return Merge2(SortLinkList(head), SortLinkList(head2)); //ʹ�õݹ����
	}
	else
		return head;
}