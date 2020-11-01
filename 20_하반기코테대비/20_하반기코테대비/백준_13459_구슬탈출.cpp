#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
/*
7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######

7 7
#######
#...RB#
#.##.##
#.....#
#####.#
#O....#
#######
*/


using namespace std;

int n, m;
int map[30][30];
string strmap[30][30];
bool visit[30][30];
bool visitB[30][30];
int startX;
int startY;
int endX;
int endY;
int dx[] = { -1,1,0,0 }; //상,하
int dy[] = { 0,0,-1,1 }; //좌,우
int BX;
int BY;
bool ch;
int nowDir;
int dir = 0; //기본은 북쪽을 바라봄.
int answer = 0;
bool FC;
struct Red
{
	int x;
	int y;
	int dir;
	int bx;
	int by;
	
};

 
void bfs(int x, int y)
{
	//queue<pair<int, int>> q;
	queue<Red> qq;
	//queue<Blue> BB;
	qq.push({ x,y,0,BX,BY });
	//BB.push({ BX,BY,0 });
	//q.push({ x,y });
	visit[x][y] = true;
	//visitB[x][y] = true;
	while (!qq.empty())
	{
		int nowX = qq.front().x;
		int nowY = qq.front().y;
		int bbx = qq.front().bx;
		int bby = qq.front().by;
		if (bbx == endX && bby == endY)
		{
			cout << "0" << endl;
			break;

		}
		//이전 방향과 현재 방향이 바뀌면 ++해준다.
		if (nowDir != qq.front().dir)
		{
			nowDir = qq.front().dir;
			answer++;
		}

		qq.pop();
		if (ch == true)
		{
			cout << "0" << endl;
			break;
		}
		//구슬의 위치가 구멍의 위치일 때
		if (nowX == endX && nowY == endY)
		{
			if (bbx == endX && bby == endY)
			{
				//실패! 
				
				cout << "0" << endl;
				break;
			}
			else {
				//bool ch = checkBlue(strmap[nowX][nowY]);
				
				if (answer <= 10)
					cout << "1" << endl;
				else
					cout << "0" << endl;
			}
			
		}
		for (int w = 0; w < 4; w++)
		{   //w(0)상dir(0), w(1)하dir(2), w(2)좌dir(3), w(3)우 dir(1)
			int nx = nowX + dx[w];
			int ny = nowY + dy[w];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visit[nx][ny])
				continue;
			if (map[nx][ny] == -1)
				continue;
			if (map[nx][ny] == -2 || map[nx][ny]==-5)
			{
				visit[nx][ny] = true; 
				string tempC  = to_string(w);
				strmap[nx][ny] = strmap[nowX][nowY] +tempC[0];
				
				if (w==0)
				{
					dir = 0;
				}
				else if (w==1)
				{
					dir = 2;
				}
				else if (w==2)
				{
					dir = 3;
				}
				else if (w==3)
				{
					dir = 1;
				} 
				//bbx + dx[w];
				//bby + dx[w];
				int temp_BX = bbx + dx[w];
				int temp_BY = bby + dy[w];
				if (map[temp_BX][temp_BY] == -2 || map[temp_BX][temp_BY] == -2)
				{
					bbx + dx[w];
					bby + dy[w];
				}
				qq.push({ nx,ny,dir,bbx,bby });
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
			if (temp[j] == '#')
			{
				map[i][j] = -1;
			}
			else if (temp[j] == '.')
			{
				map[i][j] = -2;
			}
			else if (temp[j] == 'R')
			{
				map[i][j] = -3;
				startX = i;
				startY = j;
			}
			else if (temp[j] == 'B')
			{
				map[i][j] = -4;
				BX = i;
				BY = j;
			}
			else if (temp[j] == 'O')
			{
				map[i][j] = -5;
				endX = i;
				endY = j;
			}
		}
	}
	bfs(startX, startY);


	return 0;
}