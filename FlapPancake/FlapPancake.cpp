#include <stdio.h>
#include <stdlib.h>

class CakeSort
{
private:
	int* m_CakeArray;		//初始烙饼数组
	int m_CakeCount;		//烙饼数量
	int m_MaxSwap;			//交换上界
	int m_SwapTimes;		//已交换的次数
	int* m_SwapArray;		//交换信息
	int* m_ReverseCake;		//执行交换后的烙饼数组
	int* m_SwapReverseCake;	//执行交换后的烙饼数组的交换信息
	int* m_SortArray;        //排序完成的烙饼数组结果

public:
	void Init(int* pCakeArray,int count);
	void Run(int* pCakeArray,int count);
	int UpperBound(int count);
	int LowerBound(int* pArray,int count);
	void Search(int step,int flapIndex);
	bool IsSort(int* pArray,int count);
	void Reverse(int begin,int end);
	~CakeSort(void);
};
void CakeSort::Init(int* pCakeArray,int count)
{
	m_CakeCount = count;
	m_CakeArray = new int[count];
	for(int i = 0 ; i < count ; i++)
		m_CakeArray[i] = pCakeArray[i];
	m_ReverseCake = new int[count];
	for(int i = 0 ; i < count ; i++)
		m_ReverseCake[i] = m_CakeArray[i];
	m_MaxSwap = UpperBound(count);
	m_SwapTimes = 0;
	m_SwapArray = new int[m_MaxSwap];
	m_SwapReverseCake = new int[m_MaxSwap];
	m_SortArray=new int [m_CakeCount];
}
int CakeSort::UpperBound(int count)
{
	return 2*(count-2)+1;
}

//当前状态翻转到有序状态的步骤数目下界：若当前状态中，还有m对烙饼没有相邻，而每次翻转最多只能
//使得一个烙饼与大小跟它相邻的烙饼拍到一起，故至少还要m次才能排好
int CakeSort::LowerBound(int* pArray,int count)
{
	int ret = 0 ;
	int t;
	for(int i = 1 ; i < count ; i++)
	{
		t = pArray[i] - pArray[i-1];
		if((t != 1) && ( t!= -1))
			ret++;
	}
	return ret;
}
void CakeSort::Run(int* pArray,int count)
{
	Init(pArray,count);

	Search(0,0);

	//打印最优排序方式
	printf("最优翻转方式：\n");
	for (int i = 0; i < m_MaxSwap; i++)  
		printf("%d\n", m_SwapArray[i]);  

	printf("Search Times : %d\n", m_SwapTimes);  
	printf("Total Swap times = %d\n", m_MaxSwap);  

	//打印排序结果
	for (int i=0;i<m_CakeCount;i++)
	{
		printf("cake:%d\n",m_SortArray[i]);
	}
	

}
void CakeSort::Reverse(int begin , int end)
{
	int i,j,temp;
	for(i = begin , j = end ; i < j ; i++ , j--)
	{
		temp = m_ReverseCake[i];
		m_ReverseCake[i] = m_ReverseCake[j];
		m_ReverseCake[j] = temp;
	}
}

//排列好后，返回真值
bool CakeSort::IsSort(int* pArray,int count)
{
	for(int i = 1 ; i < count ; ++i)
	{
		if(pArray[i] < pArray[i-1])
			return false;
	}
	return true;
}
void CakeSort::Search(int step,int flapIndex)
{
	m_SwapTimes++;
	int Est = LowerBound(m_ReverseCake,m_CakeCount);
	if(Est + step >= m_MaxSwap)
		return;
	if(IsSort(m_ReverseCake,m_CakeCount))
	{
		if(step <= m_MaxSwap)
		{
			m_MaxSwap = step;
			//打印翻转方式
			for(int i = 0 ; i < m_MaxSwap ; i ++)
			{
				m_SwapArray[i] = m_SwapReverseCake[i];
				printf("%d\n",m_SwapArray[i]);
			}
			//打印该翻转方式下的排序结果
			for (int i=0;i<m_CakeCount;i++)
			{
				//想要保存正确的翻转结果，需要另建数组保存，不然m_ReverseCake还会在其他函数中修改，最后m_ReverseCake中不会保留正确的翻转结果
				m_SortArray[i]=m_ReverseCake[i];
				printf("cake:%d\n",m_ReverseCake[i]);
			}
	
		}
		return;
	}
	//没有排列好的情况
	for(int i = 1 ; i < m_CakeCount ; i++)
	{
		if(flapIndex==i)continue;
		Reverse(0,i);
		//记录本次操作的下标
		m_SwapReverseCake[step] = i;
		Search(step+1,i);
		//若第step+1步的翻转失败，回复到第step步的翻转结果
		Reverse(0,i);
	}
}
int main()
{
	int a[] = {3, 2, 1, 6, 5, 4, 9, 8, 7, 0};  
	CakeSort s;
	s.Run(a,10);
	system("pause");
	return 0;  
}

CakeSort::~CakeSort(void)
{
	if(m_CakeArray!=NULL)delete []m_CakeArray;
	if(m_SwapReverseCake!=NULL)delete []m_SwapReverseCake;
	if(m_SwapArray!=NULL)delete []m_SwapArray;
	if(m_ReverseCake!=NULL)delete []m_ReverseCake;
	if(m_SortArray!=NULL)delete []m_SortArray;
}

