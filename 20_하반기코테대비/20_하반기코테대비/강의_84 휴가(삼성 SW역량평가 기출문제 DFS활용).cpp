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

4일동안 20번다.
2일동안 10번다.
3일동아 15번다...
*/
using namespace std;
int n, res = 24700000;
vector<int> T, P;
void dfs(int L, int sum)
{
	//L==n+1이라는 것은  
	if (L == n + 1)
	{
		if (sum > res)
			res = sum;

	}
	else
	{
		if (L + T[L] <= n + 1)//예외처리 ex) 마지막날이 7일인데 해당날+걸리는날짜 했는데 휴가날을초과한경우 선택불가.
		{
			dfs(L + T[L], sum + P[L]);//해당날짜에 상담을 한다. 
			dfs(L + 1, sum);//상담을 안한다.
		}
	}
}

int main()
{
	int a, b;
	cin >> n;
	T.push_back(0);//0번인덱스 사용X
	P.push_back(0);//0번인덱스 사용X
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		T.push_back(a);//a일동안
		P.push_back(b);//b번다
	}
	dfs(1, 0);
	cout << res;

	return 0;
}