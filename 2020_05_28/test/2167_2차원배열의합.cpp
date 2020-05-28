#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, K;
int arr[100][100]; 
int ii, jj, xx, yy;
int flag[100][100] = { 0, };
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

vector<int> v;
queue<pair<int,int>> q;
void input()
{
	cin >> N>> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			
		}
	}
	cin >> K; 
}
void solve()
{
	
	for (int i = 0; i < K; i++)
	{
		int sum = 0;
		memset(flag, 0, sizeof(flag));
		cin >> ii >> jj >> xx >> yy;
		q.push({ ii,jj });
		
		//알고리즘
		sum += arr[ii][jj];
		while (!q.empty())
		{
			int nx = q.front().first;  //2
			int ny = q.front().second; //3
			q.pop();

			if (nx == xx && ny == yy )
			{
				break;
			}
			for (int w = 0; w < 2; w++)
			{
				int nnx = nx + dx[w];
				int nny = ny + dy[w];
				
				if (nnx<=N && nny<=M && flag[nnx][nny] == 0)
				{					
					flag[nnx][nny] = 1;
					sum += arr[nnx][nny];
					//cout << " sum : " << sum <<endl;
					q.push({ nnx,nny });
				}
			}

		}
		cout << sum << endl;
	}
}
void main()
{
	input();
	solve();
}