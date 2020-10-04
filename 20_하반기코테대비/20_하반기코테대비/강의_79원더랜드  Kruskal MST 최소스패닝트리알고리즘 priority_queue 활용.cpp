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
int ch[1001];
struct Edge
{
	int e;
	int val;
	//ex) (8,17)
	Edge(int a, int b)
	{
		e = a;
		val = b;
	}
	//����ġ ���� ���ؼ� �������� ���� --�ּ���
	bool operator<(const Edge &b) const{
		return val > b.val;
	}
};

 
int main()
{
	priority_queue<Edge> Q;
	//����ġ ��������Ʈ!!!
	vector<pair<int, int>> map[30];
	int n, m, a, b, c, cnt = 0, res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		//a-c->b �����
		map[a].push_back({ b,c });
		//b-c->a �����
		map[b].push_back({ a,c });
	}
	Q.push(Edge(1, 0));//1�����۰���ġ0
	while (!Q.empty())
	{
		Edge tmp = Q.top();
		Q.pop(); //�̹� �����̸� �׳� pop�ǰ� ����.
		int v = tmp.e;
		int cost = tmp.val;
		if (ch[v] == 0)
		{
			res += cost;
			ch[v] = 1; //v��� ������ ���д�Ʈ����.
			for (int i = 0; i < map[v].size(); i++)
			{
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		} 

	}
	cout << res << endl;
	 
	return 0;
}