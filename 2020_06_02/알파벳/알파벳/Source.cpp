#include <iostream>
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
char map[1000][1000];
int R, C;
using namespace std;
void input()
{
	cin >> R >> C;
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
}
int main()
{ 
	input();
	
}