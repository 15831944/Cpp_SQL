#include <iostream>
#include <map>

using namespace std;


int main()
{
	map<int, int> m;
	m.insert({ 1,2 });
	map<int, int> ::iterator it = m.find(1);
	if (it != m.end())
	{
		it->second = 100;
	}
	m.insert({ 1,3 });
	m.insert({ 1,4 });
	m.insert({ 1,5 });
	m.insert({ 1,6 });
	m.insert({ 1,7 });

	return 0;
}