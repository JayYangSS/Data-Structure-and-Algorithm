#include <iostream>

/*
*create the hash table to solve the problem of finding the first charater that are 
*not repeate in the string.The ASCII code of the charater is the key and the number
*it occurs in the string is the value.
*/


using namespace std;

char FirstNotRepeateChar(char* pString){
	if (pString==NULL)
		return '\0';
	char* p=pString; 
	int hash[256];
	//initialize
	for (int i = 0; i < 256; ++i)
		hash[i]=0;

	while(*p!='\0'){
		hash[*p]++;
		p++;
	}

	for(int i=0;i<256;i++){
		if(hash[i]==1){
			char result=(char)i;
			return result;
		}
	}

	return '\0';
}


int main(int argc, char const *argv[])
{
	char pString1[]="safdsddd";
	char *pString2="SSDAAA";
	char *pString3=NULL;
	char result1=FirstNotRepeateChar(pString1);
	char result2=FirstNotRepeateChar(pString2);
	char result3=FirstNotRepeateChar(pString3);

	if (result1!='\0')
		cout<<"first not repeate char:"<<result1<<endl;
	if (result2!='\0')
		cout<<"first not repeate char:"<<result2<<endl;
	if (result3!='\0')
		cout<<"first not repeate char:"<<result3<<endl;
	return 0;
}