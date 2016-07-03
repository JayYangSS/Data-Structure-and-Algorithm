#include <iostream>
using namespace std;

/*模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，
匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配 
*/

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)return false;

	if (*pattern == '\0'&&*str == '\0')return true;

	if (*pattern == '\0'&&*str != '\0')return false;

	//下一个字符为‘*’
	if (*(pattern + 1) == '*'){
		if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
			return match(str + 1, pattern) || match(str, pattern + 2) || match(str + 1, pattern + 2);
		else
			return match(str, pattern + 2);
	}

	//下一个字符不为‘*’且当前字符匹配
	if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
		return match(str + 1, pattern + 1);
	//下一个字符不为'*'且当前字符未匹配
	return false;
}

int main(){

	string str = "a";
	string pattern = "";


	char *p1 = (char*)str.data();
	char *p2 = (char*)pattern.data();
	cout << match(p1,p2) << endl;
}