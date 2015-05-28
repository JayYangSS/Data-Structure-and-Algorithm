#include <stdio.h>
#include <stdlib.h>

class CakeSort
{
private:
	int* m_CakeArray;		//��ʼ�ӱ�����
	int m_CakeCount;		//�ӱ�����
	int m_MaxSwap;			//�����Ͻ�
	int m_SwapTimes;		//�ѽ����Ĵ���
	int* m_SwapArray;		//������Ϣ
	int* m_ReverseCake;		//ִ�н�������ӱ�����
	int* m_SwapReverseCake;	//ִ�н�������ӱ�����Ľ�����Ϣ
	int* m_SortArray;        //������ɵ��ӱ�������

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

//��ǰ״̬��ת������״̬�Ĳ�����Ŀ�½磺����ǰ״̬�У�����m���ӱ�û�����ڣ���ÿ�η�ת���ֻ��
//ʹ��һ���ӱ����С�������ڵ��ӱ��ĵ�һ�𣬹����ٻ�Ҫm�β����ź�
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

	//��ӡ��������ʽ
	printf("���ŷ�ת��ʽ��\n");
	for (int i = 0; i < m_MaxSwap; i++)  
		printf("%d\n", m_SwapArray[i]);  

	printf("Search Times : %d\n", m_SwapTimes);  
	printf("Total Swap times = %d\n", m_MaxSwap);  

	//��ӡ������
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

//���кú󣬷�����ֵ
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
			//��ӡ��ת��ʽ
			for(int i = 0 ; i < m_MaxSwap ; i ++)
			{
				m_SwapArray[i] = m_SwapReverseCake[i];
				printf("%d\n",m_SwapArray[i]);
			}
			//��ӡ�÷�ת��ʽ�µ�������
			for (int i=0;i<m_CakeCount;i++)
			{
				//��Ҫ������ȷ�ķ�ת�������Ҫ�����鱣�棬��Ȼm_ReverseCake�����������������޸ģ����m_ReverseCake�в��ᱣ����ȷ�ķ�ת���
				m_SortArray[i]=m_ReverseCake[i];
				printf("cake:%d\n",m_ReverseCake[i]);
			}
	
		}
		return;
	}
	//û�����кõ����
	for(int i = 1 ; i < m_CakeCount ; i++)
	{
		if(flapIndex==i)continue;
		Reverse(0,i);
		//��¼���β������±�
		m_SwapReverseCake[step] = i;
		Search(step+1,i);
		//����step+1���ķ�תʧ�ܣ��ظ�����step���ķ�ת���
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
	int* m_CakeArray;		//��ʼ�ӱ�����
	int m_CakeCount;		//�ӱ�����
	int m_MaxSwap;			//�����Ͻ�
	int m_SwapTimes;		//�ѽ����Ĵ���
	int* m_SwapArray;		//������Ϣ
	int* m_ReverseCake;		//ִ�н�������ӱ�����
	int* m_SwapReverseCake;	//ִ�н�������ӱ�����Ľ�����Ϣ
	int* m_SortArray;        //������ɵ��ӱ�������

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

//��ǰ״̬��ת������״̬�Ĳ�����Ŀ�½磺����ǰ״̬�У�����m���ӱ�û�����ڣ���ÿ�η�ת���ֻ��
//ʹ��һ���ӱ����С�������ڵ��ӱ��ĵ�һ�𣬹����ٻ�Ҫm�β����ź�
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

	//��ӡ��������ʽ
	printf("���ŷ�ת��ʽ��\n");
	for (int i = 0; i < m_MaxSwap; i++)  
		printf("%d\n", m_SwapArray[i]);  

	printf("Search Times : %d\n", m_SwapTimes);  
	printf("Total Swap times = %d\n", m_MaxSwap);  

	//��ӡ������
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

//���кú󣬷�����ֵ
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
			//��ӡ��ת��ʽ
			for(int i = 0 ; i < m_MaxSwap ; i ++)
			{
				m_SwapArray[i] = m_SwapReverseCake[i];
				printf("%d\n",m_SwapArray[i]);
			}
			//��ӡ�÷�ת��ʽ�µ�������
			for (int i=0;i<m_CakeCount;i++)
			{
				//��Ҫ������ȷ�ķ�ת�������Ҫ�����鱣�棬��Ȼm_ReverseCake�����������������޸ģ����m_ReverseCake�в��ᱣ����ȷ�ķ�ת���
				m_SortArray[i]=m_ReverseCake[i];
				printf("cake:%d\n",m_ReverseCake[i]);
			}

		}
		return;
	}
	//û�����кõ����
	for(int i = 1 ; i < m_CakeCount ; i++)
	{
		Reverse(0,i);
		//��¼���β������±�
		m_SwapReverseCake[step] = i;
		Search(step+1);
		//����step+1���ķ�תʧ�ܣ��ظ�����step���ķ�ת���
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