#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


/*
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7


*/
int n;
int map[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int maxNum = -987654321;
bool visit[101][101] = { false, };
int cnt = 0;
int maxmax = 1;
void jangma(int w)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] <= w)
				map[i][j] = -1;
		}
	}

}
void bfs(int x, int y)
{
	cnt++;
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = xx + dx[w];
			int ny = yy + dy[w];

			if (nx<0 || nx >= n || ny<0 || ny >= n)
				continue;
			if (visit[nx][ny])
				continue;

			if (map[nx][ny] != -1)
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}


}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			cin >> map[i][j];
			if (maxNum < map[i][j])
				maxNum = map[i][j];
		}
	}
	for (int w = 1; w < maxNum; w++)
	{

		cnt = 0;
		jangma(w);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] != -1 && visit[i][j] == false)
					bfs(i, j);
				if (cnt > maxmax)
					maxmax = cnt;
			}
		}
	}
 
	cout << maxmax << endl;
	return 0;
}