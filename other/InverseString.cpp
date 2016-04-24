/*对于一个给定的字符串，我们需要在线性(也就是O(n))的时间里对它做一些变形。
首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把
着个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。比如"Hello World"
变形后就变成了"wORLD hELLO"。
*/

string trans(string s, int n) {
	// write code here
	if (n == 0)return "";
	string result = "";
	stack<char> charStack;

	int diff = 'a' - 'A';
	int i = n - 1;

	while (i >= 0){
		while (i >= 0&&s[i] != ' '){
			charStack.push(s[i]);
			i--;
		}


		if (i == -1 || s[i] == ' '){
			while (!charStack.empty()){
				char tmp = charStack.top();

				if (tmp >='a'&&tmp<='z')
					tmp =tmp-diff;
				else if (tmp>='A'&&tmp<='Z')
					tmp += diff;
				result += tmp;
				charStack.pop();
			}

			if (i>0){
				result += ' ';
				i--;
			}

		}
	}

	return result;
}