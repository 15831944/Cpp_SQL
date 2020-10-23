#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
/*
3
1234 3412
1000 1
1 16

test
1
1234 3412
LL

*/

using namespace std;

 
int start = 0;
int endnum = 0;
string ans;
void input()
{
	cin >> start;
	cin >> endnum;
}
void bfs(int s)
{
	queue<pair<int, string>> q;
	q.push({ s,"" });
	bool visit[10000] = { false, };
	visit[s] = true;
	while (!q.empty())
	{

		int x = q.front().first;
		string y = q.front().second;
		q.pop();

		if (x == endnum)
		{
			ans = y;
			break;
		}
	
		//D
		int x1= x * 2;
		if (x1 >= 10000)
			x1 = x1 %10000;

		if (!visit[x1])
		{
			visit[x1] = true;
			q.push({x1,y + "D" });
		}

		//S

		int x2;
		if (x == 0)
			x2 = 9999;
		else
			x2 = x - 1;
		if (!visit[x2])
		{
			visit[x2] = true;
			q.push({ x2,y + "S" });
		}

		int x3 = (x % 1000) * 10 + x / 1000;
		if (!visit[x3])
		{
			visit[x3] = true;
			q.push({ x3, y + "L" });
		}
		//R
		int x4 = (x % 10) * 1000 + (x / 10);
		if (!visit[x4])
		{
			visit[x4] = true;
			q.push({ x4, y + "R" });
		}
		  

	}
}
void ini()
{
	start = 0;
	endnum = 0;
	ans = "";
}

int n, m;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ini();
		input();
		bfs(start);
		cout << ans << endl;
	}

	return 0;
}