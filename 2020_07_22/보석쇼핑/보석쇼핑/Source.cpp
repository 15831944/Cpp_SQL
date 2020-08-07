/*
["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
["AA", "AB", "AC", "AA", "AC"]						[1, 3]
["XYZ", "XYZ", "XYZ"]							[1, 1]
["ZZZ", "YYY", "NNNN", "YYY", "BBB"]	
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
vector<int> solution(vector<string> gems) 
{
	vector<int> answer = { 0, 0 };
	queue<string> q;
	map<string, int> m;
	int gems_size = 0, start = 0, end = 1000001, tmp = 0;

	for (auto i : gems)
		m[i] = 1;

	gems_size = m.size();
	m.clear();

	for (int i = 0; i < gems.size(); i++)
	{
		if (m[gems[i]] == 0)
			m[gems[i]] = 1;
		else
			m[gems[i]] += 1;
		q.push(gems[i]);

		while (1)
		{
			if (m[q.front()] > 1)
			{
				m[q.front()] -= 1;
				q.pop();
				tmp++;
			}
			else
				break;
		}

		if (m.size() == gems_size && end > q.size())
		{
			end = q.size();
			start = tmp;
		}
	}

	answer[0] = start + 1;
	answer[1] = start + end;
	return answer;
}

int main()
{

	//solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	solution({ "AA", "AB", "AC", "AA", "AC" });

	return 0; 

}