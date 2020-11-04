#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

/*
3
10
20
1000

1
0
1
*/
int Tri[45];
int n;
vector<int> test;
bool check = false;
void dfs(int des, int cnt, int sum)
{
	if (cnt == 3)
	{
		if (des == sum)
		{
			check = true;
			cout << "1" << endl;
		}

		return;
	}

	for (int w = 0; w < 45; w++)
	{
		if (Tri[w] < des)
		{
			dfs(des, cnt + 1, sum + Tri[w]);

		}
		if (check)
			break;
	}
}

int main()
{
	Tri[0] = 1;
	Tri[1] = 3;
	int cnt = 3;
	for (int i = 2; i < 45; i++)
	{
		Tri[i] = Tri[i - 1] + cnt;
		cnt++;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		test.push_back(temp);

	}
	for (int i = 0; i < test.size(); i++)
	{
		check = false;
		dfs(test[i], 0, 0);
		if (!check)
			cout << "0" << endl;
	}
	return 0;
}