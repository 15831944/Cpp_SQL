#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> v;

int cnt = 0;
void sol(int n , vector<vector<int>> v)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i <= j)
			{
				continue;
			}
			else
			{
				if (v[i][j] == 1)
				{
					cnt++;
				}
			}
		
		}
	}
}

int main()
{
	v = { {1,1,0}, {1,1,0}, {0,0,1} };
	int n = 3;
	int answer;
	sol(n,v);
	answer = n - cnt;
	cout << answer << endl;
}