#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include <set>

using namespace std;

int solution(int k, vector<int> score)
{
	int answer = -1;
	vector<int> v;
	vector<int> cntV;
	set<int> s;
	for (int i = 1; i <= score.size(); i++)
	{
		s.insert(i);
	}
	for (int i = 0; i < score.size()-1; i++)
	{
		int j = i + 1;
		v.push_back(score[i] - score[j]);
		
	}
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[i] == v[j])
				cnt++;
		}
		if(cnt>=k)
			cntV.push_back(i);
	}

	for (int i = 0; i < cntV.size(); i++)
	{
		int temp1 = 0;
		int temp2 = 0;
		temp1 = cntV[i] + 1;
		temp2 = cntV[i] + 2;
		if (s.find(temp1) != s.end())
			s.erase(temp1);
		if (s.find(temp2) != s.end())
			s.erase(temp2);
	}
	answer = s.size();
	return answer;
}

int main()
{
	cout << solution(3, { 24,22,20,10,5,3,2,1 }) << endl;
	cout << solution(2, { 1300000000, 700000000, 668239490, 618239490, 568239490, 568239486, 518239486, 157658638, 157658634, 100000000, 100 }) << endl;
	return 0;
}