/*
#include <stdio.h>
#include <stdlib.h>

class CakeSort
{
private:
	int* m_CakeArray;		//初始烙饼数组
	int m_CakeCount;		//烙饼数量
	int m_MaxSwap;			//交换上界
	int m_SwapTimes;		//已交换的次数
	int* m_SwapArray;		//交换信息
	int* m_ReverseCake;		//执行交换后的烙饼数组
	int* m_SwapReverseCake;	//执行交换后的烙饼数组的交换信息
	int* m_SortArray;        //排序完成的烙饼数组结果

public:
	void Init(int* pCakeArray,int count);
	void Run(int* pCakeArray,int count);
	int UpperBound(int count);
	int LowerBound(int* pArray,int count);
	void Search(int step);
	bool IsSort(int* pArray,int count);
	void Reverse(int begin,int end);
	~CakeSort(void);
};
void CakeSort::Init(int* pCakeArray,int count)
{
	m_CakeCount = count;
	m_CakeArray = new int[count];
	for(int i = 0 ; i < count ; i++)
		m_CakeArray[i] = pCakeArray[i];
	m_ReverseCake = new int[count];
	for(int i = 0 ; i < count ; i++)
		m_ReverseCake[i] = m_CakeArray[i];
	m_MaxSwap = UpperBound(count);
	m_SwapTimes = 0;
	m_SwapArray = new int[m_MaxSwap];
	m_SwapReverseCake = new int[m_MaxSwap];
	m_SortArray=new int [m_CakeCount];
}
int CakeSort::UpperBound(int count)
{
	return 2*(count - 1);
}

//当前状态翻转到有序状态的步骤数目下界：若当前状态中，还有m对烙饼没有相邻，而每次翻转最多只能
//使得一个烙饼与大小跟它相邻的烙饼拍到一起，故至少还要m次才能排好
int CakeSort::LowerBound(int* pArray,int count)
{
	int ret = 0 ;
	int t;
	for(int i = 1 ; i < count ; i++)
	{
		t = pArray[i] - pArray[i-1];
		if((t != 1) && ( t!= -1))
			ret++;
	}
	return ret;
}
void CakeSort::Run(int* pArray,int count)
{
	Init(pArray,count);

	Search(0);

	//打印最优排序方式
	printf("最优翻转方式：\n");
	for (int i = 0; i < m_MaxSwap; i++)  
		printf("%d\n", m_SwapArray[i]);  

	printf("Search Times : %d\n", m_SwapTimes);  
	printf("Total Swap times = %d\n", m_MaxSwap);  

	//打印排序结果
	for (int i=0;i<m_CakeCount;i++)
	{
		printf("cake:%d\n",m_SortArray[i]);
	}


}
void CakeSort::Reverse(int begin , int end)
{
	int i,j,temp;
	for(i = begin , j = end ; i < j ; i++ , j--)
	{
		temp = m_ReverseCake[i];
		m_ReverseCake[i] = m_ReverseCake[j];
		m_ReverseCake[j] = temp;
	}
}

//排列好后，返回真值
bool CakeSort::IsSort(int* pArray,int count)
{
	for(int i = 1 ; i < count ; ++i)
	{
		if(pArray[i] < pArray[i-1])
			return false;
	}
	return true;
}
void CakeSort::Search(int step)
{
	m_SwapTimes++;
	int Est = LowerBound(m_ReverseCake,m_CakeCount);
	if(Est + step >= m_MaxSwap)
		return;
	if(IsSort(m_ReverseCake,m_CakeCount))
	{
		if(step <= m_MaxSwap)
		{
			m_MaxSwap = step;
			//打印翻转方式
			for(int i = 0 ; i < m_MaxSwap ; i ++)
			{
				m_SwapArray[i] = m_SwapReverseCake[i];
				printf("%d\n",m_SwapArray[i]);
			}
			//打印该翻转方式下的排序结果
			for (int i=0;i<m_CakeCount;i++)
			{
				//想要保存正确的翻转结果，需要另建数组保存，不然m_ReverseCake还会在其他函数中修改，最后m_ReverseCake中不会保留正确的翻转结果
				m_SortArray[i]=m_ReverseCake[i];
				printf("cake:%d\n",m_ReverseCake[i]);
			}

		}
		return;
	}
	//没有排列好的情况
	for(int i = 1 ; i < m_CakeCount ; i++)
	{
		Reverse(0,i);
		//记录本次操作的下标
		m_SwapReverseCake[step] = i;
		Search(step+1);
		//若第step+1步的翻转失败，回复到第step步的翻转结果
		Reverse(0,i);
	}
}
int main()
{
	int a[] = {3, 2, 1, 6, 5, 4, 9, 8, 7, 0};  
	CakeSort s;
	s.Run(a,10);
	system("pause");
	return 0;  
}

CakeSort::~CakeSort(void)
{
	if(m_CakeArray!=NULL)delete []m_CakeArray;
	if(m_SwapReverseCake!=NULL)delete []m_SwapReverseCake;
	if(m_SwapArray!=NULL)delete []m_SwapArray;
	if(m_ReverseCake!=NULL)delete []m_ReverseCake;
	if(m_SortArray!=NULL)delete []m_SortArray;
}*/