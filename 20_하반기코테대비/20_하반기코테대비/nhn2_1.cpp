#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
2
6
6 2 11 0 3 5
6 3 0 9 0 5
*/
vector<int> v;  
int n, m;
int map[50][50];
int ans = 0;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		int maxNum = 0;
		int nowPoint = 0;
		int now = map[i][nowPoint];
		maxNum = now;
		if (i > 0) {
			for (int t = 0; t < m; t++)
			{
				map[i][t] = map[i - 1][t] + map[i][t];
			}
		}
		for (int j = 1; j < m; j++)
		{ 
			
			if (map[i][j] >= now)
			{
				now = map[i][j+1]; 
				for (int w = nowPoint; w < j; w++)
				{
					if (map[i][w] < maxNum)
					{
						ans += maxNum - map[i][w];
						map[i][w] = maxNum;
						nowPoint = j;
					}
				}

			}
			else if (j == m - 1)
			{
				
				for (int w = nowPoint; w < j; j++)
				{
					if (map[i][w] < maxNum)
					{
						ans += maxNum - map[i][w];
						map[i][w] = maxNum;
						nowPoint = j;
					}
				}
			}
			if (maxNum < map[i][j])
			{
				maxNum = map[i][j+1];
			}

		}
	}



	cout << ans << endl;

}