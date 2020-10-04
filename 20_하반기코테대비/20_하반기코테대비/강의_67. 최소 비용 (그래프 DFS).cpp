#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
//5정점,8간선
5 8
1 2 12
1 3 6
1 4 10
2 3 2
2 5 2
3 4 3
4 2 2
4 5 5
*/
using namespace std;

int n, m;
int map[100][100];
int a, b, c;
int visit[100];
int cost = 987654321;
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		map[a][b] = c;
	}
}
void dfs(int Lv, int sum)
{
	if (Lv == n)
	{
		if (sum < cost) cost = sum;//최소 값
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (map[Lv][i] > 0 && !visit[Lv])
			{
				visit[Lv] = true;
				dfs(i, sum+map[Lv][i]);
				visit[Lv] = false;
			}

		}
	}

	



}
int main()
{
	input();
	dfs(1, 0);
	cout << cost; 
	return 0;
}