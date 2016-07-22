/*
given a array, each element represent the height, 
get the max volume that the container can contain the warter 
*/

#include <iostream>

using namespace std;


int getWaterVolume(int *arr,int len){
	int *left = new int[len-1]; 
	int *right= new int[len-1];


	if(len<=2)return 0;

	left[0]=0;
	for(int j=1;j<len;j++){
		if(arr[j-1]>left[j-1])left[j]=arr[j-1];
		else
			left[j]=left[j-1];
	}

	right[len-1]=0;
	for(int j=len-2;j>=0;j--){
		if(arr[j+1]>right[j+1])right[j]=arr[j+1];
		else
			right[j]=right[j+1];
	}

	int totalVolume=0;
	//get each volume
	for(int i=1;i<len-1;i++){
		int currentVolume=0;
		int smaller=right[i]<left[i]?right[i]:left[i];
		if(arr[i]>=smaller)currentVolume=0;
		else 
			currentVolume=smaller-arr[i];	
		totalVolume+=currentVolume;
	}

	delete []left;
	delete []right;
	return totalVolume;
}



int main(){
	int a[]={5,2,3};
	int b[]={2,5};
	int c[]={2,5,3,1,0,1,5,3};


	cout<<getWaterVolume(a,3)<<endl;//1
	cout<<getWaterVolume(b,2)<<endl;//0
	cout<<getWaterVolume(c,8)<<endl;//15
}