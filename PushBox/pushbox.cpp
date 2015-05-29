/**********************
��������Ϸ
˵����0����հ׸��ӣ���4������ͨ��������1������ң���3�������ӣ���2����Ŀ���
���룺
�����������������ٳ�ʼ���ֿ⣬�����뷽�����еĸ��������������еķ�����T��
��T���ַ�����d��u��l��r���ĸ���ĸ��ɣ��ֱ�������û����£����ϣ��������ҵķ������
�����
����ÿ�����Ե㣬�����������Ƿ���Ŀ����ϡ�����ǣ����YES��������ǣ������NO��
��������
����ֿ�����M N��5 4 
�������ֵ��
00000
13000
00200
00000
���뷽�����и�����4
���뷽�����У�rurd
�����YES

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
	//������ͼ
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
	cout << "�������ֵ��" << endl;
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
	cout << "����ֿ����������M N��" << endl;
	cin >> M >> N;
	//�����ά����
	MAP = alloc_2d(M, N);
	inputMat(MAP, M, N);
}



class Box{
	//���ӵ�λ��
public:
	int x, y;
	Box(int pos_x,int pos_y);
	//�ж������Ƿ�����
	bool IsCollision(char direction);
	//�ж������Ƿ񵽴�Ŀ��
	bool IsReach();
};
Box::Box(int pos_x, int pos_y) :x(pos_x), y(pos_y){}
bool Box::IsReach()
{
	if (MAP[x][y] == GOAL)return true;
	else return false;
}
bool Box::IsCollision(char direction)//�ж��Ƿ�����ظ��������ƶ�
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
	//��Ϸ��λ��
public:
	int x, y;
	Player(int pos_x,int pos_y);
	//�ƶ�����
	bool move(char direction,Box &box);
	//�ж��Ƿ�������,����ֵΪ������player����һ��
	char AdjacentBox(Box box);
};
Player::Player(int pos_x, int pos_y) :x(pos_x), y(pos_y){}
char Player::AdjacentBox(Box box)
{
	//�˺�������ͬһ��
	if (x == box.x)
	{
		//�����������˵��ı�(����)
		if (y == box.y + 1)return 'l';
		else if (y == box.y - 1)return 'r';
		else return 'N';
	}
	//�˺�������ͬһ��
	else if (y==box.y)
	{
		//�����������˵��ıߣ����£�
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
		//�ұ��Ǳ߽�
		if (y == N - 1)return false;
		//�ұ�������
		else if (AdjacentBox(box) == 'r')
		{
			//�������ҿ����ƶ�
			if (box.IsCollision('r')){
				MAP[box.x][box.y] = PLAIN;//�����ƶ��ߺ��޸�Ϊ�յ�
				box.y = box.y + 1;//��������
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//���ƶ�����λ���޸�Ϊ����ռ��

				MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
				y++;//������
				MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
				return true;
			}
			//�������Ҳ����ƶ�
			else return false;
		}
		//�ұ���ǽ
		else if (MAP[x][y+1] == WALL)return false;
		//û�����Ӱ��ţ�û���谭�����
		else
		{
			MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
			y++;
			MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
			return true;
		}
		break;


	case 'l':
		//����Ǳ߽�
		if (y == 0)return false;
		//���������
		else if (AdjacentBox(box) == 'l')
		{
			//������������ƶ�
			if (box.IsCollision('l')){
				MAP[box.x][box.y] = PLAIN;//�����ƶ��ߺ��޸�Ϊ�յ�
				box.y = box.y - 1;//��������
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//���ƶ�����λ���޸�Ϊ����ռ��

				MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
				y--;//������
				MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
				return true;
			}
			//�����������ƶ�
			else return false;
		}
		//�����ǽ
		else if (MAP[x][y-1] == WALL)return false;
		//û�����Ӱ��ţ�û���谭�����
		else
		{
			MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
			y--;
			MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
			return true;
		}
		break;


	case 'u':
		//�ϱ��Ǳ߽�
		if (x == 0)return false;
		//�ϱ�������
		else if (AdjacentBox(box) == 'u')
		{
			//�������Ͽ����ƶ�
			if (box.IsCollision('u')){
				MAP[box.x][box.y] = PLAIN;//�����ƶ��ߺ��޸�Ϊ�յ�
				box.x = box.x - 1;//��������
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//���ƶ�����λ���޸�Ϊ����ռ��

				MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
				x--;//������
				MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
				return true;
			}
			//�������ϲ����ƶ�
			else return false;
		}
		//�ϱ���ǽ
		else if (MAP[x-1][y] == WALL)return false;
		//û�����Ӱ��ţ�û���谭�����
		else
		{
			MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
			x--;
			MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
			return true;
		}
		break;


	case 'd':
		//�±��Ǳ߽�
		if (x == M-1)return false;
		//�±�������
		else if (AdjacentBox(box) == 'd')
		{
			//�������¿����ƶ�
			if (box.IsCollision('d')){
				MAP[box.x][box.y] = PLAIN;//�����ƶ��ߺ��޸�Ϊ�յ�
				box.x = box.x + 1;//��������
				if (MAP[box.x][box.y] == GOAL)RESULT = true;
				MAP[box.x][box.y] = BOX;//���ƶ�����λ���޸�Ϊ����ռ��

				MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
				x++;//������
				MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
				return true;
			}
			//�������²����ƶ�
			else return false;
		}
		//�±���ǽ
		else if (MAP[x+1][y] == WALL)return false;
		//û�����Ӱ��ţ�û���谭�����
		else
		{
			MAP[x][y] = PLAIN;//���ƶ��ߺ��޸�Ϊ�յ�
			x++;
			MAP[x][y] = PLAYER;//���ƶ�����λ���޸�Ϊ��ռ��
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
	//�����ֿ��ͼ
	map.Setup();
	//�õ��˺����ӵ�λ��
	map.GetPosition(pos_player, pos_box, M, N);
	//������������
	Player player(pos_player.first,pos_player.second);
	Box box(pos_box.first, pos_box.second);
	cout << "���뷽�����еĸ�����" << endl;
	cin >> numDir;
	char *dir = (char*)malloc(numDir * sizeof(char));
	cout << "���뷽�����У�" << endl;
	cin >> dir;
	for (int i = 0; i < numDir; i++)
	{
		if (player.move(dir[i], box))continue;
		else break;
	}
	if (RESULT)cout << "Yes" << endl;
	else cout << "No" << endl;
}