#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
char arr[20][20];
string str;
void input()
{
	int n, m;
	cin >> n;
	cin >> m;
	//input()
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{	
			arr[i][j] = s[j];
		}
	}

}
void main()
{
	input();
}