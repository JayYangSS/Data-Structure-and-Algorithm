#include <iostream>

using namespace std;

//maxHeap
class HeapSort
{
public:
	void maxHeapFix(int a[],int val);
	void insertMaxHeap(int a[],int n,int val);
	void deleteMaxHeap(int a[],int n);
	void sort(int a[],int n);
	void setupMaxHeap(int a[],int n);
	void sink(int a[],int index,int len);

};

//maxHeap
void HeapSort::maxHeapFix(int a[],int index){
	int parentIndex=(index-1)/2;
	while(index>0&&a[parentIndex]<a[index]){
		//swap
		int tmp=a[parentIndex];
		a[parentIndex]=a[index];
		a[index]=tmp;

		index=parentIndex;
		parentIndex=(index-1)/2;
	}
}


//insert an element
void HeapSort::insertMaxHeap(int a[],int n,int val){
	a[n]=val;
	maxHeapFix(a,n);
}

//n is the number of elements in array
void HeapSort::deleteMaxHeap(int a[],int n){
	if(n==1)return;
	a[0]=a[n-1];
	sink(a,0,n);
}


void HeapSort::setupMaxHeap(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		sink(a,i,n);
}


//将堆的第一个元素（最大值）放置在数组末尾，会得到递增数组
void HeapSort::sort(int a[],int n){
	//setup the max heap
	setupMaxHeap(a,n);

	for(int i=n-1;i>=0;i--){
		//swap a[0] and a[i]
		int tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;

		//sink
		sink(a,0,i);
	}

}


//n is the length of the array
void HeapSort::sink(int a[],int i,int n){
	if(n==1)return;

	//int tempVal=a[i];
	//a[i]=a[n-1];
	int childIndex=2*i+1;
	int index=i;
	while(childIndex<n){
		
		//find the max child
		if(a[childIndex]<a[childIndex+1]&&childIndex+1<n)
			childIndex++;

		if(a[index]>=a[childIndex])break;
		//swap
		int tmp=a[childIndex];
		a[childIndex]=a[index];
		a[index]=tmp;

		index=childIndex;
		childIndex=index*2+1;

	}

}





void display(int a[],int size){
	for(int i=0;i<size;i++)
		cout<<a[i]<<endl;
}

int main(){
	int a[3]={1,2,3};
	HeapSort h;

	cout<<"setupMaxHeap methood1:"<<endl;
	for(int i=0;i<3;i++)
		h.maxHeapFix(a,i);

	//display
	display(a,3);

	int c[5]={1,3,2,7,6};
	cout<<"setupMaxHeap:"<<endl;
	h.setupMaxHeap(c,5);
	display(c,5);


	// h.deleteMaxHeap(a,3);
	// display(a,3);


	int b[5]={1,3,2,7,6};
	cout<<"heap sort:"<<endl;
	h.sort(b,5);
	display(b,5);


}