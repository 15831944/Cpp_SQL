
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100001

using namespace std;

int n, k;
int answer=1;
int ch;
bool visit[MAX];
int tempcnt = 0;
int minN;
int cnt = 0;
bool first = false;
void bfs()
{
	queue<pair<int, int>> q;
	q.push({ n,0 });
	visit[n] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int time = q.front().second;
	
		q.pop();
	
		visit[x] = true; 
		//최초로 찾았을때
		if (!minN&&x == k && first==false)
		{
			minN = time;
			first = true;
			cnt++;
		}
		else if (minN &&x == k && time == minN && first)
		{
			cnt++;
		}
		 
		//int nx = x + 1;
		if (x+1<MAX && !visit[x+1] )
		{
			//visit[x+1] = true;
			q.push({ x+1,time + 1 });
		} 
		if (x - 1 >= 0 && !visit[x-1]  )
		{
			//visit[x-1] = true;
			q.push({ x-1,time + 1 });
		} 
				 
		if (x*2 <= MAX && !visit[x*2] )
		{
			
			//visit[2*x] = true;
			q.push({ 2*x,time + 1 });
		}
			 
		 
	}
}
int main()
{
	cin >> n >> k;
	bfs();
	cout << minN << endl;
	cout << cnt << endl;
	return 0;
}