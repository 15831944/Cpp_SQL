/*
["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
["AA", "AB", "AC", "AA", "AC"]						[1, 3]
["XYZ", "XYZ", "XYZ"]							[1, 1]
["ZZZ", "YYY", "NNNN", "YYY", "BBB"]
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int sum = 0;
int answer = 0;


void dfs(int start, int goal)
{
	if (start == goal)
	{
		answer ++ ;
		return;
	}
	else if (start > goal) 
	{
		return;
	}
	dfs(start + 1, goal);
	dfs(start + 2, goal);
	answer = 1234567 & answer;
}

int solution(int n)
{
	dfs(0, n);
	return answer;
}
int main()
{ 
	solution(15); 
	cout << answer << endl;
	return 0;

}