#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
/*
6
1 2 3 4 5 6
2 1 1 1

3
3 4 5
1 0 1 0
*/
 
int n;
int main()
{
	cin >> n;
	vector<int> num;
	vector<int> yeon;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 1; i <=4; i++)
	{
		int tmp;
		cin >> tmp;
	 
		for (int j = 0; j <tmp; j++)
		{
			yeon.push_back(i);
		}
	}
	vector<int> temp;
	int answerMax = -987654321;
	int answerMin = 987654321;
	do
	{
		int cnt = 0;
		int sum =num[cnt++];
		for (int i = 0; i < yeon.size(); i++)
		{
			if (yeon[i] == 1)
			{
				sum += num[cnt++];
			}
			else if (yeon[i] == 2)
			{
				sum -= num[cnt++];
			}
			else if (yeon[i] == 3)
			{
				sum *= num[cnt++];
			}
			else if (yeon[i] == 4)
			{
				sum /= num[cnt++];
			}
			else
			{
				sum = sum;
			}
		}

		temp.push_back(sum);
		answerMax = max(sum, answerMax);
		answerMin = min(sum, answerMin);

	} while (next_permutation(yeon.begin(), yeon.end()));


	cout << answerMax << endl;
	cout << answerMin << endl;
	return 0;
}