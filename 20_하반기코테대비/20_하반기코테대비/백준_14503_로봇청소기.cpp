
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
		
		//û�Ҹ� �Ѱ��� 2�� �ٲ۴�.
		if (map[x][y] == 0) //û���Ѱ� üũ
		{
			map[x][y] = 2;
			result++;
		}
		int check = 0;
		/*
		4������ ��� ���ڿ� �ش� ���� û�Ұ��ɽ� check�� ���س���
		
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
				check = 1; //û���Ұ��߰��ߴ�.
				break;
			}
		}
		/*
		û�ҿϷ�
		*/
		if (check == 1)
			continue;
		/*
		����
		dir���ٰ� -2�ϰڴٴ� ����
		180�� ������ �����ڴٴ� ���̴�.
		�װ����� �����ϰڴٴ� ���� �����ϰڴٴ°��̴�.
		*/
		int temp_dir = dir - 2;
		if (temp_dir == -2)
			temp_dir = 2;
		if (temp_dir == -1)
			temp_dir = 3;

		x = x + dx[temp_dir];
		y = y + dy[temp_dir];

		/*
		�����ص� �ұ��ϰ� �װ��� 1�̸� ������.*/
		if (map[x][y] == 1)
			break;
	}
		
	cout << result;
	return 0;

}