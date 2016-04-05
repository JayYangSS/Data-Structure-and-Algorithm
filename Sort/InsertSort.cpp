#include <iostream>

using namespace std;

void insertSort(int a[],int len){
	for(int i=1;i<len;i++){
		
		if(a[i]<a[i-1]){
			//将a[i]插入到前i个数据中
			int tmp=a[i];
			int j=i-1;
			for(j=i-1;j>=0;j--){
				if(a[i]>a[j])break;
			}

			//将a[j]之后的元素后移
			for(int m=i-1;m>j;m--){
				a[m+1]=a[m];
			}
			//插入元素
			a[j+1]=tmp;
		}
	}
}


int main(){
	int a[7]={1,3,23,4,4,9,5};
	//int a[3]={1,1,1};
	int len=3;
	insertSort(a,len);

	for(int i=0;i<len;i++)
		cout<<a[i]<<endl;
}