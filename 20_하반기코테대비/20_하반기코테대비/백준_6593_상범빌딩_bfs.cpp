/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;

int startZ;
int startX;
int startY; 

int endZ;
int endX;
int endY;

int L, R, C;
int map[101][101][101];
int Plusmap[101][101][101];
bool visit[101][101][101];
int dx[] = { -1,1,0,0,0,0};
int dy[] = { 0,0,-1,1,0,0};
int dz[] = { 0,0,0,0,1,-1};
int cnt;
int answer = 0;
int bfs(int z, int x, int y)
{
	queue<pair<int, pair<int, int>>> q;
	q.push({ z,{x,y} });
	visit[z][x][y] = true;
	
	while (!q.empty())
	{
		
		int xx = q.front().second.first;
		int yy = q.front().second.second;
		int zz = q.front().first;
		q.pop();
		if (xx == endX && yy == endY && zz == endZ)
		{
			answer = Plusmap[zz][xx][yy];
			break;
		}
		for (int w = 0; w < 6; w++)
		{
			int nx = xx + dx[w];
			int ny = yy + dy[w];
			int nz = zz + dz[w];
			
			if (nx < 0 || nx > C || ny < 0 || ny > R)
				continue;
			if (visit[nz][nx][ny])
				continue;
			if (map[nz][nx][ny] == -4)
				continue;
			if (map[nz][nx][ny] == -3 || map[nz][nx][ny]==-2)
			{
				visit[nz][nx][ny] = true;
				q.push({ nz,{nx,ny} });
				Plusmap[nz][nx][ny] = Plusmap[zz][xx][yy]+1; 
			}
			
		}

	}
	
	return - 1;
}
int main()
{
	while (1)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		memset(Plusmap, 0, sizeof(Plusmap));
		startZ=0;
		startX=0;
		startY=0;
		answer = 0;
		endZ =0;
		endX =0;
		endY =0;

		for (int w = 0; w < L; w++)
		{
			for (int i = 0; i < R; i++)
			{
				string temp;
				cin >> temp;
				for (int j = 0; j < C; j++)
				{
					char temp2;
					temp2 = temp[j];
					if (temp2 == 'S')
					{
						map[w][i][j] = -1;
						startZ = w;
						startX = i;
						startY = j;
					}
					else if (temp2 == 'E')
					{
						map[w][i][j] = -2;
						endZ = w;
						endX = i;
						endY = j;

					}

					else if (temp2 == '.')
						map[w][i][j] = -3;
					else
						map[w][i][j] = -4;
				}
			}

		}
		
		if (bfs(startZ, startX, startY) == -1)
			cout << "Trapped!" << endl; 
		else
			cout << "Escaped in " << answer << " " << "minute(s)." << endl;
	}
 
	return 0;
}