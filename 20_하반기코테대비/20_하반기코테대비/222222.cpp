#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;
int mo[13] = {0,0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int solution(int n, vector<string> customers)
{
	int answer = 0;
	//vector<pair<int, int>> arr(customers.size());  //시작시간 , 끝나는시간
	vector<pair<int, int>> arr;
	queue<int> q;
	for (int i = 0; i < customers.size(); i++)
	{
		int cnt = 0;
		string s;
		s = customers[i].substr(0, 2);
		int x = stoi(s);
		s = customers[i].substr(3, 2);
		int y = stoi(s);
		cnt += (mo[x] + mo[y]) * 24 * 60 * 60;

		s = customers[i].substr(6, 2);
		int h = stoi(s);
		s = customers[i].substr(9, 2);
		int m = stoi(s);
		s = customers[i].substr(12, 2);
		int se = stoi(s);
		cnt += (se + m * 60 + h * 3600);
		
		s = customers[i].substr(14);
		int wo = stoi(s);

		//q.push(cnt + wo * 60);
		arr.push_back({ cnt,cnt + wo * 60  });
	 
	}


	

	vector<vector<int>> ko(n); //끝나는시간

	for (int i = 0; i < arr.size(); i++)
	{
		int max = -99999999;
		int mi;
		bool chk = false;
		for (int j = 0; j < n; j++)
		{
			if (ko[j].empty())
			{
				ko[j].push_back(arr[i].second);
				chk = true;
				break;
			}

			int temp = arr[i].first - ko[j].back();
			if (temp > max)
			{
				max = temp;
				mi = j;
			}
		}

		if (!chk)
		{
			ko[mi].push_back(arr[i].second);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (answer < ko[i].size())
		{
			answer = ko[i].size();
		}
	}

	return answer;
}
int main()
{
	solution(3, { "10/01 23:20:25 30", "10/01 23:25:50 26", "10/01 23:31:00 05", "10/01 23:33:17 24", "10/01 23:50:25 13", "10/01 23:55:45 20", "10/01 23:59:39 03", "10/02 00:10:00 10" });
	return 0;
}