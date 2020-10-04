#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
6 9
1 3
1 4
2 1
2 5
3 4
4 5
4 6
6 2
6 5

*/

using namespace std;
int n, m;
vector<int> map[30];
int visit[30];
int dis[30];
int a, b;
void input() {
	queue<int> q;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a].push_back(b);
	}
	q.push(1);
	visit[1] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++)
		{
			if (visit[map[x][i]] == 0)
			{
				visit[map[x][i]] = 1;
				q.push(map[x][i]);
				dis[map[x][i]] = dis[x] + 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		cout << i << dis[i];

	}
}
void solution()
{

}

int main()
{
	input();

	return 0;
}