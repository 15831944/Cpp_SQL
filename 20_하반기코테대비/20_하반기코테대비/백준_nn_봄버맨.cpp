#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <cstring>
#define MAX 201
using namespace std;
/*
6 7 7
.......
...O...
....O..
.......
OO.....
OO.....


*/


int r, c, n;//r x c, n√ »ƒ
string map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void PrintMap()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}

}

void Pung()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visit[i][j])
			{
				map[i][j] = ".";
				for (int w = 0; w < 4; w++)
				{
					int nx = i + dx[w];
					int ny = j + dy[w];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c)
						continue;
					if (!visit[nx][ny])
						map[nx][ny] = ".";
				}

			}

		}
	}
	//PrintMap();
}

void fill()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			if (map[i][j] == ".")
			{
				map[i][j] = "O";
			}

		}
	}

	//PrintMap();
}
void checkPUNG()
{
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			if (map[i][j] == "O")
			{
				visit[i][j] = true;
			}
		}
	}
}
int main() {
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = temp[j];
		}
	}

	int time = 0;
	while (1)
	{
		time++;
		//cout << time << endl;;
		//æ∆π´¿œµµæ»ª˝±Ë..?
		if (time == 1)
		{
			checkPUNG();
			if (time == n)
			{
				PrintMap();
				break;
			}
		}
		//∫Ûƒ≠ ∆¯≈∫√§øÏ±‚
		else if (time % 2 == 0)
		{
			checkPUNG();
			fill();
			if (time == n)
			{
				PrintMap();
				break;
			}
		}
		//∆¯≈∫ ∆„
		else if (time % 2 == 1)
		{
			Pung();
			if (time == n)
			{
				PrintMap();
				break;
			}
		}
	
	}

	return 0;
}