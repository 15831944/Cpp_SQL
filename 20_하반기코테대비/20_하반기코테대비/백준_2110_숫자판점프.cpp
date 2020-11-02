#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1
*/
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

set<string> s;
string map[5][5];
int answer = 0;
void dfs(int x, int y, int cnt, string strTotal)
{

	if (cnt == 5)
	{
		s.insert(strTotal);
		answer = s.size();
		return;
	}

	for (int w = 0; w < 4; w++)
	{
		int nx = x + dx[w];
		int ny = y + dy[w];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;
		string temp = strTotal;
		dfs(nx, ny, cnt + 1, strTotal += map[nx][ny]);
		strTotal = temp;
	}
}
int main()
{
	int cnt = 4;
	set<string> s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			dfs(i, j, 0, map[i][j]);
		}
	}

	cout << answer << endl;
	return 0;
}