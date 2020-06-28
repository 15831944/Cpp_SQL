#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;


void main()
{
	map<string, int> m;
	m.insert({ "ぞし", 2 });
	m.insert({ "ぉし", 4 });
	m.insert({ "けし", 6 });
	m.insert({ "" , 1 });
	map<string, int> ::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->second << endl;
	}


}
