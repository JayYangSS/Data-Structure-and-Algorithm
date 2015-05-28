#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//���֮����һ�⣺����һ��ʱ��Σ��жϸ�ʱ������м���2��29��
//���룺��һ��Ϊһ������T����ʾ����������֮��ÿ�����ݰ������С�ÿһ�и�ʽΪ"month day, year"��
//��ʾһ�����ڡ�monthΪ{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"}�е�һ���ַ�����day��yearΪ��������
//���������ÿ���������һ�У�����"Case #X: Y"��XΪ������������1��ʼ��YΪ��
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
	//����ĩβ�·�
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
		cout<<"Case #"<<i+1<<": "<<num<<endl;//���������ʽ���ԣ����˺ð��졣��Case����ĸ��д����
	}
	//system("pause");
	return 0;
}
