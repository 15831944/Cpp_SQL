#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;
int cnt = 0;
bool vi[200] = { false, };
bool vi2[200] = { false, };
vector<int> v;
void per(int cnt, int num, vector<int> arr)
{
	if (cnt == 3)
	{
		int sum = 0;
		bool check = false;
		for (int i = 0; i < v.size(); i++)
		{ 
			sum += v[i];
		} 
		//cout << sum << endl;
		for (int i =2; i < sum; i++)
		{ 
			if (sum % i == 0)
			{
				check = true; 
				break;
			}

		}
		if (check == false)
		{
			vi2[sum] = true;
 			//cout << sum << endl;
		} 
	}
	for (int w = num; w < arr.size(); w++)
	{
		if (!vi[w])
		{
			vi[w] = true;
			v.push_back(arr[w]);
			per(cnt + 1, w, arr);
			v.pop_back();
			vi[w] = false;
		}
	}
}
int sol(vector<int> arr)
{
	int answer = 0;
	per(0, 0,arr);
	for (int i = 0; i < 200; i++)
	{
		if (vi2[i] == true)
		{
			answer++;
		}
	}
	cout << answer << endl;
	return answer;
}
int main()
{
	sol({ 1,2,7,6,4 });
	return 0;
}