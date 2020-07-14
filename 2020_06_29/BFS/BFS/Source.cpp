#include <iostream>
#include <queue>
#include <string>

using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool as()
{
	queue<pair<int,int>> q;
	bool answer= false; 
	string arr[12][6];
	bool visit[12][6];
	q.push({ 11,0 });
	string temp;
	int cnt =0 ;
	while (!q.empty())
	{
	
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++)
		{
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (arr[nx][ny] == temp)
			{
				cnt++;
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}

		}

	}
	if (cnt >= 3)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (visit[i][j] == true)
				{
					arr[i][j] == ".";

				}
			}
		}
		answer = true;
	}
	return answer;
}

int main() {
	return 0;
}