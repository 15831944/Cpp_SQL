#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
7
4 20
2 10
3 15
3 20
2 30
2 20
1 10

4�ϵ��� 20����.
2�ϵ��� 10����.
3�ϵ��� 15����...
*/
using namespace std;
int n, res = 24700000;
vector<int> T, P;
void dfs(int L, int sum)
{
	//L==n+1�̶�� ����  
	if (L == n + 1)
	{
		if (sum > res)
			res = sum;

	}
	else
	{
		if (L + T[L] <= n + 1)//����ó�� ex) ���������� 7���ε� �ش糯+�ɸ��³�¥ �ߴµ� �ް������ʰ��Ѱ�� ���úҰ�.
		{
			dfs(L + T[L], sum + P[L]);//�ش糯¥�� ����� �Ѵ�. 
			dfs(L + 1, sum);//����� ���Ѵ�.
		}
	}
}

int main()
{
	int a, b;
	cin >> n;
	T.push_back(0);//0���ε��� ���X
	P.push_back(0);//0���ε��� ���X
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		T.push_back(a);//a�ϵ���
		P.push_back(b);//b����
	}
	dfs(1, 0);
	cout << res;

	return 0;
}