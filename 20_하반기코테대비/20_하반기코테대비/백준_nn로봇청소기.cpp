/*
7 5
.......
.o...*.
.......
.*...*.
.......
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
10 10
..........
..o.......
..........
..........
..........
.....xxxxx
.....x....
.....x.*..
.....x....
.....x....
0 0

7 5
.......
.o...*.
.......
.*...*.
.......
0 0
*/


#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;


string map[101][101];

bool visit[101][101];
int sX;
int sY;
queue<pair<int, int>> dirty;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
int answer = 0;
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	int map2[101][101] = { 0, };
	memset(visit, false, sizeof(visit));
	visit[x][y] = true;
	bool check = false;

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
			if (visit[nx][ny])
				continue;

			if (!visit[nx][ny])
			{
				if (map[nx][ny] == "." || map[nx][ny] == "*")
				{
					if (map[nx][ny] == "*")
					{
						check = true;
						visit[nx][ny] = true;;

						map[nx][ny] = ".";
						map2[nx][ny] = map2[nowX][nowY] + 1;
						answer = answer + map2[nx][ny];
						bfs(nx, ny);
						break;
					}
					q.push({ nx,ny });
					visit[nx][ny] = true;
					map2[nx][ny] = map2[nowX][nowY] + 1;
				}
			}
		}
	}
}
int main()
{
	while (1)
	{

		cin >> n >> m;
		//초기화 장소.
		if (n == 0 && m == 0)
		{
			break;
		}
		for (int i = 0; i < m; i++)
		{
			string temp;
			cin >> temp;
			for (int j = 0; j < n; j++)
			{
				map[j][i] = temp[j];
				if (map[j][i] == "o")
				{
					sX = j;
					sY = i;
				}
				else if (map[j][i] == "*")
				{
					dirty.push({ j,i });
				}

			}
		}
		bfs(sX, sY);


	}

	return 0;
}
































