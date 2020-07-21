#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define MAX_N 10000
using namespace std;
/*
백준문제..
*/

struct Trie
{
	bool finish;
	Trie* next[26];
	Trie() : finish(false)
	{
		memset(next, 0, sizeof(next));
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}

	void insert(const char* key)
	{
		if (*key == '\0')
			finish = true;//문자열이 끝나느 지점...
		else
		{
			int curr = *key - 'A';
			if (next[curr] == NULL)
				next[curr] = new Trie();//탐색이 처음되는 지점일 경우 동적할당
			next[curr]->insert(key + 1); //다음문자 삽입 
		} 
	}
	Trie* find(const char* key)
	{
		if (*key == '\0')return this; //문자열이 끝나는 위치를 반환
		int curr = *key - 'A';
		if (next[curr] == NULL) return NULL;// 찾는 값이 존재하지않음.
		return next[curr]->find(key + 1); //다음문자를탐색 
	}
};

int t, n, r;
char a[MAX_N][11];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		getchar();
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Trie *root = new Trie;
		r = 0;
		for (int i = 0; i < n; i++)
		{
			root->insert(a[i]);
		}
		for(int i = 0 ; i < n ; i ++)
			if (root->find(a[i]))
			{
				r = 1;
			}
		
	}
	return 0;
}