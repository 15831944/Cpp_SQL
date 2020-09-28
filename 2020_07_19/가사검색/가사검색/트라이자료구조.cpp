#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define MAX_N 10000
using namespace std;
/*
���ع���..
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
			finish = true;//���ڿ��� ������ ����...
		else
		{
			int curr = *key - 'A';
			if (next[curr] == NULL)
				next[curr] = new Trie();//Ž���� ó���Ǵ� ������ ��� �����Ҵ�
			next[curr]->insert(key + 1); //�������� ���� 
		} 
	}
	Trie* find(const char* key)
	{
		if (*key == '\0')return this; //���ڿ��� ������ ��ġ�� ��ȯ
		int curr = *key - 'A';
		if (next[curr] == NULL) return NULL;// ã�� ���� ������������.
		return next[curr]->find(key + 1); //�������ڸ�Ž�� 
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