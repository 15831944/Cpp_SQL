#include <iostream>
#include <vector>

#include <algorithm>


using namespace std;
vector<pair<int, int>> ck;
vector<pair<int, int>> vv;
vector<pair<int, int>> house;
bool visit[13] ;

int answer = 987654321;
int n, m;
int map[50][50];
void dfs(int cnt, int p)
{
	if (cnt == m)
	{
		int suum = 0;
		
		for (int i = 0; i < house.size(); i++)
		{
			int value = 987654321;
			
			
				for (int j = 0; j < vv.size(); j++)
				{
					 
						//answer = min(answer,abs(ck[i].first - house[j].first) + abs(ck[i].second - house[j].second));
						//value =min(value , abs(ck[i].first - house[j].first) + abs(ck[i].second - house[j].second));
						int temp =abs(vv[j].first - house[i].first) + abs(vv[j].second - house[i].second);
						value = min(temp, value); 
				}
				suum += value; 
		}
		if (answer > suum)
		{
			answer = suum;
			return;
		}
		//minhouse.push_back(suum);
		//sort(minhouse.begin(), minhouse.end());
		//answer = minhouse[0];
		//answer = min(answer, suum);
		
	}
	for (int i = p+1; i < ck.size(); i++)
	{
		
		vv.push_back(ck[i]);
		dfs(cnt + 1, i);
		vv.pop_back();
			 
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <n; j++)
		{ 
			cin >> map[i][j]; 
			if (map[i][j] == 1)
			{
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2)
			{
				ck.push_back({ i,j });
			}
		}
	} 
	dfs(0,-1);
	cout << answer << endl;
	return 0;
}