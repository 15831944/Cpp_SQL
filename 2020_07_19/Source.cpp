#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[50] = { false,  };
int in = -1;
void dfs(string begin, vector<string> words, int num,string target)
{ 
	if (target== begin)
		return;
	else if (num >= words.size()&& target!=begin)
	{
		in = 100;
		return;
	} 

	int cnt = 0;

	//단어에서 1개만 바뀐것인지 확인하는 로직
	for (int i = 0; i < begin.length(); i++)
	{
		//for (int j = 0; j < words[num].length(); j++)
		//{
			if (begin[i] == words[num][i])
			{
				cnt++;
			}
		//}
	}
	//한개 바뀜
	if (cnt == 2 && visit[num]==false){
		visit[num] = true;
		begin = words[num];
		in++;
		dfs(begin, words, 0,target);
		visit[num] = false;
	}
	else
	{
		dfs(begin, words, num + 1, target);
		visit[num] = false;
		//dfs(begin, words, num + 1, target);
	}
		
	
	
	//끝까지 탐색하는 로직 
	 
}

int solution(string begin, string target, vector<string> words) 
{
	int answer = 100;
	for (int i = 0; i < words.size(); i++)
	{
		dfs(begin, words, i,target);
		answer = min(in, answer);
		in = 0;
	}
	if (answer == 100)
		answer = 0;
	return answer;
}

int main()
{
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log","cog" }) << endl;// hot -> dot -> dog -> log -> cog 
	//cout << solution("hit", "hhh", { "hhh", "hht" }) << endl; //2
	//cout << solution("hit", "zzz", { "aaa" }) << endl;
	//cout << solution("hit", "zzz", { "zz" }) << endl;
	//cout << solution("hit", "zzz", { "zzz", "zyz", "xzz", "xyz", "hyt", "hyz", "xiz", "hiz" }) << endl;// 4 :  hyt -> hyz -> zyz -> zzz //4번


	
}