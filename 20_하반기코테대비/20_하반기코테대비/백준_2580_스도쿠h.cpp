#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 9
/*
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0



*/

using namespace std;
 
int map[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];
void Print()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}



void dfs(int cnt)
{//cnt : 
	int x = cnt / 9;//x좌표
	int y = cnt % 9;//y좌표
	if (cnt == 81)
	{
		Print();
		exit(0);
		//return;
	}

	if (map[x][y] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
			{
				row[x][i] = true;
				col[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				map[x][y] = i;
				dfs(cnt + 1);
				map[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
			 
			}

		}

	}
	else dfs(cnt + 1); 

}
int main()
{
 


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
			{
				row[i][map[i][j]] = true; //i번째 가로줄에 n라는 숫자가 이미 존재합니다.
				col[j][map[i][j]] = true; //j번째 세로줄에 n라는 숫자가 이미 존재합니다.
				square[(i / 3) * 3 + (j / 3)][map[i][j]] = true; //a번째 사각형에 b라라는 숫자가 이미존재합니다.

			}
		}
	} 
	dfs(0);

	return 0;
}