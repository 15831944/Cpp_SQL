#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
6 6
1 4
5 4
4 3
2 5
2 3
6 2*/

using namespace std;
int n, m, a, b, score;


void solution()
{
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	vector<int> degree(n + 1);
	queue<int> q;


	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		degree[b] ++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 1; i <= n; i++)
		{
			if (graph[now][i] == 1)
			{
				degree[i]--;
				if (degree[i] == 0)
					q.push(i);
			}
		}
	}
}


int main()
{
	//input();
	solution();
	return 0;
}