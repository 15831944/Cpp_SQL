#include <iostream>

#include <algorithm>

/*
5 3
1
2
8
4
9
*/
using namespace std;
int n, m;
int house[200000];
bool solution(int mid)
{
	int cnt = 1;
	int now = house[0];
	//cout << "mid:" << mid << endl;
	for (int i = 1; i < n; i++)
	{
		if (house[i] - now >= mid)
		{
			cnt++;
			now = house[i];
			//cout << "mid:" << mid << endl;
			//cout <<"now:" <<now << endl;
		}
		//cout << "cnt:" << cnt << endl;

	}
	if (cnt >= m)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> house[i];
	}
	sort(house, house + n);
	//for (int i = 0; i < n; i++)
	//	cout << house[i] << " ";
	//int Left = house[0];
	int Left = 1;
	int mid;
	int right = house[n - 1] - house[0];

	int result = 0;
	//cout <<"right : " <<right << endl;
	while (Left <= right)
	{
		//cout << "Left : " << Left << endl;
		//cout << "right : " << right << endl;
		mid = (Left + right) / 2;

		if (solution(mid))
		{
			result = max(result, mid);
			Left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}

	cout << result << endl;


	return 0;
}