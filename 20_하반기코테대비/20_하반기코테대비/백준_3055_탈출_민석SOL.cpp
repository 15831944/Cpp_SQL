#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int vi[50][50];
int n, m, ans;
queue<pair<int, int>> wq;
int gox, goy, bix, biy;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				wq.push({ i,j });
			else if (map[i][j] == 'S')
			{
				gox = i;
				goy = j;
			}
			else if (map[i][j] == 'D')
			{
				bix = i;
				biy = j;
			}
		}
	}
}

void solve()
{
	while (!wq.empty())
	{
		pair<int, int> xxx = wq.front();
		wq.pop();
		bool visit[50][50] = { false, };
		queue<pair<int, int>> q;
		q.push({ xxx.first,xxx.second });
		visit[xxx.first][xxx.second] = true;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int w = 0; w < 4; w++)
			{
				int nx = x + dx[w];
				int ny = y + dy[w];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (map[nx][ny] == '.' && !visit[nx][ny])
				{
					visit[nx][ny] = true;
					if (vi[nx][ny] == 0)
					{
						vi[nx][ny] = vi[x][y] + 1;
						q.push({ nx,ny });
					}
					else if (vi[nx][ny] >= vi[x][y] + 1)
					{
						vi[nx][ny] = vi[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	bool visit[50][50] = { false, };
	queue<pair<pair<int, int>, int>> q;
	q.push({ { gox,goy },0 });
	visit[gox][goy] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == bix && y == biy)
		{
			ans = cnt;
			break;
		}

		for (int w = 0; w < 4; w++)
		{
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == '.' && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				if (vi[nx][ny] > cnt + 1)
					q.push({ { nx,ny },cnt + 1 });
				else if (vi[nx][ny] == 0)
					q.push({ { nx,ny },cnt + 1 });
			}
			if (nx == bix && ny == biy)
				q.push({ { nx,ny },cnt + 1 });
		}
	}

}

int main()
{
	input();
	solve();
	if (ans == 0)
		cout << "KAKTUS" << endl;
	else
		cout << ans << endl;
	return 0;
}