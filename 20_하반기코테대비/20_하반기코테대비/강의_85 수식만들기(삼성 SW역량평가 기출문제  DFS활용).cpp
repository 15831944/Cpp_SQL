#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int arr[4];
int n;
/*
3
5 3 8
1 0 1 0

*/
vector<int> v,num;
int visit[10];
int op[4];
int maxN = -98876754121;
int minN = 875432123;
void dfs(int cnt, int sum)
{
	if (n== cnt)
	{
		if (sum > maxN)
		{
			maxN = sum;
		}
		if(sum<minN)
			minN = sum;
		return;
	}
	else
	{
		if (op[0] > 0)
		{
			op[0]--;
			dfs(cnt + 1, sum + num[cnt]);
			op[0]++;
		}
		 if (op[1] > 0)
		{
			op[1]--;
			dfs(cnt + 1, sum-num[cnt]);
			op[1]++;
		}
		 if (op[2] > 0)
		{
			op[2]--;
			dfs(cnt + 1, sum * num[cnt]);
			op[2]++;
		}
		 if (op[3] > 0)
		{
			op[3]--;
			dfs(cnt + 1, sum / num[cnt]);
			op[3]++;
		}
	}


	 


}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{ 	
		int t;
		cin >> t;
		num.push_back(t);

	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	} 
	dfs(1,num[0]);

	cout << maxN << endl;
	cout << minN << endl;
	return 0;
}