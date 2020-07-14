#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
//#include <functional>

using namespace std;

void sol(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	int answer = 0;
	for (int i = 0; i < A.size(); i++)
	{
		answer += A[i] * B[i];
	}


	cout << answer << endl;
}
int main()
{
	sol({ 1,4,2 }, { 5,4,4 });
}