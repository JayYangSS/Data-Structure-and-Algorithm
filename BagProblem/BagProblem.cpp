#include<iostream>

#define max(a,b) ((a) > (b) ? a : b)
int c[5] = {3,5,2,7,4};
int v[5] = {2,4,1,6,5};
int f[6][10] = {0};
//f[i][v] = max{ f[i-1][v] , f[i-1][v - c[i]] + w[i]}

int main()
{
	for(int i = 1; i <= 5; i++)//��ʾ��i����Ʒ
		for(int j = 1; j <=10 ;j++)//j��ʾ�������
		{
			
			if(c[i] > j)//����������������Ų���c[i]����ѡc[i]
				f[i][j] = f[i-1][j];        
			else
			{
				f[i][j] = max(f[i-1][j], f[i-1][j - c[i]] + v[i]);//ת�Ʒ���ʽ
			}
		}
		//�������Ϊ10�ı�����5�������ѡ��װ������Ž�
		std::cout<<f[5][10]<<std::endl;
		system("pause");
		return 0;
}