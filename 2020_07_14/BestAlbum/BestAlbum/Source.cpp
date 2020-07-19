
#include<iostream>
#include<vector> 
#include<map> 
#include<algorithm>
#define PP pair<int,int>

using namespace std;
bool cmp(PP a, PP b)
{
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool cmp2(pair<string, vector<pair<int, int>>> a, pair<string, vector<pair<int, int>>> b)
{
	if (a.second[0].second > b.second[0].second)
		return true;
	else
		return false;
}

vector<int> sol(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	map<string, vector<pair<int, int>>> m;
	for (int i = 0; i < genres.size(); i++)
	{ 
		//중복X : 키 값이 중복이 아니면 입력
		if (m.find(genres[i]) == m.end())
		{
			vector<pair<int, int>> v;
			v.push_back({ i,plays[i] });
			m.insert({ genres[i],v });

		}
		//중복O : 키 값이 중복이면 value값을 sum한다.
		else
		{ 
			m[genres[i]].push_back({ i,plays[i] }); // 중요!

		}
	}
	//map -> vector
	vector<pair<string, vector<pair<int, int>>>> v;
	v.assign(m.begin(), m.end());

	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < v[i].second.size(); j++)
		{
			cnt += v[i].second[j].second;//갯수 합치기

		}
		v[i].second.push_back({ cnt,cnt });//빈공백에 그냥 cnt넣기
	}

	for (int i = 0; i < v.size(); i++)
	{
		sort(v[i].second.begin(), v[i].second.end(), cmp);
	}

	sort(v.begin(), v.end(),cmp2);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].second.size(); j++)
		{
			if (v[i].second[j].first == v[i].second[j].second)
				continue;
			answer.push_back(v[i].second[j].first);
			//앞에서 두개까지만
			if (j == 2)
				break;
		}
	}

	return answer;
 
}


int main()
{
	/*
		c 500 0
		p 600 1
		c 150 2
		p 800 3
		c 1500 4 
		answer : 4 1 3 0 
	*/ 
	sol({ "classic", "pop","classic","pop","classic" }, { 500,600,150,800,2500 });
	return 0;
}