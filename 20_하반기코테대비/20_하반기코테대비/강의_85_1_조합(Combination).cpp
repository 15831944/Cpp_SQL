#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
nCr
n개중에 4개를 뽑는 과정 
*/
using namespace std;
int n, r;
int choice[101];
 
void dfs(int c, int L)
{
	if (L == r)
	{
		for (int j = 0; j < r; j++)
		{
			cout << choice[j] << " ";
		}
		cout << endl;
	}
	for (int i = c; i < n; i++)
	{
		choice[L] = i;
		dfs(i + 1, L + 1);
	}
}
 

 
int main()
{
	cin >> n >> r;
	dfs(0,0);
	return 0;
}