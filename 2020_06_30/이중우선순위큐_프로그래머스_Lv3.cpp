#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
 



void sol(vector<string> operations)
{
	
	vector<int> answer;
	list<int> l;
	for (int i = 0; i < operations.size(); i++)
	{
		string str = operations[i];

		//삽입
		if (str[0] == 'I')
		{
			string strNum = "";
			int parseInt;
			for (int j = 2; j < str.size(); j++)
			{
				strNum += str[j];
			}
			parseInt = stoi(strNum);
			l.push_back(parseInt);
		}
		//제거
		else if (str[0] == 'D')
		{
			if (l.empty()) continue;
			if (str[2] == '-')
			{
				l.sort();
				l.pop_front();
			}
			else
			{
				l.sort();
				l.pop_back();
			}
		}
	}
	//string -> int
	//5 , 7 , 10 , 12 ...

	
	while (!l.empty())
	{
		answer.push_back(l.back());
		l.pop_back();
	}

	//cout << "[" << l.back() << "]" << "[" << l.front() << "]";
	
}
void main()
{


	sol({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123" }); //답 : 0,0 
	sol({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" }); // 답 [333, -45]
	cout << " gd " << endl;
	 
	
}