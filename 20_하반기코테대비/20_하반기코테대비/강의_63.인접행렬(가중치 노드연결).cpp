#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n, m;
int map[100][100];
int a, b, c;
/*
https://wantairpod.tistory.com/105
*/
void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
			
		}
		cout << endl;
	}
}

int main()
{
	input();
	return 0;
}