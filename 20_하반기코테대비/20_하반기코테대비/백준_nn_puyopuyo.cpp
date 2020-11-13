#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <cstring>
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


string map[12][6];
bool visit[12][6];
 
queue<pair<int, int>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer = 0;
void resetMap()
{

	for (int i = 10; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == ".") continue;
			int Tmp = i;

			while (1)
			{
				if (Tmp == 11 || map[Tmp + 1][j] != ".") break;

				map[Tmp + 1][j] = map[Tmp][j];
				map[Tmp][j] = ".";
				Tmp++;
			}
		}
	}






}

void printmap()
{
	cout << endl;
	cout << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}
void realPung()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (visit[i][j])
			{
				map[i][j] = ".";
			}
		}
	}
	resetMap();
	
}

void Pung(int x,int y)
{
	visit[x][y] = true;
	q.push({ x,y });
	int cnt = 1; 
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
			if (visit[nx][ny])
				continue;
			if (map[nx][ny] != "." && !visit[nx][ny])
			{
				//visit[nx][ny] = true;
				//q.push({ nx,ny });
				if (map[nx][ny] == map[Nowx][Nowy])
				{
					cnt++; 
					visit[nx][ny] = true;
					q.push({ nx,ny });
				 
				}
			}
		} 
	}
	if (cnt >= 4)
	{
		answer++;
		realPung();
	}

 
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
		 
		}

	}



	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] != ".")
			{
				Pung(i, j);
				memset(visit, false, sizeof(visit));
			}
		}
		 
	}
	cout << answer << endl;
	return 0;
}