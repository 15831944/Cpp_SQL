#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;


void main()
{
	map<string, int> m;
	m.insert({ "����", 2 });
	m.insert({ "����", 4 });
	m.insert({ "����", 6 });
	m.insert({ "" , 1 });
	map<string, int> ::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->second << endl;
	}


}
