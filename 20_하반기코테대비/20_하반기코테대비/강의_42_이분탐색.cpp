#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
 
/*
8 32
23 87 65 12 57 32 99 81

해당 수열을 오름차순으로 정렬하고 32가 몇 번째 있는지
ANSWER = 3
*/
int main()
{
	int n, i, key, lt = 0, rt, mid;
	cin >> n >> key;
	vector<int>a(n);
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	rt = n;
	while (lt <= rt)
	{
		mid = (lt + rt) / 2;
		if (a[mid] == key)
		{
			cout << mid + 1;
			return 0;
		}
		else if (a[mid] > key)
			rt = mid - 1;
		else if (a[mid] < key)
			lt = mid + 1;
	}

	return 0;
}