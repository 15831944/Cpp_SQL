#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 1 0 0 0
1 0 0 0 1 0 0
1 0 1 0 0 0 0

출력
12
1:벽
0:길
1,1에서 7.7까지 최단 경로
*/
using namespace std;
int map[7][7];
int visit[7][7];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int answer = 0;
void bfs(int startX,int startY)
{
	queue<pair<int,int>> q;
	q.push({ startX,startY });
	int cnt = 0;
	visit[0][0] = 1;
	while (!q.empty())
	{
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = x + dx[w];
			int ny = y + dy[w];
			
			if (nx > 7 || nx < 0 || ny>7 || ny < 0)
				continue;
			if (visit[nx][ny]>=1)
				continue;
			if (map[nx][ny] == 0)
			{
				visit[nx][ny] = visit[x][y]+1;
				if (nx == 6 && ny == 6)
				{
					answer = visit[nx][ny]-1;
					break;
				}
				q.push({ nx,ny });
			}
		}

	}
}
void input()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0 ;j < 7; j++)
		{
			cin >> map[i][j];
		}
	}
}
int main()
{
	input(); 
	bfs(0,0);
	
	cout << answer << endl;
	return 0;
}