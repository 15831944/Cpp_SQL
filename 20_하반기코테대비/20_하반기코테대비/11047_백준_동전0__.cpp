#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
*/
using namespace std;

void solution()
{

}
int n, m;
vector<int> v;
int main()
{
	solution();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp > m)
			continue;
		v.push_back(tmp);
	} 
	sort(v.rbegin(), v.rend());
	int num = 0;
	int sum = 0;
	int cnt = 0;
	while (1)
	{
		if (sum == m)
			break;
		if (sum < m)
		{
			cnt++;
			sum += v[num];
		
		}
		else
		{
			sum -= v[num];
			num++;
			cnt--;
		}
	}


	cout << cnt << endl;

	return 0;
}