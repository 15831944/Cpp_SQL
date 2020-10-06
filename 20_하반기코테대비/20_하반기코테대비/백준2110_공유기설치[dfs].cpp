#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n, m;
int home[1000000000] = { 0, };

int maxNum;
int num = -976543321;
int ch[200000];
int minNum = 987654321;
int answer = -987654321;
/*
5 3
1
2
8
4
9
*/
void dfs(int c, int L)
{
	if (L == m)
	{
		vector<int> v;
		//여기에 알고리즘 담기.
		for (int i = 1; i < m; i++)
		{
			for (int j =i-1; j < i; j++)
			{
				int temp = ch[i] - ch[j];
				v.push_back(temp);
				//minNum = 987654321;
				//int temp = ch[i] - ch[j];
				//minNum = min(temp, minNum);
				
			} 

		}
		sort(v.begin(), v.end());
		answer = max(answer, v[0]);
		
		//cout << endl;
	}
	else 
	{
		for (int i = c; i <= maxNum ; i++)
		{
			if (home[i] == 0)
				continue;
			ch[L] = i;
			dfs(i + 1, L + 1);
		}
	}
}
void input()
{
	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		home[num] = 1;
		maxNum = max(num, maxNum);
	}
}
int main()
{
	
	input();
	dfs(0, 0);
	cout << answer << endl;
	return 0;
}