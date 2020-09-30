#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n, m, k;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int map[400][400] = { 0, };
int map2[400][400] = { 0, };
bool visit[400][400] = { false, };
void solution()
{
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < k; i++)
	{
		for (int i = 0; i < 400; i++)
		{
			for (int j = 0; j < 400; j++)
			{

				if (map2[i][j] != 0)
				{
					visit[i][j] = true;
					map[i][j]--;
					if (map[i][j] == -1)
					{
						q.push({ map2[i][j], { i, j } });
					}
				}
			}
		}

		while (!q.empty())
		{
			int x = q.front().second.first;
			int y = q.front().second.second;
			int z = q.front().first;
			q.pop();
			for (int w = 0; w < 4; w++)
			{
				int nx = x + dx[w];
				int ny = y + dy[w];

				if (map[nx][ny] != 0 || visit[nx][ny] == true)
					continue;
				visit[nx][ny] = true;
				map[nx][ny] = z;
				map2[nx][ny] = z;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (map[i][j] > 0)
				cnt++;
		}
	}

	cout << cnt << endl;

}

void input()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i + 200][j + 200];
			map2[i + 200][j + 200] = map[i + 200][j + 200];

		}
	}
}
int main()
{
	input();
	solution();

	return 0;
}