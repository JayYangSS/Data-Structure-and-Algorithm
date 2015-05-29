/**********************
推箱子游戏
说明：0代表空白格子，以4代表不能通过区域，以1代表玩家，以3代表箱子，以2代表目标点
输入：
首先输入行列数，再初始化仓库，再输入方向序列的个数（即方向序列的方向数T）
这T个字符仅由d，u，l，r这四个字母组成，分别代表了敲击向下，向上，向左，向右的方向键。
输出：
对于每个测试点，输出最后箱子是否在目标点上。如果是，输出YES，如果不是，则输出NO。
样例输入
输入仓库行列M N：5 4 
输入矩阵值：
00000
13000
00200
00000
输入方向序列个数：4
输入方向序列：rurd
输出：YES

**********************/
#include<iostream>
using namespace std;
#define WALL 4
#define PLAYER 1
#define BOX 3
#define GOAL 2
#define PLAIN 0

int M, N;
int **MAP;
pair<int, int>pos_player;
pair<int, int>pos_box;
bool RESULT = false;
class Map{
public:
	//建立地图
	void Setup();
	int* alloc_1d(int n);
	int** alloc_2d(int m, int n);
	void inputMat(int **matrix, int m, int n);
	void GetPosition(pair<int, int> &player, pair<int, int> &box,int m,int n);
};
void Map::GetPosition(pair<int, int> &player, pair<int, int> &box, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[i][j] == PLAYER)player=make_pair(i, j);
			else if (MAP[i][j] == BOX)box = make_pair(i, j);
		}
	}
}

int* Map::alloc_1d(int n)
{
	int *new1;
	new1 = new int[n];
	return new1;
}

int** Map::alloc_2d(int m, int n)
{
	int** new1;
	new1 = new int*[m];
	for (int i = 0; i < m; i++)
	{
		new1[i] = alloc_1d(n);
	}
	return new1;
}

