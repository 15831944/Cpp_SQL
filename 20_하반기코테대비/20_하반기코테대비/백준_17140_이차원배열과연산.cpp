
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>


using namespace std;
int a, r, k;
//int map[500][500];
int n;
vector<vector<int>> arr(500,vector<int>(500,0));
//vector<int> map[501];
int maxNumGa = 0;
int maxNumSe = 0;

bool cmp(pair<int,int> x, pair<int,int> y)
{
	if (x.second < y.second)
		return true;
	else if (x.second > y.second)
		return false;
	else if (x.second == y.second)
		if (x.first < y.first)
		return true;
}
void Rowcal()
{
	
	for (int i = 0; i < maxNumGa; i++)
	{ 
		map<int, int> Row;
		if (Row.empty())
			Row[arr[i][0]] = 1; 
		for (int j = 1; j < maxNumGa; j++)
		{ 
			if (Row.find(arr[i][j]) != Row.end())
			{
				Row[arr[i][j]]++;
			}
			else
			{
				Row[arr[i][j]] = 1;
			}
		}
		vector<pair<int, int>> vec(Row.begin(), Row.end());

		sort(vec.begin(), vec.end(), cmp);
		int sum = 0;
		 
	}

}
void Colcal()
{

}

bool CheckLanth()
{
	
	
	//가로 가장 긴 것 
	for (int i = 0; i < arr.size(); i++)
	{ 
		int cnt = 0;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] != 0)
				cnt++;
			else
				break;
	
		}
		if (maxNumGa < cnt)
			maxNumGa = cnt;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[j][i] != 0)
				cnt++;
			else
				break;
		
		}  
		if (maxNumSe < cnt)
			maxNumSe = cnt;
	}
	if (maxNumGa >= maxNumSe)
		return true;
	else
		return false;
	
}
int main()
{
	int time = 0;
	cin >> a >> r >> k;
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++) 
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
			
		}
	}
	//길이체크함수.

	while (time++ < 100)
	{
		maxNumGa = 0;
		maxNumSe = 0;
		//행이 더 길 경우
		if (CheckLanth())
		{
			Rowcal();
		}
		//열이 더 길 경우 
		else
		{

		}
	}



	return 0;
}