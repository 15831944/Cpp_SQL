#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n, m;
int cnt;
int a[11],path[11];
void dfs(int Lv, int val)
{
	if (Lv == n )
	{
		if (val == m)
		{
			cnt++;
			for (int i = 0; i < Lv; i++)
			{
				cout << path[i] << " ";
				 
			}
			cout << endl;
		}
	}
	else
	{
		path[Lv] = a[Lv];
		dfs(Lv + 1, val + a[Lv]); //더하기 사용
		path[Lv] = -a[Lv];
		dfs(Lv + 1, val - a[Lv]); //마이너스 사용
		path[Lv] = 0;
		dfs(Lv + 1, val); //사용X 
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dfs(0,0); //Lv1시작
	if (cnt == 0) cout << "-1" << endl;
	else cout << cnt << endl;
	return 0;
}