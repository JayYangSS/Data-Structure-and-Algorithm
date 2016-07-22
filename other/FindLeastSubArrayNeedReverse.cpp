
//given a array, find the minimal subArray that need to be adjusted to make the 
//Array to be an ordered array
//for instance:given [0,1,2,43,0,2,87],the minimal sub array is [1,2,43,0,2]
#include <iostream>

using namespace std;


pair<int,int> findLeastSubArrayNeedReverse(int *arr,int len){

	int max=arr[0],min=arr[len-1];
	int index1=0,index2=len-1;
	for(int i=0;i<len;i++){
		if(arr[i]>=max)max=arr[i];
		else
			index1=i;
	}

	for(int i=len-1;i>=0;i--){
		if(arr[i]<=min)min=arr[i];
		else
			index2=i;
	}

	return make_pair(index2,index1);
}


int main(){
	//test
	int a[]={0,1,2,43,0,2,87};
	int b[]={2,1};
	pair<int,int>result1=findLeastSubArrayNeedReverse(a,7);
	cout<<result1.first<<" "<<result1.second<<endl;

	pair<int,int>result2=findLeastSubArrayNeedReverse(b,2);
	cout<<result2.first<<" "<<result2.second<<endl;
}