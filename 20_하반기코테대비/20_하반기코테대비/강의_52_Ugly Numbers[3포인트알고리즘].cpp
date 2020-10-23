#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int a[1501];
using namespace std;
int main()
{
	int n, p2, p3, p5, min = 2147000000;
	cin >> n;
	a[1] = 1;
	p2 = p3 = p5 = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[p2] * 2 < a[p3] * 3)
			min = a[p2] * 2;
		else min = a[p3] * 3;
		if (a[p5]*5 < min)
			min = a[p5]*5;
		if (a[p2] * 2 == min)
			p2++;
		if (a[p3] * 3 == min)
			p3++;
		if (a[p5] * 5 == min)
			p5++;
		a[i] = min;
			 
	}
	cout << a[n];
	return 0;
}