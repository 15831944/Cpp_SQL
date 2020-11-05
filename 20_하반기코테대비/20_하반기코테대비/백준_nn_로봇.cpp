#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;


/*
5 6
0 0 0 0 0 0
0 1 1 0 1 0
0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
2 4 1


5 6
0 0 0 0 0 0
0 1 1 D 1 0
0 1 0 0 0 0
0 S 1 1 1 0
1 0 0 0 0 0
4 2 3
2 4 1
*/
















int n, m;
int map[100][100];
int map2[100][100];
int startX;
int startY;
int startDir;
int endX;
int endY;
int endDir;
int answer = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visit[100][100];
int cnt = 0;
struct robot
{
	int nowx;
	int nowy;
	int nowdir;//동1서2남3북4
	int turn;
};


int checkDir(int mX, int mY, int nx, int ny)
{
	if (mX - nx <0)//북쪽
	{
		return 4;
	}
	else if (mX - nx > 0)//남쪽
	{
		return 3;
	}
	else if (mY - ny > 0) //동쪽
	{
		return 1;
	}
	else if (ny - ny < 0)//서쪽
	{
		return 2;
	}

}


void bfs(int x, int y, int dir)
{
	queue<robot> q;
	q.push({ x,y,dir,0 });
	visit[x][y] = true;
	while (!q.empty())
	{
		int nx = q.front().nowx;
		int ny = q.front().nowy;
		int ndir = q.front().nowdir;
		int nturn = q.front().turn;
		q.pop();
		if (nx == endX&&ny == endY)
		{
			if (ndir != endDir)
			{
				//동서남북극혐..
				//하드코딩으로 마무리해야할듯.
				answer = nturn + map2[nx][ny] + 1;
			}
			else
			{
				answer = nturn + map2[nx][ny];
			}

			break;
		}
		for (int w = 0; w < 4; w++)
		{
			int moveX = nx + dx[w];
			int moveY = ny + dy[w];
			if (moveX<0 || moveX >= n || moveY<0 || moveY >= m)
				continue;
			if (visit[moveX][moveY])
				continue;
			if (map[moveX][moveY] == 1)
				continue;
			if (map[moveX][moveY] == 0)
			{
				visit[moveX][moveY] = true;
				int nextDir = checkDir(moveX, moveY, nx, ny);
				if (ndir != nextDir)
				{
					nturn = nturn + 1;
					map2[moveX][moveY] = map2[nx][ny] + 1;
					q.push({ moveX,moveY,nextDir,nturn });
				}
				else
				{
					map2[moveX][moveY] = map2[nx][ny];
					q.push({ moveX,moveY,nextDir,nturn });
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
		}
	}
	cin >> startX >> startY >> startDir;
	cin >> endX >> endY >> endDir;
	startX = startX - 1;
	startY = startY - 1;
	endX = endX - 1;
	endY = endY - 1;

	bfs(startX, startY, startDir);
	cout << answer << endl;
	return 0;
}
