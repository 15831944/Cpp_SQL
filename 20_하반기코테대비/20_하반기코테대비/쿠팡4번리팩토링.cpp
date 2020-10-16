#include <iostream>
#include <vector>
using namespace std;


string m_hub;
string m_dest;
vector<vector<string>> m_roads;
int cnt;

void dfs(string depar, bool check)
{
	if (depar == m_dest)
	{
		if (check)
			cnt++;
		return;
	}
	for (int i = 0; i < m_roads.size(); i++)
	{
		if (m_roads[i][0] == depar)
		{
			depar = m_roads[i][1];
			if (depar == m_hub)
				check = true;
			dfs(depar, check);
		}
	}
}
int solution(string depar, string hub, string dest, vector<vector<string>> roads)
{
	int answer = -1;
	m_hub = hub;
	m_dest = dest;
	m_roads = roads;
	dfs(depar, false);
	cout << cnt << endl;
	return answer;
}
int main()
{
	solution("SEOUL", "DAEGU", "YEOSU", { { "ULSAN", "BUSAN" },{ "DAEJEON", "ULSAN" },{ "DAEJEON", "GWANGJU" },{ "SEOUL", "DAEJEON" },{ "SEOUL", "ULSAN" },{ "DAEJEON", "DAEGU" },{ "GWANGJU", "BUSAN" },{ "DAEGU", "GWANGJU" },{ "DAEGU", "BUSAN" },{ "ULSAN", "DAEGU" },{ "GWANGJU", "YEOSU" },{ "BUSAN", "YEOSU" } });
}