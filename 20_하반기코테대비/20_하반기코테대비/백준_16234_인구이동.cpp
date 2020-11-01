
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>



using namespace std;
int n, l, r;
int map[1001][1001];
bool visit[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool ch ;
int answer = 0;
void solution(int x,int y)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;

	q.push({ x,y });
	v.push_back({ x,y });
	visit[x][y] = true;
	int cnt = 1;
	int sum = map[x][y];
	while (!q.empty())
	{
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = nowx + dx[w];
			int ny = nowy + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visit[nx][ny])
				continue;
			//중요
			int temp = abs(map[nx][ny] - map[nowx][nowy]);
			if (temp >= l && temp <= r)
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
				v.push_back({ nx,ny });
				sum += map[nx][ny];
				cnt++;
				ch = true;
			}
			
		} 	
	}//end while
	//계산
	int changNum = sum / cnt;
	while(!v.empty())
	{
		int vx = v.back().first;
		int vy = v.back().second;
		v.pop_back();
		map[vx][vy] = changNum;
		
	}
	

}

int main()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	bool finish = false;
	while (1)
	{
		memset(visit, false, sizeof(visit));
		finish = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j] == false)
				{
					
					solution(i, j);
					if (ch)
					{
						finish = true;
						answer++;
					}
				 
				}
			}
		}
	
		if (!finish)
			break;

		
	}
	
	cout << answer << endl;
	return 0;
}