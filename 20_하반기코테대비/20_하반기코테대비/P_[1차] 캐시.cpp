#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>


using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	list<string> l;
	vector<string> citi;
 
	for (int i = 0; i<cities.size(); i++)
	{
		string tempStr =""; 
		for (int j = 0; j < cities[i].size(); j++)
		{ 
			tempStr += tolower(cities[i][j]); //소문자를 대문자로 교환.}
		} 
		citi.push_back(tempStr); 
	}
	  
	for (int i = 0; i < citi.size(); i++)
	{
		list<string> :: iterator  iter; 
		if (cacheSize == 0)
		{
			answer += cities.size() * 5;
			break;
		} 
		iter = find(l.begin(), l.end(), citi[i]);
 
		//없다.
		if (iter == l.end())
		{ 
			l.push_back(citi[i]);
			answer += 5;
		}
		//있다
		else
		{
			l.erase(iter);
			l.push_back(citi[i]);
			answer += 1;
		} 
		if (l.size() > cacheSize)
			l.pop_front();
	} 
	return answer;
}

int main()
{
	cout << solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" }) << endl; //15+3+3 = 21
	cout << solution(5,{ "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << endl;
	return 0;
}

