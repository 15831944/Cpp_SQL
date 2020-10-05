#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
4 4
0 1 2 0
1 0 2 1
0 2 1 2
2 0 1 2
*/

using namespace std;
int n, a;
int m;
int sum = 0;
int  dis;
int res = 886543321;
int ch[20];
vector<pair<int, int>> H;
vector<pair<int, int>> PH;
void dfs(int L, int s)
{
	if (L == m)
	{
		sum = 0;
		for (int i = 0; i < H.size(); i++)
		{
			int x1 = H[i].first;
			int y1 = H[i].second;
			dis = 21470000;
			for (int j = 0; j < m; j++)
			{
				int x2 = PH[ch[j]].first;
				int y2 = PH[ch[j]].second;
				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
			}
			sum += dis;
		}
		if (sum < res)
		{
			res = sum;
		}

	
	}
	else
	{
		for (int i = s; i < PH.size(); i++)
		{
			ch[L] = i;
			dfs(L + 1, i + 1);
		}
	}

}

int main()
{

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a;
			if (a == 1) H.push_back({ i,j });
			else if (a == 2) PH.push_back({ i,j });

		}
	}
	dfs(0, 0);
	cout << res;
	//solution();
	return 0;
}