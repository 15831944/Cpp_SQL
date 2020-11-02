#include <set>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#define MAX_N 2188
/*
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1
*/
using namespace std;

int n;
int paper[MAX_N][MAX_N];
int cnt[3];
//cnt[0]: -1�θ� ä���� ������ ����
//cnt[1] : 0
//cnt[2] : 1
bool same(int x, int y, int n)
{
	for(int i = x ; i< x+n ; i ++)
		for (int j = y; j < y + n; j++)
		{
			if (paper[x][y] != paper[i][j])
				return false;
		}
	return true;//��� ���� paper[x][y] ����.
}
void solve(int x, int y, int n)
{
	//���� ���ڷ� �̷���� ���̶��
	if (same(x, y, n))
	{
		cnt[paper[x][y] + 1] += 1;
		return;
	}

	//�����ϴ� ����
	int m = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			solve(x + i*m, y + j*m, m);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}
	set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(0);
	if (1)
	{
		string temp = "!";
	}
	else if (1)
	{
		string temp2 = "2";
	}

	solve(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;
	return 0;
}