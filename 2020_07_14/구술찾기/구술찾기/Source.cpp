//SOL ����.

#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int check[100] = { 0, };
int checkMin[100] = { 0, };
int answer = 0;
vector<pair<int, int>> v;
void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int first, second;
		cin >> first >> second;
		v.push_back({ first,second });
	}
}
void sol()
{
	int checkNum;
	for (int i = 0; i < m; i++)
	{
		check[v[i].first]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i] >= (n / 2))
		{
			checkNum = i;


			for (int j = 0; j < m; j++)
			{
				//if 4�϶� ���ڸ��� 
				if (v[j].first == checkNum)
				{
					// v[i].second 3��2�� frist�� �ִ��� üũ 
					for (int w = 0; w < m; w++)
					{
						//���� 3�Ǵ�2�� first�� �ִٸ� check[3]��++���ش�.
						if (v[j].second == v[w].first)
						{
							check[checkNum]++;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		checkMin[v[i].second]++;
	}  
	for (int i = 1; i <= n; i++)
	{
		if (checkMin[i] >= (n / 2))
		{
			checkNum = i; 
			for (int j = 0; j < m; j++)
			{
				//if 4�϶� ���ڸ��� 
				if (v[j].second == checkNum)
				{
					// v[i].second 3��2�� frist�� �ִ��� üũ 
					for (int w = 0; w < m; w++)
					{
						//���� 3�Ǵ�2�� first�� �ִٸ� check[3]��++���ش�.
						if (v[j].first == v[w].second)
						{
							checkMin[checkNum]++;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i < n; i++)
	{

		if (check[i] >= (n / 2) || checkMin[i] >= n/2)
		{
			answer++;
		}
		
	}
	cout << answer << endl;
}
int main()
{
	input();
	sol();
	return 0;
}