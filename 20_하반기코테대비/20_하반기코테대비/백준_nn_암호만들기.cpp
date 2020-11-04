#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

/*
4 6
a t c i s w
*/
int n, m;
string arr[15];
bool visit[15];
set<string> s;
void dfs(int cnt, string sum, int num)
{
	if (cnt == n)
	{
		int moCnt = 0;;
		//Á¶°Ç
		for (int i = 0; i < sum.size(); i++)
		{
			if (sum[i] == 'a' || sum[i] == 'e' || sum[i] == 'i' || sum[i] == 'o' || sum[i] == 'u')
				moCnt++;
		}
		if (moCnt >= 1 && n - moCnt >= 2)
			s.insert(sum);
		return;
	}

	for (int i = num; i < m; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(cnt + 1, sum + arr[i], i);
			visit[i] = false;
		}
	}

}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + m);
	dfs(0, "", 0);
	return 0;
}