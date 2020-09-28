#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
 
/*

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