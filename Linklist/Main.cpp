#include "LinkList.h"
int main()
{
	
	/*Solution tmp;
	uint32_t num=1;
	uint32_t si=2147483648;
	uint32_t result;
	int Count=0;
	Count=tmp.hammingWeight(num);
	cout<<Count<<endl;
	
	result=tmp.reverseBits(si);
	cout<<result<<endl;*/


	//Test the function of SetupOrderedLinkList()
	/*LinkList list;
	Node *p1=list.SetupOrderedLinkList(false);//up order
	list.display(p1);

	Node *p2=list.SetupOrderedLinkList(false);
	list.display(p2);

	Node *merge=list.Merge2(p1,p2);

	cout<<"�ϲ��������"<<endl;
	list.display(merge);

	Node* mid=new Node;
	mid=list.FindMid(merge);
	cout<<"�ϲ��������е�Ϊ��"<<mid->data<<endl;*/

	//Test the function of copyto()
	/*LinkList list;
	Node *p1=list.SetupOrderedLinkList(false);//up order
	list.display(p1);

	Node *p2=new Node;
	list.copyto(p1,p2);
	list.display(p2);*/

	/*extern int a,b;//���ù����������ļ���������ȫ�ֱ������ⲿ����������������չ�����ļ���
	cout<<max(a,b)<<endl;*/

	/*LinkList list;
	Node* p=list.SetupLinkList();
	list.display(p);
	Node* q=list.SortLinkList(p);
	list.display(q);
	system("pause");*/



	//test the SortLinkList()
	LinkList list;
	Node *p = list.SetupLinkList();
	list.display(p);
	Node *new_p=list.SortLinkList(p);
	cout << "ʹ�ù鲢���򷨵õ���������Ϊ��" << endl;
	list.display(new_p);
	
	system("pause");
}

//int a=15,b=-7;
int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	return z;
}