
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
/*
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/


using namespace std;
int map[10][10];
int cpymap[10][10];
int n, m;
bool visit[7][7];
bool visit2[10][10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int maxNum = -987654321;
int check()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 99)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit2[x][y] = true;
	int tempMap[10][10];
	memcpy(tempMap, map, sizeof(tempMap));
	
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = xx + dx[w];
			int ny = yy + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue; 
			if (visit2[nx][ny])
				continue;
			if (map[nx][ny] == 1)
				continue;
			if (map[nx][ny] ==99)
			{
				visit2[nx][ny]=true;
				map[nx][ny] = 2;
				q.push({ nx,ny });
			}

		}
			
	}
	int checkNum = check();
	maxNum = max(maxNum, checkNum);
	if (maxNum == 30)
	{
		string nuaa = "asdf";
	}
	memcpy(map, tempMap, sizeof(map));
}

void dfs(int x, int y, int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 2 && visit2[i][j]==false)
				{
					bfs(i, j);
					memset(visit2, false, sizeof(visit2));
				}
			}
		}
		
		//check();
		return;
	}

	map[x][y] = 1;
	visit[x][y] = true;
	for (int i = x; i < n; i++)
	{
		for (int j = y; j < m; j++)
		{
			if (map[i][j] == 99)
			{
				if (!visit[i][j])
				{
					visit[i][j] = true;
					map[i][j] = 1;
					dfs(i, j, cnt + 1);
					map[i][j] = 99;
					visit[i][j] = false;
				}
			}
		}
	}
	
	


}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			cin >> map[i][j];
			if (map[i][j] == 0)
				map[i][j] = 99;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 99)
			{
				dfs(i, j, 1);
			}
		}
	}
	cout << maxNum << endl;
	return 0;
}