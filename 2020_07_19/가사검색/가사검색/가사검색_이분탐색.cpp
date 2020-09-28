#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if(a.length() == b.length())
	{
		if (a < b)
			return true;
	}
	return false;
}

vector<int> solution(vector<string> words, vector<string> queries) 
{
	vector<int> answer;
	
	vector<string> rwords = words;
	//rwords ���Ϳ� �ܾ ����� ����
	for (int i = 0; i < words.size(); i++)
		reverse(rwords[i].begin(), rwords[i].end());
	//cmp ���� ����
	sort(words.begin(), words.end(), cmp);
	sort(rwords.begin(), rwords.end(), cmp);

	int len, lo, hi;
	int idx;
	for (string query : queries)
	{
		len = query.length();
		//?�� ���λ翡 �ִ� ���
		if (query[0] == '?')
		{
			reverse(query.begin(), query.end());//Ű���嵵 �������ش�.
			idx = query.find_first_of('?'); 
			for (int i = idx; i < len; i++)
			{
				query[i] = 'a';
			}
			lo = lower_bound(rwords.begin(), rwords.end(), query, cmp) - rwords.begin();
			for (int i = idx; i < len; i++)
			{
				query[i] = 'z';
			}
			hi = upper_bound(rwords.begin(), rwords.end(), query, cmp) - rwords.begin();
		}
		//?�� ���̻翡 �ִ� ���
		else
		{
			idx = query.find_first_of('?');
			for (int i = idx; i < len; i++)
			{
				query[i] = 'a';
			}
			lo = lower_bound(words.begin(), words.end(), query, cmp) - words.begin();
			for (int i = idx; i < len; i++)
			{
				query[i] = 'z';
			}
			hi = upper_bound(words.begin(), words.end(), query, cmp) - words.begin();
		}
		answer.push_back(hi - lo);
	}


	return answer;
}
int main()
{
	solution({ "frodo","front","frost","frozen","frame","kakao" }, { "fro??","????o","fr???","fro???","pro?" });
}