
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 50
/*
2 20 50
50 30
20 40

4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
*/


using namespace std;


int n;
int l, r;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool checkF = true;

void bfs(int x, int y) 
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> Nq;
	visit[x][y] = true;
	q.push({ x,y });
	Nq.push({ x,y });
	bool check2 = false;
	int cnt = 1;
	int sum = arr[x][y];
 
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for(int w= 0 ; w< 4; w++)
		{
			int nx = xx + dx[w];
			int ny = yy + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visit[nx][ny])
				continue;
			if (abs(arr[xx][yy] - arr[nx][ny]) >= l &&abs(arr[xx][yy] - arr[nx][ny]) <= r)
			{
				 
				visit[nx][ny]=true;
				//visit[x][y] = true;
				cnt++;
				q.push({ nx, ny });
				Nq.push({ nx,ny });
				sum += arr[nx][ny];
				checkF = true;
				check2 = true;
			}
		}
	}
	
	 
		int newPeople = sum / cnt;
		//cout << newPeople << endl;
		//cout << sum << endl;
		//cout << cnt << endl;
	
		while (!Nq.empty())
		{
			int x = Nq.front().first;
			int y = Nq.front().second;
			Nq.pop();
			arr[x][y] = newPeople;
		}
	 

}
bool Can_Combination2(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (l <= abs(arr[x][y] - arr[nx][ny]) && abs(arr[x][y] - arr[nx][ny]) <= r)
				return true;
		}
	}
	return false;
}



int main()
{
	cin >> n >> l>> r;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int answer = 0;
	while (checkF)
	{
		
		checkF = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j] && Can_Combination2(i, j))
				{
					bfs(i, j);
					checkF = true;
				}
			}
		}
		
		if (checkF)
		{
			answer++;
		}
		memset(visit, false, sizeof(visit));
	
		
	}
	cout << answer << endl;
	return 0;
}