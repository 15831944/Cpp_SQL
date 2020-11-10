
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 10000


using namespace std;
bool visit[MAX];
vector<string> answer;
vector<string> NaviSave;
void dfs(string st, string de, vector<vector<string>> tickets,int cnt,char Navi)
{
	
	if (cnt == tickets.size())
	{

		//cout << Navi << endl;
		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{ 
		if (de == tickets[i][0])
		{
			if (!visit[i])
			{ 
				visit[i] = true; 
				char temp = i - '0';
				cout << temp << endl;
				dfs(tickets[i][0], tickets[i][1], tickets, cnt + 1, Navi+temp);
				visit[i] = false;
			}
		}
	}

}

vector<string> solution(vector<vector<string>> tickets) 
{

	for (int i = 0; i < tickets.size(); i++)
	{
		string start = tickets[i][0];
		string des = tickets[i][1];
		if (start == "ICN")
		{
			visit[i] = true;
			char tempStr = i - '0';
			
			dfs(start,des,tickets,1, tempStr);
			
			visit[i] = false;
		}
		//answer.clear();
	}
	return answer;
}

int main()
{
	//solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
	solution({ { "ICN", "SFO" },{ "ICN", "ATL" },{ "SFO", "ATL" },{ "ATL", "ICN" },{ "ATL","SFO" } });
	
	
	for (int i = 0; i < NaviSave[0].size(); i++)
	{
		for (int j = i; j < i + 3; j++)
		{ 
			string temp = NaviSave[0];
			
		}
	}
	return 0;
}