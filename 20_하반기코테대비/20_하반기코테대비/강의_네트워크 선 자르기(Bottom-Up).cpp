#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

void solution()
{

}
int dp[100];
int n;
int main()
{
	dp[1] = 1;
	dp[2] = 2;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;

	return 0;
}