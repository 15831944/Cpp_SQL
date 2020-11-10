#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#define MAX 10000 
/*
1 2 3
1 2 1
2 1 3
3 3 3

*/

int r, c, k;
int arr[MAX][MAX];
int arrNum[MAX];
/*bool cmp(pair<int, int> a, pair <int, int> b)
{



}*/
int answer = 0;
vector<pair<int, int>>  InsertFun(vector<pair<int, int>> vv)
{
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size() * 2; i++)
	{
		for (int j = 0; j < vv.size() * 2; j = j + 2)
		{
			for (int w = 0; w < vv.size(); w++)
			{
				arr[i][j] = vv[w].first;
				arr[i][j + 1] = vv[w].second;
			}

		}
	}
	return vv;
}



void Rcal()
{
	int time = 0;
	int hang = 3;
	int yul = 3;
	while (1)
	{
		if (arr[r][c] == k)
		{
			answer = time;//0
			break;
		}
		if (time > 100)
		{
			answer = -1;
			break;
		}
		vector<int> arrSize;
		if (hang >= yul) //행>=열
		{
			for (int i = 1; i <= hang; i++)
			{
				vector<pair<int, int>> v;
				memset(arrNum, 0, sizeof(arrNum));
				for (int j = 1; j <= yul; j++)
				{
					arrNum[arr[i][j]]++;
				}
				for (int j = 1; j < MAX; j++)
				{
					if (arrNum[j] == 0)
						continue;
					else
						//	v.push_back({ j,arrNum[j] });
						v.push_back({ arrNum[j],j });
				}
				sort(v.begin(), v.end());

				for (int j = 1; j <= yul; j++)
				{
					arr[i][j] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++)
				{
					arr[i][idx++] = v[j].second;
					arr[i][idx++] = v[j].first;
				}
				idx--;
				arrSize.push_back(idx);
			}
			sort(arrSize.begin(), arrSize.end());
			yul = arrSize.back();
		}
		else
		{
			for (int i = 1; i <= hang; i++)
			{
				vector<pair<int, int>> v;
				memset(arrNum, 0, sizeof(arrNum));
				//숫자몇개씩들어있는지확인
				for (int j = 1; j <= yul; j++)
				{
					arrNum[arr[j][i]]++;
				}
				//숫자의갯수, 숫자 v에 넣기
				for (int j = 1; j < MAX; j++)
					if (arrNum[j] == 0)
						continue;
					else
						v.push_back({ arrNum[j],j });

				//각각 정렬하기
				sort(v.begin(), v.end());

				for (int j = 1; j <= hang; j++)
				{
					arr[j][i] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++)
				{
					arr[idx++][i] = v[j].second;
					arr[idx++][i] = v[j].first;
				}
				idx--;
				arrSize.push_back(idx);

			}
			sort(arrSize.begin(), arrSize.end());
			hang = arrSize.back();


		}
		//v = InsertFun(v);

		time++;
	}
}

void Ccal()
{

}
int main()
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> arr[i][j];
		}
	}


	if (arr[r][c] == k)
	{
		answer = 0;
		cout << answer << endl;
	}
	Rcal();
	cout << answer << endl;




	return 0;
}