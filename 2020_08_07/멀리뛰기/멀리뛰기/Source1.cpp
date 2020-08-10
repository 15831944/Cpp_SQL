#include <string>
#include <vector>

using namespace std;
int dp[2001];

long long solution(int n) {
	long long answer = 0;
	dp[1] = 1; //1,2,3,5,
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		//dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
		dp[i] = (dp[i - 1] + dp[i - 2]) ;
	answer = dp[n];
	return answer;
}
int main()
{
	solution(4);
 
	return 0;

}