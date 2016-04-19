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

	cout<<"合并后的链表："<<endl;
	list.display(merge);

	Node* mid=new Node;
	mid=list.FindMid(merge);
	cout<<"合并后链表中点为："<<mid->data<<endl;*/

	//Test the function of copyto()
	/*LinkList list;
	Node *p1=list.SetupOrderedLinkList(false);//up order
	list.display(p1);

	Node *p2=new Node;
	list.copyto(p1,p2);
	list.display(p2);*/

	/*extern int a,b;//将该工程中其他文件中声明的全局变量（外部变量）的作用域扩展到该文件来
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
	cout << "SortLinkList:" << endl;
	list.display(new_p);


	cout<<"test quickSort:"<<endl;
	Node *q = list.SetupLinkList();
	list.QuickSort(q->next,NULL);
	list.display(q);
	
	//system("pause");
}

//int a=15,b=-7;
int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	return z;
}