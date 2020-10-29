#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt = 0;
int n, m;
int map[300][300];
int check[300][300];
bool exitC = false;
int cc = 0;
void solution()
{
	bool Bcheck[300][300] = { false , };
	cc++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0)
			{

				for (int w = 0; w < 4; w++)
				{
					int nx = i + dx[w];
					int ny = j + dy[w];
					if (map[nx][ny] == 0 && Bcheck[nx][ny] == false)
					{
						map[i][j]--;
						if (map[i][j] < 0)
							map[i][j] = 0;
					}
				}
				Bcheck[i][j] = true;
			}

		}
	}
}

void bfs(int i, int j)
{

	queue<pair<int, int>> q;
	q.push({ i,j }); 
	check[i][j] = true;
	int temp = 0;
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = xx + dx[w];
			int ny = yy + dy[w];

			if (nx < 0 | nx >= n | ny < 0 | ny >=m)
				continue;
			if (check[nx][ny])
				continue;
			if (map[nx][ny] != 0)
			{
				check[nx][ny] = true;
				q.push({ nx,ny });
				temp++;
			}

		}

	}
	cnt++;
 

}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);



	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int ch = 0;
	while (1)
	{
		ch++;
		solution();
		cnt = 0;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 0)
					continue;
				if (check[i][j])
					continue;
				queue<pair<int, int>> q;
				q.push({ i,j });
				check[i][j] = true;
				int temp = 0;
				while (!q.empty())
				{
					int xx = q.front().first;
					int yy = q.front().second;
					q.pop();
					for (int w = 0; w < 4; w++)
					{
						int nx = xx + dx[w];
						int ny = yy + dy[w];

						if (nx < 0 | nx >= n | ny < 0 | ny >= m)
							continue;
						if (check[nx][ny])
							continue;
						if (map[nx][ny] != 0)
						{
							check[nx][ny] = true;
							q.push({ nx,ny });
							temp++;
						}

					}

				}
				cnt++;

				if (cnt >= 2)
				{
					cout << ch << endl;
					return 0;
				}
				
			}

			if (cnt >= 2)
				break;
		}

		if (cnt >= 2)
			break;
	}

	cout << ch << endl;
	return 0;
}