#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#define MAX 100
using namespace std;
/*
6 7 4
.......
...o...
....o..
.......
oo.....
oo.....

*/


int r, c, n;//r x c, n檬饶
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
				map[i][j] = "o";
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

			if (map[i][j] == "o")
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
		//酒公老档救积辫..?
		if (time == 1)
		{
			checkPUNG();
		}
		//后沫 气藕盲快扁
		else if (time % 2 == 0)
		{
			fill();
		}
		//气藕 沏
		else if (time % 2 == 1)
		{
			Pung();
		}
		if (time == n)
		{
			PrintMap();
			break;
		}
	}

	return 0;
}