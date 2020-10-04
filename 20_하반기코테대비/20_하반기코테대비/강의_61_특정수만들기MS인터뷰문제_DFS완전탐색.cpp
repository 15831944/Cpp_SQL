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
		dfs(Lv + 1, val + a[Lv]); //���ϱ� ���
		path[Lv] = -a[Lv];
		dfs(Lv + 1, val - a[Lv]); //���̳ʽ� ���
		path[Lv] = 0;
		dfs(Lv + 1, val); //���X 
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dfs(0,0); //Lv1����
	if (cnt == 0) cout << "-1" << endl;
	else cout << cnt << endl;
	return 0;
}