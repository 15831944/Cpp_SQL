#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

int n, m;
vector<int> v;
int main()
{
	cin >> n >> m;
	while (n > 0)
	{
		int namerge = n%m;
		n = n / m;
		v.push_back(namerge);
	}
	string tm;
	while (!v.empty())
	{
		int temp = v.back();
		tm += to_string(temp);
		v.pop_back();
	}
	int answer = stoi(tm);
	cout << answer << endl;
	return 0;
}