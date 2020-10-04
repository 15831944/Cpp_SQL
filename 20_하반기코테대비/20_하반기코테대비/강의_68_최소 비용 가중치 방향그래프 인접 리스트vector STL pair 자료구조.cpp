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
//int map[100][100];
vector<pair<int, int>> map[300];
int a, b, c;
int visit[100];
int cost = 987654321;
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
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
		for (int i = 0; i< map[Lv].size(); i++)
		{
			int temp = map[Lv][i].first;
			if (visit[map[Lv][i].first] == 0)
			{
				visit[map[Lv][i].first] = 1;
				dfs(map[Lv][i].first, sum + map[Lv][i].second);
				visit[map[Lv][i].first] = 0;
			}

		}
	} 


}
int main()
{
	input();
	visit[1] = 1;
	dfs(1, 0);
	cout << cost;
	return 0;
}