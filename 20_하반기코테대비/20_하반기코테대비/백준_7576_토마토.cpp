
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 1001

/*
6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
*/
using namespace std;

int n, m;
int map[MAX][MAX]; 
bool visit[MAX][MAX];
queue<pair<int, int>> q;
int answer = 0;
bool flag = false;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int maxNum = -987654321;
void bfs() 
{

	while (!q.empty()) 
	{
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = nowX + dx[w];
			int ny = nowY + dy[w];
		 

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == -1)
			{ 

				//cout << "¹¹ÁöX " << ny << endl;
				//cout << "¹¹ÁöY " << nx << endl;
				continue;
			}
			if (map[nx][ny] == 0 && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
				map[nx][ny] = map[nowX][nowY] + 1;
			}
		} 

	}


}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0 )
			{
				flag = true;
				break;
			}
			else if (maxNum < map[i][j])
			{
				maxNum = map[i][j];
			}

		}
		if (flag)
			break;
	}
	//cout << "check" << map[1][0] << endl;
	if (flag)
		cout << -1 << endl;
	else
		cout << maxNum-1 << endl;

	return 0;
}
