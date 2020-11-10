#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>


using namespace std;

int n, m;
string map[1000][1000];
int map3[1000][1000];

int startX;
int startY;
int endX;
int endY;
int visit[1000][1000];
int map2[1000][1000];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int answer = 0;
void bfs(int xxx, int yyy)
{
	queue<pair<int, int>> q;
	q.push({ xxx, yyy });
	visit[xxx][yyy] = true;
	while (!q.empty())
	{
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++)
		{
			int nx = nowx + dx[w];
			int ny = nowy + dy[w];
			if (visit[nx][ny])
				continue;
			if (nx < 0 || nx > n | ny < 0 || ny > m)
				continue;
			if (map[nx][ny] == "X" || map[nx][ny] == "S" || map[nx][ny] == "D")
				continue;
			if (!visit[nx][ny])
			{
				if (map[nx][ny] == ".")
				{
					visit[nx][ny] = true;
					q.push({ nx, ny });
					int tempa = map2[nowx][nowy] + 1;
					if (map2[nx][ny] <= tempa)
					{
						map2[nx][ny] = tempa;
					}

				}
			}
		}
	}

}
void bfs2(int xxx, int yyy)
{
	queue<pair<int, int>> q;
	q.push({ xxx, yyy });
	visit[xxx][yyy] = true;
	while (!q.empty())
	{
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		if (nowx == endX && nowy == endY)
		{
			answer = map3[nowx][nowy];
			//return answer;
		}
		for (int w = 0; w < 4; w++)
		{
			int nx = nowx + dx[w];
			int ny = nowy + dy[w];
			if (visit[nx][ny])
				continue;
			if (nx < 0 || nx >= n | ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == "." && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				if (map3[nx][ny] == 0)
				{
					map3[nx][ny] = map3[nx][ny] + 1;
					q.push({ nx,ny });
				}
				else if (map2[nx][ny] >= map3[nx][ny] + 1)
				{
					map3[nx][ny] = map3[nx][ny] + 1;
					q.push({ nx,ny });
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
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = temp[j];

			if (map[i][j] == "S")
			{
				startX = i;
				startY = j;
			}
			else if (map[i][j] == "D")
			{
				endX = i;
				endY = j;
			}

		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == "*")
			{
				bfs(i, j);
			}
		}
	}
	memset(visit, false, sizeof(visit));
	int ans = 0;
	bfs2(startX, startY);
	if (answer != 0)
		cout << answer << endl;
	else
		cout << "KAKTUS" << endl;

	return 0;
}

