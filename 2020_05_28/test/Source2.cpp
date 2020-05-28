#include <iostream>
#include <queue>

using namespace std;

struct aaa
{
	int p;
	vector<int> v;
};
aaa ar[10001];
int ans, ans2, a, e, c, d;

void input()
{
	for (int i = 0; i < 10001; i++)
	{
		ar[i].p = 0;
		ar[i].v.clear();
	}
	ans = 0;
	ans2 = 0;
	cin >> a >> e >> c >> d;
	
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		ar[a].v.push_back(b);
		ar[b].p = a;
	}
}

void solve()
{
	vector<int> v[2];
	int x = c;
	while (true)
	{
		if (ar[x].p == 0)
			break;
		v[0].push_back(ar[x].p);
		x = ar[x].p;
	}

	x = d;
	while (true)
	{
		if (ar[x].p == 0)
			break;
		v[1].push_back(ar[x].p);
		x = ar[x].p;
	}

	for (int i = 0; i < v[0].size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < v[1].size(); j++)
		{
			if (v[0][i] == v[1][j])
			{
				ans = v[0][i];
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	queue<int> q;
	q.push(ans);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ans2 += ar[x].v.size();
		for (int i = 0; i < ar[x].v.size(); i++)
			q.push(ar[x].v[i]);
	}
	ans2++;
	cout << ans << "  " << ans2 << endl;
}


void main()
{
	input();
	solve();

}