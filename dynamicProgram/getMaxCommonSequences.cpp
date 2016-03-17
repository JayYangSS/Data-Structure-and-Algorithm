/**
*this program uses the DP(dynamic program) to solve the LCQ prolem
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int max(int a,int b){
	int result=a>b?a:b;
	return result;
}

//get the max common subString of two strings
int getMaxCommonSubStringLen(string &str1,string &str2,int len1,int len2){
	//table[i][j] represent that the common subString length between two strings which are ended with str1[i] and str2[j]
	std::vector<std::vector<int> > table(len1+1,std::vector<int>(len2+1));

	for(int i=0;i<len1+1;i++){
		for (int j = 0; j < len2+1; ++j)
		{
			if(i==0||j==0)table[i][j]=0;
			else if(str1[i]==str2[j])table[i][j]=table[i-1][j-1]+1;
			else//since the subString is continus
				table[i][j]=0;
		}
	}

	//find the maxmum in the table,and the value is the max common substring length
	int maxLen=0;
	for(int i=1;i<len1+1;i++){
		for(int j=1;j<len2+1;j++){
			if(maxLen<table[i][j])maxLen=table[i][j];
		}
	}
	return maxLen;
}



//get the max common sequences of two strings
int getMaxCommonSeqLen(string &str1,string &str2,int len1,int len2){

	//table[i][j] means the maxcommon sequences between two strings whose lenth are i and j
	std::vector<std::vector<int> > table(len1+1,std::vector<int>(len2+1));

	for (int i = 0; i < len1+1; ++i)
	{
		for (int j = 0; j < len2+1; ++j)
		{
			if (i==0||j==0)table[i][j]=0;
			else if(str1[i]==str2[j])
				table[i][j]=table[i-1][j-1]+1;
			else
				table[i][j]=max(table[i][j-1],table[i-1][j]);
		}
	}


	return table[len1][len2];
}


int main(int argc, char const *argv[])
{
	string A="ABDEFYS";
	string B="DGYSMP";

	string C="ABDEFYS";
	string D="QDEFYP";

	cout<<"common sequences length:"<<getMaxCommonSeqLen(A,B,7,6)<<endl;
	cout<<"common subString length:"<<getMaxCommonSubStringLen(D,C,6,7)<<endl;
	return 0;
}