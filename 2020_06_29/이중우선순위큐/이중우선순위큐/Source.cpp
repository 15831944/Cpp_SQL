#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <string>

using namespace std;
char arr[20][20];
string str;
int n, m;
list<int> l;
vector<string> v;
void sol(vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		string str = v[i];
		 
		//»ðÀÔ
		if (str[0] == 'I')
		{
			string strNum="";
			int parseInt;
			for (int j = 2; j < str.size(); j++)
			{
				strNum += str[j];
			}
			parseInt = stoi(strNum);
			l.push_back(parseInt);
		}
		//Á¦°Å
		else if (str[0] == 'D')
		{
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
	

	
}
void main()
{
	v = { "I 7","I 5","I -5","D -1" };
	sol(v);
	l.sort();
	cout << "[" << l.back() << "]" << "[" << l.front() << "]";
}