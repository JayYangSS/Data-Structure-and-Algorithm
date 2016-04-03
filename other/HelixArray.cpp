//This is the tecent intership test. Print the N-by-N dimensional array which are increased according row and columns
//eg.  input:4
//output: 
//1   2    3   4
//12 13 14 5
//11 16 15 6
//10  9   8  7

#include <iostream>
using namespace std;


void display(int **p,int N){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
}

//allocate the 2D array
int** new2DArray(int N){

	int **p = new int*[N];
	for (int i = 0; i < N; i++){
		p[i] = new int[N];
		for (int j = 0; j < N; j++)
			p[i][j] = 0;
	}
		
	return p;
}

int main(){

	int N;
	int i = 0, j = 0;
	cin >> N;
	int total = N*N;
	int count = 0;//统计当前元素数目
	int **p=new2DArray(N);

	//horz positive
	while (count<total){
		while (j < N&&p[i][j] == 0){
			count++;
			p[i][j] = count ;
			j++;
		}
		j--;
		i++;

		//down increase
		while (i < N&&p[i][j] == 0){
			count++;
			p[i][j] = count;
			i++;
		}
		i--;
		j--;

		//horz decrease
		while (j >= 0&&p[i][j] == 0){
			count++;
			p[i][j] = count;
			j--;
		}
		j++;
		i--;

		//vertical decrease
		while (i>=0&&p[i][j]==0)
		{
			count++;
			p[i][j] = count ;
			i--;
		}
		i++;
		j++;
	}
	display(p, N);
	//system("pause");
}
