#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#define MAX 100
using namespace std;

/*12 x 6

......
......
......
......
......
......
......
......
.Y....
.YG...
RRYGG.
RRYGG.

*/
struct info
{
	int x;
	int y;
	int cnt;
};


string map[MAX][MAX];
bool visit[MAX][MAX];
int delMap[MAX][MAX] = { 1, };
queue<pair<int, int>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void printmap()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}
void Pung()
{

	while (!q.empty())
	{
		int Nowx = q.front().first;
		int Nowy = q.front().second;
		visit[Nowx][Nowy] = true;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = Nowx + dx[w];
			int ny = Nowy + dy[w];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
				continue;
			if (map[nx][ny] != "." && !visit[nx][ny])
			{
				//visit[nx][ny] = true;
				//q.push({ nx,ny });
				if (map[nx][ny] == map[Nowx][Nowy])
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
					delMap[nx][ny] = delMap[Nowx][Nowy] + 1;
				}
			}
		}

	}



}
void realPung()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (delMap[i][j] >= 4)
			{
				map[i][j] = ".";
			}
		}

	}
	printmap();
}


int main()
{
	for (int i = 0; i < 12; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < 6; j++)
		{
			map[i][j] = temp[j];
			if (map[i][j] != ".")
			{
				//visit[i][j] = true;
				q.push({ i,j });
			}
		}

	}


	Pung();
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << delMap[i][j];
		}
		cout << endl;
	}
	realPung();
	return 0;
}