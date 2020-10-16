



#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
입력 : 9 3
1,2,3,4,5,6,7,8,9
9개의 앨범을 3개로 나눌 때 가장 작은 dvd 용량
*/
using namespace std;
int n, m;
int a[1001];

int rt = 0;
int res = 98775431;

long long solution(int n, vector<int> times)
{
	long long answer = 0;
	int mid = 0;
	int ll = 1;

	int rr = times[0];

	while (ll <= rr)
	{
		mid = (ll + rr) / 2;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < times.size(); i++)
		{
			int temp = 0;
			sum += mid / times[i];
		}
		if (sum < n)
		{
			rr = mid - 1;
		}
		else if (sum > n)
		{
			ll = mid + 1;
		}
		if (sum == n)
		{
			answer = mid;
			break;
		}
	}
	return answer;
}
int main()
{
	solution(6, { 7, 10 });
	return 0;
}