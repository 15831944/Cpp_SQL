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
	cin >> n; //5개
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	vector<int> degree(n + 1);
	vector<int> v(n + 1);
	queue<int> q;


	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;
	}
	//v[a] = 5,4,3,2,1
	//5-4, 5-3, 5-3, 5-2, 5-1 간선그래프 생성
	//4-3, 4-2, 4-1, 
	for (int i = 0; i < n; i++)
	{ 
		for (int j = i+1; j < n; j++)
		{
			
			graph[v[i]][v[j]] = 1;
			degree[v[j]]++;
		}
	}

	//바뀌는
	int m;
	cin >> m; //2
	
	for (int i = 0; i < m; i++)
	{
		int c, d;
		cin >> c >> d;
		if (graph[d][c] == 1)
		{
			graph[d][c] = 0;
			graph[c][d] = 1;
			degree[d]++;
			degree[c]--;
		}
		else
		{
			graph[d][c] = 1;
			graph[c][d] = 0;
			degree[c]++;
			degree[d]--;
		}
	}

	for (int i = 1; i <=n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	bool certain = true;
	if (q.size()==0)
		cout << "IMPOSSIBLE" << endl;
	while (!q.empty())
	{
		if (q.size() > 1)
		{
			cout << "IMPOSSIBLE" << endl;
			break;
		}
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
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solution();
 
	return 0;
}