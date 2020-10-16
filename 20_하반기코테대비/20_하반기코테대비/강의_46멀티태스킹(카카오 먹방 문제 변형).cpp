#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

/*
https://wantairpod.tistory.com/121
3
1
2
3
5

*/
void solution()
{

}

int main()
{
	int n,num,k;
	int sum=0;
	vector<int> v;
	cin >> n;
	
	for (int i = 0 ;i < n; i++)
	{
		cin >> num;
		sum += num;
		v.push_back(num);
	}
	//k
	cin >> k;
	int answer = 0;
	//¹®Ç®
	for (int i = 1; i <= sum; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == 0)
				continue;
			else if (v[j] != 0 && i == k)
				answer = j + 1;
			else
			{
				v[j]--;
				break;
			}

		}
	}









	return 0;
}