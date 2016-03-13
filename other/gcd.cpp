#include <iostream>
using namespace std;


//find the greatest common divisor
int gcd(int a,int b){

	int big=a>b?a:b;
	int small=a>=b?b:a;
	if(big%small==0)return small;
	int result=gcd(small,big%small);
	return result;
}

//find the least common multiple
int lcm(int a,int b){
	int temp;
	temp=gcd(a,b);
	return a*b/temp;
}


int main(){
	int a=0,b=0;
	cin>>a;
	cin>>b;
	cout<<"the greatest common divisor is:"<<gcd(a,b)<<endl;
	cout<<"the least common multiple is:"<<lcm(a,b)<<endl;
}
