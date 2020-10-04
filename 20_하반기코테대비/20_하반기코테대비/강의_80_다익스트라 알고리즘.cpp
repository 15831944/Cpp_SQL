#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


/*
6 9
1 2 12
1 3 4
2 1 2
2 3 5
2 5 5 
3 4 5
4 2 2
4 5 5 
6 4 5
*/
using namespace std;
struct Edge {
	int vex;
	int dis;
	Edge(int a, int b)
	{
		vex = a;
		dis = b;
	}
	bool operator<(const Edge &b) const
	{//최소힙 가장 작은 값이 상위에 있게함.
		return dis > b.dis;
	}
};
 

int main()
{ 
	priority_queue<Edge> Q;
	vector<pair<int, int>> graph[30];
	int i, n, m, a, b, c;
	cin >> n >> m;
	vector<int> dist(n + 1, 21470000);

	for (i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	Q.push(Edge(1, 0));
	dist[1] = 0;
	while (!Q.empty())
	{
		int now = Q.top().vex;
		int cost = Q.top().dis;
		Q.pop();
		if (cost > dist[now]) continue;
		for (i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextdis = cost + graph[now][i].second;
			if (dist[next] > nextdis)
			{
				dist[next] = nextdis;
				Q.push(Edge(next, nextdis));
			}
		}


	}//end while

	for (i = 2; i <= n; i++)
	{
		if (dist[i] < 100000)
			cout << i << " : " << dist[i] << endl;
		else
			cout << i << " : " << "IMPOSSIBLE" << endl;

	}


	return 0;
} 