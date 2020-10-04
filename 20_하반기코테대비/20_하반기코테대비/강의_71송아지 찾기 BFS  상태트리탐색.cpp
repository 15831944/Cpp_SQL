#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
5 14 
*/


using namespace std;
int n, m;
int visit[30]; 
int d[3] = { 1,-1,5 };
void input() {
	queue<int> q;
	cin >> n >> m; 
	q.push(n);
	visit[1] = 1;
	int pos;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			pos = x + d[i];
			if (pos == m)
			{
				cout << visit[x] << endl;
				exit(0);
			}
			if (visit[pos] == 0)
			{
				visit[pos] = visit[x] + 1;
				q.push(pos);
			}
		}

			
		
	}
	
}
void solution()
{

}

int main()
{
	input();

	return 0;
}