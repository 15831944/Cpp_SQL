#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt = 0;
bool visit[10000];
void DFS(string start, vector<vector<string>>& tickets, vector<string>& answer, vector<string>& temp, int cnt) 
{
	
	temp.push_back(start);

	if (max_cnt < cnt) 
	{
		max_cnt = cnt;
		answer = temp;
	}

	for (int i = 0; i < tickets.size(); i++) 
	{
		if (start == tickets[i][0] && !visit[i])
		{
			visit[i] = true;
			DFS(tickets[i][1], tickets, answer, temp, cnt + 1);
			visit[i] = false;
		}
	}
	temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) 
{
	int cnt = 0;
	vector<string> answer, temp;
	 
	sort(tickets.begin(), tickets.end());
	DFS("ICN", tickets, answer, temp, cnt);
	return answer;
}


int main()
{
	//solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
	solution({ { "ICN", "SFO" },{ "ICN", "ATL" },{ "SFO", "ATL" },{ "ATL", "ICN" },{ "ATL","SFO" } });
 
	return 0;
}