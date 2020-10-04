#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
4 3
1 3 6 7

1 3 6 7 에서 4C3 을 구하라
*/


using namespace std;
int a[20],res[20],ch[20]; 
int n, r, cnt;
void dfs(int L)
{
	if (L == r)
	{
		for (int j = 0; j < L; j++)
		{
			cout << res[j] << " ";
		}
		cnt++;
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (ch[i] == 0)
			{
				res[L] = a[i];
				ch[i] = 1;
				dfs(L + 1);
				ch[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	dfs(0);
	cout << cnt << endl;
	return 0;
}