#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


/*
9 7
1 2
2 3
3 4
1 5
6 7
7 8
8 9
3 8

9명의친구 7개의 간선
마지막3,8이 친구이냐?
*/

using namespace std;

int unf[1001];
// find함수 : v라는 학생의 집합 번호를 리턴해준다.
// 1번학생은 1, 2번학생은 2, 3번학생은 3
int Find(int v)
{
	
	if (v == unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

//a,b 둘의 집합번호를 구해서 만약 다르면 같은 집합에 넣어준다.
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main()
{ 
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		Union(a, b);
	}
	cin >> a >> b;
	a = Find(a);
	b = Find(b);
	if (a == b) cout << "YES";
	else cout << "NO";
 

	return 0;
}