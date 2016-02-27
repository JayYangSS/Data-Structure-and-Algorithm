#include<iostream>

//recursive version
int binarySearch(int a[],int start,int end,int val)
{
	
	if(start>end)
		return -1;	
	//get the result
	if(val==a[(start+end)/2]){
		return (start+end)/2;
	} 
	else if(val>a[(start+end)/2]){
		start=(start+end)/2+1;
		return binarySearch(a,start,end,val);	
	}
	else{
		end=(start+end)/2-1;
		return binarySearch(a,start,end,val);		
	}
}


//iterative version
int binarySearch2(int a[],int start,int end,int val)
{
	while(start<=end){
		int mid=start+end;
		if(a[mid]==val)
			return mid;
		else if(a[mid]<val)
			start=mid+1;
		else
			end=mid-1;
	}
	return -1;
}


int main()
{
	int a[]={0,1,3,7,10,12};
	int val=22;
	int position=binarySearch2(a,0,5,val);
	std::cout<<"index:"<<position<<std::endl;
}
