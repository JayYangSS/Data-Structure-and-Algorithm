#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//编程之美第一题：给定一个时间段，判断该时间段内有几个2月29号
//输入：第一行为一个整数T，表示数据组数，之后每组数据包含两行。每一行格式为"month day, year"，
//表示一个日期。month为{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"}中的一个字符串。day与year为两个数字
//输出：对于每组数据输出一行，形如"Case #X: Y"。X为数据组数，从1开始，Y为答案
////////////////////////////////////////////////////////////////////////////////////


bool IsYear(long int year)
{
	//bool flag=false;
	if((year%4==0)&&(year%100!=0))return true;
	else if(!(year%400))return true;
	else return false;

}

int CalcYear(string month_start,int day_start,long int year_start,string month_end,int day_end,long int year_end)
{
	long int num=0;

	if(month_start!="January"&&month_start!="February")
	{
		year_start++;
	}
	//处理末尾月份
	if ((month_end=="February"&&day_end<29)||month_end=="January")
	{
		year_end--;
	}

	for (long int i=year_start;i<=year_end;i++)
	{
		if(IsYear(i))num++;
	}
	return num;
}




int main()
{
	int T;//the number of test
	cin>>T;
	string month_start[550],month_end[550];
	int day_start[550],day_end[550];
	int year_start[550];
	long int year_end[550]; 
	char comma;
	//input the start time and end time
	for (int i=0;i<T;i++)
	{
		cin>>month_start[i]>>day_start[i]>>comma>>year_start[i];
		cin>>month_end[i]>>day_end[i]>>comma>>year_end[i];
	}

	//judge the year
	for (int i=0;i<T;i++)
	{
		long int num=CalcYear(month_start[i],day_start[i],year_start[i],month_end[i],day_end[i],year_end[i]);
		cout<<"Case #"<<i+1<<": "<<num<<endl;//就是输出格式不对，搞了好半天。。Case首字母大写。。
	}
	//system("pause");
	return 0;
}
