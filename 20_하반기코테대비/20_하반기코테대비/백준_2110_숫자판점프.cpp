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
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

set<int> s;
//string map[5][5];
int map[5][5];
int answer = 0;
int tempcnt;
void dfs(int x, int y, int cnt, int strTotal)
{

	if (cnt == 5)
	{
		s.insert(strTotal);
		answer = s.size();
		tempcnt++;
		return;
	}

	for (int w = 0; w < 4; w++)
	{
		int nx = x + dx[w];
		int ny = y + dy[w];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;

		dfs(nx, ny, cnt + 1, strTotal * 10 + map[nx][ny]);

	}
}
int main()
{
	int cnt = 4;
	//set<string> s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(i, j, 0, map[i][j]);
		}
	}

	cout << answer << endl;
	return 0;
}