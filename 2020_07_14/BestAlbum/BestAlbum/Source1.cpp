#include<iostream>
#include<vector> 
#include<map> 
#include<algorithm>
using namespace std;

void cmp( pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first)
		true;
	else if (a.first == b.first)
		if (a.second < b.second)
			true;
		else
			false;
	else
		false;

}


vector<int> sol(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	map < string, vector<pair<int, int>>> m;

	for (int i = 0; i < genres.size(); i++)
	{
		//중복x
		if (m.find(genres[i]) == m.end())
		{
			vector<pair<int, int>> v;
			v.push_back({ plays[i],i });
			m.insert({ genres[i],v });

		}
		//중복o
		else
		{
			m[genres[i]].push_back({plays[i],i });
		} 
	}

	vector<string, pair<int, int>> v;
	v.assign(m.begin(), m.end());

	for (int i = 0; i < v.size(); i++)
		sort(v.begin(), v.end(), cmp);





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