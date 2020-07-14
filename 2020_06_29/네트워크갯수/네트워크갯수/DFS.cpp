#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//dfs
bool flag[200];
 
bool dfs(vector<vector<int>>& v, int n)
{
	if (v[n][n]==0) return false;
	v[n][n] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		//v[0][0]~[0][2] 
		if (v[n][i]==1)
			/*
			
			*/
			dfs(v, i);
	}
}
void sol(int n, vector<vector<int>> v)
{
	int answer =0;
	for (int i = 0; i < n; i++)
	{
		if (v[i][i]==1 && dfs(v, i))
		{
			answer++;
		}
	}
	
}

int main()
{
	/*
	110
	110
	001

	110
	111
	011
	*/
	vector<vector<int>> v;
	sol(3, {{ 1,1,0 },{ 1,1,0 },{ 0,0,1 }});
	sol(3, { { 1,1,0 },{ 1,1,1 },{ 0,1,1 } });
}