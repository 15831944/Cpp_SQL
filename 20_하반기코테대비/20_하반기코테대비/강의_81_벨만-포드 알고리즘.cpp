#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
5 7
1 2 5
1 3 4
2 3 -3
2 5 13
3 4 5
4 2 3
4 5 7
1 5 
*/



using namespace std;
int dist[101];
struct Edge
{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c)
	{
		s = a;
		e = b;
		val = c;
	}
};



int main()
{
	vector<Edge> Ed;
	int n, m, a, b, c, s, e;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i] = 2147000000;
	}
	cin >> s >> e;
	dist[s] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < Ed.size(); j++)
		{
			int u = Ed[j].s;
			int v = Ed[j].e;
			int w = Ed[j].val;
			if (dist[u] != 2147000000 && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}
	}
	for (int j = 0; j < Ed.size(); j++)
	{
		int u = Ed[j].s;
		int v = Ed[j].e;
		int w = Ed[j].val;
		if (dist[u] != 2147000000 && dist[u] + w < dist[v])
		{
			cout << "-1" << endl;
			exit(0);
		}
	}

	cout << dist[e] << endl;

	return 0;
}