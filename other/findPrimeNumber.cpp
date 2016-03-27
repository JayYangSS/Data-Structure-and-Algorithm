#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class FindPrimeNumber{
public:

	//最low的方法，全部遍历
	vector<int> solution1(int num){
		vector<int> v;
		if(num<=2)return v;
		for(int i=2;i<num;i++){

			int j=2;
			for ( j= 2; j < i; ++j)
			{
				if(i%j==0)break;
			}
			if(i==j)
				v.push_back(i);
		}

		return v;
	}

	//段位二：只需要找到n/2就可以判断一个数是否为质数了
	vector<int> solution2(int num){
		vector<int> v;
		for(int i=2;i<num;i++){

			int j=2; 
			//i>=4;
			for ( j= 2; j <=i/2; ++j)
			{
				if(i%j==0)break;
			}
			if(i/2<j)
				v.push_back(i);	
		}
		return v;
	}

	//段位三：质数除2之外都为奇数（计算量减半）
	vector<int> solution3(int num){
		vector<int> v;
		if(num>=3) 
			v.push_back(2);

		for(int i=3;i<num;i=i+2){

			int j=2; 
			//i>=4;
			for ( j= 2; j <=i/2; j++)
			{
				if(i%j==0)break;
			}
			if(i/2<j)
				v.push_back(i);	
		}
		return v;
	}



	//段位四：判断一个数是否为质数只需要到平方根就可以了
	vector<int> solution4(int num){
		vector<int> v;
		if(num>=3) 
			v.push_back(2);

		for(int i=3;i<num;i=i+2){

			float sq=sqrt(i);
			int j=2; 
			//i>=4;
			for ( j= 2; j<sq; j++)
			{
				if(i%j==0)break;
			}
			if(sq<j)
				v.push_back(i);	
		}
		return v;
	}


};


int main(){

	int val=24;
	vector<int> v;
	FindPrimeNumber f;

	v=f.solution4(val);
	
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
}