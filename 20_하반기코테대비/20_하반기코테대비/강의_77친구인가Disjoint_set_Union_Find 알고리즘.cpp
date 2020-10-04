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

9����ģ�� 7���� ����
������3,8�� ģ���̳�?
*/

using namespace std;

int unf[1001];
// find�Լ� : v��� �л��� ���� ��ȣ�� �������ش�.
// 1���л��� 1, 2���л��� 2, 3���л��� 3
int Find(int v)
{
	
	if (v == unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

//a,b ���� ���չ�ȣ�� ���ؼ� ���� �ٸ��� ���� ���տ� �־��ش�.
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