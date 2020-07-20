#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[50] = { false, };
 
bool flag = false;
int bfs(string begin, vector<string> words, int num, string target)
{
	int answer = 100;
	queue<pair<string, int>> q;
	q.push({ begin,0 });
	int sizeQueue = 0; 
	int ansNum = 0;
	while(!q.empty())
	{ 
		if (flag == true)
			break; 
		string begin = q.front().first;
		int ansNum = q.front().second;
		q.pop();
		ansNum++;  
		for (int w = 0; w < words.size(); w++)
		{
			int cnt = 0;
			for (int i = 0; i < begin.length(); i++)
			{
				if (begin[i] == words[w][i])
				{
					cnt++;
				}
			} 
			if (cnt == 2 && !visit[w])
			{
				if (words[w] == target)
				{
					flag = true;
					answer = ansNum;
					break;
				}
				visit[w] = true;
				q.push({ words[w],ansNum });
			}
		} 
		sizeQueue = q.size(); 
	}

	return answer;


}

int solution(string begin, string target, vector<string> words)
{
	int answer = 100;
	int in = 100;
	 
	in = bfs(begin, words, 0, target);
	answer = min(in, answer);
	in = 0;
	 
	if (answer == 100)
		answer = 0;
	return answer;
}

int main()
{
	//cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log","cog" }) << endl;// hot -> dot -> dog -> log -> cog 
 	//cout << solution("hit", "hhh", { "hhh", "hht" }) << endl; //2
	//cout << solution("hit", "zzz", { "aaa" }) << endl;
	//cout << solution("hit", "zzz", { "zzz" }) << endl;
	//cout << solution("hit", "zzz", { "zzz", "zyz", "xzz", "xyz", "hyt", "hyz", "xiz", "hiz" }) << endl;// 4 :  hyt -> xiz -> xzz -> zzz //4¹ø



}