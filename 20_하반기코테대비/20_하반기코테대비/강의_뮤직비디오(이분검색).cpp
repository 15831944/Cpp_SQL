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

int rt = 0 ;
int res = 98775431;

int solution(int s)
{
	int sum = 0;
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (sum + a[i] > s)
		{
			cnt++;
			sum = a[i];
		}
		else
		{
			sum += a[i];
		}
	}

	return cnt;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		//cin >> a[i];
		a[i] = i;
		rt += a[i];
	}
	int ll = 1;
 
	int mid = 0;
	
	while (ll <= rt)
	{
		mid = (ll+rt) / 2;
		int sum = 0;
		int cnt = 0;
	

		if (solution(mid) <= m)
		{
			res = mid;
			rt = mid - 1;
		}
		else
		{
			ll = mid + 1;
		}

	}
	cout << res << endl;
	return 0;
}