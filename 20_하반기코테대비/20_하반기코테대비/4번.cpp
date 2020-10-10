#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int cnt = 0;

void dfs(string now,string des,string hh, vector<vector<string>> roads,bool check)
{
	if (now == des)
	{
		if (check) 
		{ 
			cnt++;
		} 
		return;
	} 

	
	for (int i = 0; i < roads.size(); i++)
	{
		if (now == roads[i][0])
		{
			if (roads[i][1] == hh)
			{
				check = true;
			}
			now = roads[i][1];
			dfs(now, des, hh, roads,check);
		}
	}

}


int solution(string depar, string hub, string dest, vector<vector<string>> roads)
{
	int answer = -1;
	cnt = 0;
	dfs(depar, dest, hub, roads,false);
	answer= cnt % 10007;
	//cout << answer << endl;
	
	return answer;
}

int main()
{ 
	solution("SEOUL", "DAEGU", "YEOSU", { { "ULSAN", "BUSAN" },{ "DAEJEON", "ULSAN" },{ "DAEJEON", "GWANGJU" },{ "SEOUL", "DAEJEON" },{ "SEOUL", "ULSAN" },{ "DAEJEON", "DAEGU" },{ "GWANGJU", "BUSAN" },{ "DAEGU", "GWANGJU" },{ "DAEGU", "BUSAN" },{ "ULSAN", "DAEGU" },{ "GWANGJU", "YEOSU" },{ "BUSAN", "YEOSU" } });
	solution("ULSAN", "SEOUL", "BUSAN", { {"SEOUL", "DAEJEON"}, {"ULSAN", "BUSAN"}, {"DAEJEON", "ULSAN"}, {"DAEJEON", "GWANGJU"}, {"SEOUL", "ULSAN"}, {"DAEJEON", "BUSAN"}, {"GWANGJU", "BUSAN"} });
	//solution
	return 0;
}