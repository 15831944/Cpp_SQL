#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
9 12
1 2 12
1 9 25
2 3 10
2 8 17
2 9 8
3 4 18
3 7 55
4 5 44
5 6 60
5 7 38
7 8 35
8 9 15
*/

using namespace std;
int unf[1001];
struct Edge
{
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
		val = c;
	}

	//가중치 값에 의해서 오름차순 정렬 오름차순 정렬
	bool operator<(Edge &b) {
		return val < b.val;
	}
};

int Find(int v)
{
	if (v == unf[v])return v;
	else return unf[v] = Find(unf[v]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;

} 

int main()
{
	vector<Edge> Ed;
	int n, m, a, b, c, cnt = 0, res = 0;
	cin >> n >> m;
	for (int i=1; i <= n; i++)
	{
		unf[i] = i;
	}
	for (int i = 1; i <= m; i++) 
	{
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}
	sort(Ed.begin(), Ed.end());

	for (int i = 0; i < m; i++)
	{
		int fa = Find(Ed[i].v1);
		int fb = Find(Ed[i].v2);
		if (fa != fb)
		{
			res += Ed[i].val;
			Union(Ed[i].v1, Ed[i].v2);
		}
	}
	cout << res << endl;
	return 0;
}