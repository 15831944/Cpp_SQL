#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int map[100][100];
int t,n,x,y;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<pair<int,int>,int>> q; 

void input()
{
	cin >> n >> x >> y ; 
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num; 
		}
	}
} 
void sol2(int sNum)
{
	for (int i = 0; i < 4; i++)
	{ 
		if (map[dx[i]][dy[i]] == 0 )
			continue;
		else if (map[dx[i]][dy[i]] > sNum)
		{
		//	sol2(sNum);
		}
	 
	}
}
void sol(int fNum)
{
    //bombs.push({ { x좌표,y좌표 },해당 값 });
	//q.push( { { x , y } , value } );
	//가로 탐색
	for (int i = 0; i < x; i++) 
	{
		if (map[i][0] == 0)
		{
			continue;
		}
		else
		{
			//해당 값
			//int tempNum = map[i][fNum];
			//q.push( tempNum , { i,0 });
			q.push({ { i,fNum }, map[i][fNum] });
			while (!q.empty())
			{
				int value = q.front().second; // 3,0 
				q.pop();
				//가로줄
				for (int w = 0; w < value; w++)
				{
					if (w == i)
						continue;
					if (map[w][fNum] > 1)
					{
						q.push({ { w,i }, map[w][fNum] });
						map[w][fNum] = 0;
					}
					else if (map[w][fNum] == 0)
						continue;
					else
						map[w][fNum] = map[w][fNum] - value;
				}
				//세로줄

				for (int w = 0; w < value; w++)
				{

					if (w == i)
						continue;
					if (map[i][w] > 1)
					{
						q.push({ { w,i }, map[w][fNum] });
						map[i][w] = 0;
					}
					else if (map[i][w] == 0)
						continue;
					else
						map[i][w] = map[i][w] - value;
				}

			 }

		}
	}
}
int main()
{
	input();
	sol(0); 
	return 0;

}