#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//dfs


  
int sol(int n, vector<vector<int>> computers)
{
	int answer = 0;
	vector<int> v[200];
	bool vi[200] = { false,0 };
	for (int i = 0; i < computers.size(); i++)
	{
		for (int j = 0; j < computers[i].size(); j++)
		{
			if (computers[i][j] == 1)
			{
				v[i].push_back(j);
			}
		 }
	}
	for (int i = 0; i < n; i++)
	{
		if (v[i].size() == 0)
		{
			continue;
		}
		if (vi[i])
		{
			continue;
		}
		queue<int> q;
		q.push(i);
		vi[i] = true;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();

			for (int w = 0; w < v[x].size(); w++)
			{
				if (!vi[v[x][w]]) // false이면 즉 경로 방문안헀으면
				{
					vi[v[x][w]] = true;
					q.push(v[x][w]);
				}
			}
			
		}
		answer++;
	}
	return answer; 

}

int main()
{ 
	vector<vector<int>> computers;
	sol(3, { { 1,1,0 },{ 1,1,0 },{ 0,0,1 } });
	sol(3, { { 1,1,0 },{ 1,1,1 },{ 0,1,1 } });
}