/**
*基数排序：先根据序列的个位数的数字来进行排序，将其分到指定的桶中，再将按照个位排好顺序
*的数字重新组合成一个数组，再对新的数组根据十位数大小排序，以此类推，直到最高位排序完成
*/

#include <iostream>
#include <vector>

using namespace std;

//获取制定第n位的数字
int getDigit(int val,int n){
	int div=1;
	if(n==0)div=1;
	else{
		for(int i=0;i<n;i++)
			div*=10;
	}
	return (val/div)%10;
}

int getNumBit(const int val){
	int tmp=val;
	int result=0;	
	while(tmp!=0){
		result++;
		tmp=tmp/10;
	}
	return result;
}


//获取数组中的元素的最高位数
int getMaxBit(int a[],int n){
	int max=a[0];	
	for(int i=0;i<n;i++){
		if(max<a[i])max=a[i];	
	}
	return getNumBit(max);
}


void baseSort(int a[],int len){

	int d=getMaxBit(a,len);
	vector<int> container[10];
	vector<int> result;

	for(int j=0;j<d;j++){
		for(int i=0;i<len;i++){
			int digit=getDigit(a[i],j);//获取第i位的数字
			container[digit].push_back(a[i]);	
		}
		//将按照第j位数字排序好的内容重新组合为数组
		int ct=0;
		for(int i=0;i<10;i++){
			for(int m=0;m<container[i].size();m++){
				a[ct]=container[i][m];
				ct++;
			}
			container[i].clear();		
		}
		
	}
}

void test(int a[]){
	int tmp=a[0];
	a[0]=a[2];
	a[2]=tmp;
}


int main(){
	int a[7]={123,5,123,15,4,24,1235};
	int len=7;
	baseSort(a,len);
	//test(a);	
	//show result
	for(int i=0;i<len;i++)
		cout<<a[i]<<endl;
}
