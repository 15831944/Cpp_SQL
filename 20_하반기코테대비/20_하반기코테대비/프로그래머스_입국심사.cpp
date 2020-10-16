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
 
int res = 98775431;

long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());
	long long temp = n;
	long long answer = 0;
	long long mid = 0;
	long long ll = 1;
	long long rr = times[0] * temp ;
	long long sum = 0;
 

	while (ll <= rr)
	{
		mid = (ll + rr) / 2;
		
		long long cnt = 0;
		for (int i = 0; i < times.size(); i++)
		{
			
			cnt += mid / times[i];
		} 

		if (cnt >= n)
		{ 
			rr = mid - 1;
			answer = mid;
		}
		else  
		{
			ll = mid + 1;
		} 
	}
	return answer;
}
int main()
{
	cout << solution(6, { 7, 10 }) << endl;
	
	return 0;
}