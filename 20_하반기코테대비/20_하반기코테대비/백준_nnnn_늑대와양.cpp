#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;


/*
6 6
..S...
..S.W.
.S....
..W...
...W..
......


.DSD..
.DSDW.
DSD...
.DW...
...W..
......

*/
int n, m;
string map[501][501] = { "", };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool check = false;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = temp[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == "S")
			{
				for (int w = 0; w < 4; w++)
				{
					int nx = i + dx[w];
					int ny = j + dy[w];
					if (nx<0 || nx>n || ny > m || ny < 0)
						continue;
					if (map[nx][ny] == "W")
					{
						check = true;
						cout << "0" << endl;
						exit(0);
					}
					if (map[nx][ny] == "D")
						continue;
					if (map[nx][ny] == ".")
						map[nx][ny] = "D";
				}
			}
		}
	}
	if (check)
		cout << 0 << endl;
	else
	{
		cout << "1" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

	}
	return 0;
}