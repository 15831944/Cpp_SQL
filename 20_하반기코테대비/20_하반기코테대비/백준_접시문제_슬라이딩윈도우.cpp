#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*
8 50 4 7
2
7
9
25
7
9
7
30

8 50 4 30
2
7
9
25
7
9
7
30


*/

int n, m, k, c;//접시수,가짓수,연속k,쿠폰
int temp;
int maxNum = -987654312;
int belt[300000];
int kind[3000];
queue<int> window;
int SlidingWindow()
{
	int maxcount;
	int count = 0;
	int temp;
	for (int i = 0; i < k; i++)
	{
		temp = belt[i];
		window.push(temp);
		if (kind[temp - 1] == 0)
			count++;
		kind[temp - 1]++;
	}
	if (kind[c - 1] == 0)
		maxcount = count + 1;
	else
		maxcount = count;

	for (int i = k; i <n + k; i++)
	{
		//맨앞접시제거
		int tempcount = count;
		int front = window.front();
		kind[front - 1]--;
		if (kind[front - 1] == 0)
			tempcount--;
		window.pop();
		//새로운접시추가
		temp = belt[i%n];
		window.push(temp);
		if (kind[temp - 1] == 0)
			count++;
		kind[temp - 1]++;
		if (kind[c - 1] == 0)
			maxcount = max(maxcount, tempcount + 1);
		else
			maxcount = max(maxcount, tempcount);
		count = tempcount;
	}
	return maxcount;
}
int main()
{
	cin >> n >> m >> k >> c;
	for (int i = 0; i < n; i++)
	{
		//cin >> temp;
		//.push_back(temp);
		cin >> belt[i];
	}
	cout << SlidingWindow() << endl;;
	return 0;
}