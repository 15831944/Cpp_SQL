#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int visit[100] = { 0, };
int arr[100];

set<string> s; 
int bSize, uSize;
vector<int> t;
string ban, user;
int qq = 0;
void dfs(int cnt, vector<string> user_id, vector<string> banned_id)
{

	

	if (cnt == banned_id.size())
	{
		string tmp;
		for (int i = 0; i < t.size(); i++)
		{
			tmp += t[i];
		}
		s.insert(tmp);
		t.clear();
		return;
	}
	 
 

		for (int j = 0; j < uSize; j++)
		{
			if (visit[j] == 1) continue;
			int ct = 0;
			
			if (banned_id[qq].size() != user_id[j].size())
				continue;
			for (int w = 0; w < banned_id[qq].size(); w++)
			{
				if (banned_id[qq][w] == '*')
				{
					ct++;
				}
				else if (banned_id[qq][w] == user_id[j][w])
				{
					ct++;
				}
			}
			int tempp = banned_id[qq].size();
			if ( ct == banned_id[qq].size())
			{
				t.push_back(j);
				visit[j] = 1;
				qq++;
				dfs(cnt + 1, user_id, banned_id );
				qq--;
				visit[j] = 0;
			}
		}
	
 
}
int solution(vector<string> user_id, vector<string> banned_id) 
{
	int answer = -987655;
	uSize = user_id.size();
	bSize = banned_id.size();

	dfs(0,user_id, banned_id);
	
	return answer;

}
int main()
{
	solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" });
	int answer = -9898771;

	return 0;
}