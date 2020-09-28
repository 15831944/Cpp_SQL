#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
bool visit[50] = { false, };

vector<int> v[10];
 
set<string> s;

void  dfs(int num, int N) 
{
	if (num == N) 
	{
		string tmepStr = "";
		for (int i = 0; i < 10; i++)
			if (visit[i] == 1)
			{
				tmepStr += to_string(i);
			}
		s.insert(tmepStr);
		return;
	}

	for (int j = 0; j < v[num].size(); j++) 
	{
		int cur = v[num][j];
		if (visit[cur] == 1) continue;
		visit[cur] = 1;
		dfs(num + 1, N);
		visit[cur] = 0;
	}
 
} 

int solution(vector<string> user_id, vector<string> banned_id)
{
	int answer = 0;
	for (int i = 0; i < banned_id.size(); i++)
	{
		for (int j = 0; j < user_id.size(); j++)
		{

			int cnt = 0;
			int starcnt = 0;
			if (banned_id[i].length() != user_id[j].length())
				continue;
			for (int w = 0; w < banned_id[i].length(); w++)
			{
			
				if (banned_id[i][w] == '*')
				{
					starcnt++;
					continue;
				}
				if (banned_id[i][w] != user_id[j][w])
				{
					break;
				}
				else if( banned_id[i][w] == user_id[j][w])
				{
					cnt++;
				}
			}
			if (user_id[j].length() - starcnt == cnt)
			{
				v[i].push_back(j);
				//visit[j] = true;
			}
		}
	}
	 dfs(0, banned_id.size());
	 answer = s.size();
	return answer;
}
int main()
{
	//solution({ "frodo","fradi","crodo","abc123","frodoc" }, { "fr*d*","abc1**" });
	solution({ "frodo","fradi","crodo","abc123","frodoc" }, { "fr*d*","*rodo","******","******"});
	return 0;
}