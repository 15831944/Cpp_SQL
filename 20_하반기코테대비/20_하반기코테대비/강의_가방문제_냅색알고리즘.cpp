#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
/*
4 11
5 12
3 8
6 14
4 8
´ä : 28

*/
int main()
{
	int n, m, w, v;
	cin >> n >> m;
	vector<int> dy(m+1,0);
	for (int i = 0; i < n; i++)
	{
		cin >> w >> v; 
		for (int j = w; j <= m; j++)
		{
			dy[j] = max(dy[j], dy[j - w] + v);
		}
	}
	cout << dy[m]; 
	
	return 0;
}