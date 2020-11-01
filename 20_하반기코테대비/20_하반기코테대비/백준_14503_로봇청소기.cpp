
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 50
int n, m;
int map[MAX][MAX];
int x, y;
int result;
int dir;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

using namespace std;

void solution()
{

}

int main()
{
	cin >> n >> m;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	while (1)
	{
		
		//청소를 한곳은 2로 바꾼다.
		if (map[x][y] == 0) //청소한곳 체크
		{
			map[x][y] = 2;
			result++;
		}
		int check = 0;
		/*
		4방향을 모두 본뒤에 해당 방향 청소가능시 check를 통해나옴
		
		*/
		for (int w = 0; w < 4; w++)
		{
			dir = dir - 1;
			if (dir < 0)
				dir = 3;

			int temp_x = x + dx[dir];
			int temp_y = y + dy[dir];
			/*

			*/
			if (map[temp_x][temp_y] == 0)
			{
				x = temp_x;
				y = temp_y;
				check = 1; //청소할곳발견했다.
				break;
			}
		}
		/*
		청소완료
		*/
		if (check == 1)
			continue;
		/*
		후진
		dir에다가 -2하겠다는 것은
		180도 방향을 돌리겠다는 것이다.
		그곳으로 직진하겠다는 것은 후진하겠다는것이다.
		*/
		int temp_dir = dir - 2;
		if (temp_dir == -2)
			temp_dir = 2;
		if (temp_dir == -1)
			temp_dir = 3;

		x = x + dx[temp_dir];
		y = y + dy[temp_dir];

		/*
		후진해도 불구하고 그곳이 1이면 끝낸다.*/
		if (map[x][y] == 1)
			break;
	}
		
	cout << result;
	return 0;

}