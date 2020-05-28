#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int n,num;
set<int> s;
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s.insert(num);
	}
	
	cout << s.size(); 
	
	
}
void main()
{
	input();
}