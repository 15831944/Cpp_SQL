#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n, m;
vector<int> v;
bool vi[1000];
//cnt 
void dfs(int cnt, int sum,int w)
{
	if (cnt == 3)
	{
		if (sum <=m )
			v.push_back(sum);
		return;
	}
	 
	for (int i = 0; i <n; i++)
	{
		
		if (vi[i] == false)
		{
			vi[i] = true;
			dfs(cnt + 1, sum += v[i],0);
			sum -= v[i];
			vi[i] = false;
		}
	} 
	return;

}
void solution()
{
	dfs(0,0,0);
}

void input()
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp); 
	}
}

int main()
{
	cin >> n >> m;
	input();
	solution();
	int answer = 0;
	sort(v.begin(), v.end());
	answer = v.back();
	cout << answer << endl;
	return 0;
}