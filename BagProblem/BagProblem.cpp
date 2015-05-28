#include<iostream>

#define max(a,b) ((a) > (b) ? a : b)
int c[5] = {3,5,2,7,4};
int v[5] = {2,4,1,6,5};
int f[6][10] = {0};
//f[i][v] = max{ f[i-1][v] , f[i-1][v - c[i]] + w[i]}

int main()
{
	for(int i = 1; i <= 5; i++)//表示第i个物品
		for(int j = 1; j <=10 ;j++)//j表示背包体积
		{
			
			if(c[i] > j)//如果背包的容量，放不下c[i]，则不选c[i]
				f[i][j] = f[i-1][j];        
			else
			{
				f[i][j] = max(f[i-1][j], f[i-1][j - c[i]] + v[i]);//转移方程式
			}
		}
		//输出容量为10的背包，5个物体待选择装入的最优解
		std::cout<<f[5][10]<<std::endl;
		system("pause");
		return 0;
}