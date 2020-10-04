#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n, total = 0;
int a[100];
bool flag = false;
void dfs(int L, int sum)
{
	if (flag == true) return;
	if (L == n + 1)
	{
		if ( sum == (total - sum))
			flag = true;
	}
	else
	{
		dfs(L+1, sum += a[L]);
		dfs(L+1, sum);
			
	}
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	
}
int main()
{
	input();
	dfs(1, 0);
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}