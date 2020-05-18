#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int map[16][16];
bool vi[16];
int n, ans;
vector<int> v;

void input()
{
	ans = 987654321;
	memset(map, 0, sizeof(map));
	memset(vi, false, sizeof(vi));
	v.clear();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
}

void pro(int ct, int num)
{
	if (ct == n / 2)
	{
		vector<int> nv;
		for (int w = 0; w < n; w++)
		{
			if (!vi[w])
				nv.push_back(w);
		} 
		return;
	}

	for (int w = num; w < n; w++)
	{
		if (!vi[w])
		{
			vi[w] = true;
			v.push_back(w);
			pro(ct + 1, w);
			v.pop_back();
			vi[w] = false;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		input();
		pro(0, 0);
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}
