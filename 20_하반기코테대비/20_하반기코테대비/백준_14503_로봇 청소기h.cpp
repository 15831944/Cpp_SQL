/*
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int di[] = { 0,1,2,3 };
int map[50][50];
 
int n, m;
int x, y, z;
vector<pair<int, pair<int, int>>> v;
int main()
{
	//solution();
	cin >> n >> m;
	cin >> x >> y >> z;
	v.push_back({ z, { x,y } });
 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int nx = v.front().second.first;
	int ny = v.front().second.second;
	int bang = v.front().first;
	int cnt = 1;
	int result = 0;
	while (1) 
	{ 
		if (map[nx][ny] == 0)
		{
			map[nx][ny] = 2;
			result++;
		}
		int check = 0;
		for (int i = 0; i < 4; i++)
		{
			bang = bang - 1;
			if (bang < 0)
				bang = 3;
			int temp_x = nx + dx[bang];
			int temp_y = ny + dy[bang];
			if (map[temp_x][temp_y] == 0)
			{
				nx = temp_x;
				ny = temp_y;
				check = 1; //2번으로 돌아감
				break;
			} 
		}

		if (check == 1)
			continue;
		int temp_dir = bang - 2;//후진하기
		if (temp_dir == -2)
			temp_dir = 2;
		if (temp_dir == -1)
			temp_dir = 3;

		nx = nx + dx[temp_dir];
		ny = ny + dy[temp_dir];

		if (map[nx][ny] == 1)
			break;  
	}
	cout << result;




	return 0;
}