#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> answer;
	for (int i = 0; i < queries.size(); i++)
	{
		int cnt =0 ;
		for (int j = 0; j < words.size(); j++)
		{
			int cntStr = 0;
			if (queries[i].size() != words[j].size())
				continue;
			for (int w = 0; w < queries[i].size(); w++)
			{
				
				if (queries[i][w] != words[j][w] && queries[i][w] != '?')
					break;
				else if (queries[i][w] == '?')
					cntStr++;
				else
					cntStr++;
			}
			if (cntStr == queries[i].size())
				cnt++;
	
		}
		cout << cnt << endl;
		answer.push_back(cnt);

	}
	
	return answer;
}

int main()
{
	solution({ "frodo","front","frost","frozen","frame","kakao" }, {"fro??","????o","fr???","fro???","pro?"});
}