void Map::inputMat(int **matrix, int m, int n){
	cout << "输入矩阵值：" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
void Map::Setup()
{
	cout << "输入仓库的行数列数M N：" << endl;
	cin >> M >> N;
	//申请二维数组
	MAP = alloc_2d(M, N);
	inputMat(MAP, M, N);
}



class Box{
	//箱子的位置
public:
	int x, y;
	Box(int pos_x,int pos_y);
	//判断箱子是否碰壁
	bool IsCollision(char direction);
	//判断箱子是否到达目标
	bool IsReach();
};
Box::Box(int pos_x, int pos_y) :x(pos_x), y(pos_y){}
bool Box::IsReach()
{
	if (MAP[x][y] == GOAL)return true;
	else return false;
}
bool Box::IsCollision(char direction)//判断是否可以沿给定方向移动
{
	switch (direction)
	{
	case 'r':
		if (y == N-1)return false;
		else if (MAP[x][y+1] == WALL)return false;
		else return true;
		break;
	case 'l':
		if (y == 0)return false;
		else if (MAP[x][y-1] == WALL)return false;
		else return true;
		break;
	case 'u':
		if (x == 0)return false;
		else if (MAP[x-1][y] == WALL)return false;
		else return true;
		break;
	case 'd':
		if (x == N-1)return false;
		else if (MAP[x+1][y] == WALL)return false;
		else return true;
		break;
	default:
		return false;
		break;
	}
}


class Player{
	//游戏者位置
public:
	int x, y;
	Player(int pos_x,int pos_y);
	//移动方法
	bool move(char direction,Box &box);
	//判断是否挨着箱子,返回值为箱子在player的哪一侧
	char AdjacentBox(Box box);
};
Player::Player(int pos_x, int pos_y) :x(pos_x), y(pos_y){}
char Player::AdjacentBox(Box box)
{
	//人和箱子在同一行
	if (x == box.x)
	{
		//返回箱子在人的哪边(左右)
		if (y == box.y + 1)return 'l';
		else if (y == box.y - 1)return 'r';
		else return 'N';
	}
	//人和箱子在同一列
	else if (y==box.y)
	{
		//返回箱子在人的哪边（上下）
		if (x == box.x + 1)return 'u';
		else if (x == box.x - 1)return 'd';
		else return 'N';
	}
	else return 'N';
}

bool Player::move(char direction, Box &box)
{
	switch (direction)
	{
	case 'r':
		//右边是边界
		if (y == N - 1)return false;
		//右边有箱子
		else if (AdjacentBox(box) == 'r')
		{
			//箱子向右可以移动
			if (box.IsCollision('r')){
				MAP[box.x][box.y] = PLAIN;//箱子移动走后修改为空地
				box.y = box.y + 1;//箱子右移
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//将移动到的位置修改为箱子占用

				MAP[x][y] = PLAIN;//人移动走后修改为空地
				y++;//人右移
				MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
				return true;
			}
			//箱子向右不能移动
			else return false;
		}
		//右边有墙
		else if (MAP[x][y+1] == WALL)return false;
		//没有箱子挨着，没有阻碍的情况
		else
		{
			MAP[x][y] = PLAIN;//人移动走后修改为空地
			y++;
			MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
			return true;
		}
		break;


	case 'l':
		//左边是边界
		if (y == 0)return false;
		//左边有箱子
		else if (AdjacentBox(box) == 'l')
		{
			//箱子向左可以移动
			if (box.IsCollision('l')){
				MAP[box.x][box.y] = PLAIN;//箱子移动走后修改为空地
				box.y = box.y - 1;//箱子右移
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//将移动到的位置修改为箱子占用

				MAP[x][y] = PLAIN;//人移动走后修改为空地
				y--;//人左移
				MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
				return true;
			}
			//箱子向左不能移动
			else return false;
		}
		//左边有墙
		else if (MAP[x][y-1] == WALL)return false;
		//没有箱子挨着，没有阻碍的情况
		else
		{
			MAP[x][y] = PLAIN;//人移动走后修改为空地
			y--;
			MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
			return true;
		}
		break;


	case 'u':
		//上边是边界
		if (x == 0)return false;
		//上边有箱子
		else if (AdjacentBox(box) == 'u')
		{
			//箱子向上可以移动
			if (box.IsCollision('u')){
				MAP[box.x][box.y] = PLAIN;//箱子移动走后修改为空地
				box.x = box.x - 1;//箱子上移
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//将移动到的位置修改为箱子占用

				MAP[x][y] = PLAIN;//人移动走后修改为空地
				x--;//人上移
				MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
				return true;
			}
			//箱子向上不能移动
			else return false;
		}
		//上边有墙
		else if (MAP[x-1][y] == WALL)return false;
		//没有箱子挨着，没有阻碍的情况
		else
		{
			MAP[x][y] = PLAIN;//人移动走后修改为空地
			x--;
			MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
			return true;
		}
		break;


	case 'd':
		//下边是边界
		if (x == M-1)return false;
		//下边有箱子
		else if (AdjacentBox(box) == 'd')
		{
			//箱子向下可以移动
			if (box.IsCollision('d')){
				MAP[box.x][box.y] = PLAIN;//箱子移动走后修改为空地
				box.x = box.x + 1;//箱子下移
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//将移动到的位置修改为箱子占用

				MAP[x][y] = PLAIN;//人移动走后修改为空地
				x++;//人下移
				MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
				return true;
			}
			//箱子向下不能移动
			else return false;
		}
		//下边有墙
		else if (MAP[x+1][y] == WALL)return false;
		//没有箱子挨着，没有阻碍的情况
		else
		{
			MAP[x][y] = PLAIN;//人移动走后修改为空地
			x++;
			MAP[x][y] = PLAYER;//将移动到的位置修改为人占用
			return true;
		}
		break;

	default:
		return false;
		break;
	}
}


int main()
{
	Map map;
	int numDir;
	//创建仓库地图
	map.Setup();
	//得到人和箱子的位置
	map.GetPosition(pos_player, pos_box, M, N);
	//输入行走命令
	Player player(pos_player.first,pos_player.second);
	Box box(pos_box.first, pos_box.second);
	cout << "输入方向序列的个数：" << endl;
	cin >> numDir;
	char *dir = (char*)malloc(numDir * sizeof(char));
	cout << "输入方向序列：" << endl;
	cin >> dir;
	for (int i = 0; i < numDir; i++)
	{
		if (player.move(dir[i], box))continue;
		else break;
	}
	if (RESULT)cout << "Yes" << endl;
	else cout << "No" << endl;
}