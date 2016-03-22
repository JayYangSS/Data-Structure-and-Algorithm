#include <iostream>

using namespace std;

// replace the space in the string.for example: "hello world" will be replaced as "hello%20world"

class Solution {
public:
	void replaceSpace(char *str,int length) {
		
        if(str==NULL||length==0)return;
        
        int numBlank=0;
        int originStrLen=0;
        int changeLength=0;
        char* p=str;
        
        while(*p!='\0'){
            originStrLen++;
            if(*p==' ')numBlank++;
            p++;
        }
        
        changeLength=originStrLen+2*numBlank;
        
        char *p1,*p2;
        
        p1=str+originStrLen-1;
        p2=str+changeLength-1;
        
        while(p1!=p2&&p1>=str&&p2>=str){
            if(*p1==' '){
                *p2--='0';
                //p2--;
                *p2--='2';
                //p2--;
                *p2='%';
            }else{
                (*p2)=(*p1);
            }
            p1--;
            p2--;
        }
        
        str[changeLength]='\0';
	}
};



int main(){
    Solution s;
    char *str;
    char strArray[]=" ";
    str=strArray;

    //attention: if write like this: char* str="hello world!";
    //the str points to the const string, and the content is not permitted to be changed and will occur the segment fault! 
    s.replaceSpace(str,100);
    while(*str!='\0'){
        cout<<(*(str++));
    }
    cout<<""<<endl;
}