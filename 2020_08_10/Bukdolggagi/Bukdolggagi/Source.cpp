#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 987654321


using namespace std;
int map[100][100];
int t,n,x,y;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<pair<int,int>,int>> q; 


int N, W, H;
//int map[16][12];

//int dr[4] = { -1,1,0,0 };
//int dc[4] = { 0,0,-1,1 };

int ans = INF;


void input()
{
	cin >> n >> x >> y ; 
	for (int i = 1; i <=x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num; 
		}
	}
} 
// 정리해놓기 배열을 레퍼런스로 받는 방법

void copyMap(int(* a)[100], int (* b)[100])
{
	for (int i = 0; i <= H; i++)
	{
		for (int j = 0; i < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void downMap()
{
	for (int i = 0; i < W; i++)
	{
		queue<int> down;
		//차근차근 위에서부터 맨아래로
		for (int r = H; r > 0; r--)
		{
			if (map[r][i] > 0)
			{
				down.push(map[r][i]);
			}

		}
		//아래서부터 맨위까지 0으로 채움
		for (int r = 1; r < H; r++)
		{
			map[r][i] = 0;
		}
		int h = H;
		//위에서 부터 큐에서 빼면서 순서대로 쭉 채워잔다.
		while (!down.empty())
		{
			int range = down.front();
			down.pop();
			map[h][i] = range;
			h--;
		}
	} 
}

void drop(int r, int c, int range) 
{
	if (range == 0)
	{
		if (r + 1 > H)
		{
			return;
		}
		//만약 해당 값이 0이면 계속 탐색한다.
		drop(r + 1, c, map[r + 1][c]);
	}
	else
	{
		//중요 queue
		queue<pair<pair<int, int>, int>> q;
		q.push({ { r,c }, range });
		map[r][c] = 0;
		while (!q.empty())
		{
			int rr = q.front().first.first;
			int cc = q.front().first.second;
			int nRange = q.front().second;
			q.pop();
			for (int i = 1; i < nRange; i++)
			{
				for (int j = 1; j < 4; j++)
				{
					int nx = rr + i*dx[j];
					int ny = cc + i*dy[j];
					if (nx<1 || nx>H || ny<0 || ny>W - 1)
					{
						continue;
					}
					if (map[nx][ny] > 0)
					{
						q.push({ {nx,ny},map[nx][ny] });
						map[nx][ny] = 0;
					}
				}
			} 
		}

		downMap();
	}
}

 
void sol(int fNum)
{
	if (fNum == 0)
	{
		int sum = 0;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (map[i][j] > 0)
				{
					sum++;
				}
			}
			if (ans > sum)ans = sum;
			return;
		}
	}
	int copyM[100][100];
	for (int i = 0; i < W; i++)
	{
		copyMap(map, copyM);

	}
 
}
int main()
{
	input();
	sol(0); 
	return 0;

}
