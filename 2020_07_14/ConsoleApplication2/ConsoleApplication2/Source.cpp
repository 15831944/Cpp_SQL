#include <iostream>
#include <vector>
#include <map>

using namespace std;
bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}
int main()
{

	vector<int> first;
	vector<int> second;
	vector<int> third;
	int myints[] = { 1776,7,4 };

	//1
	first.assign(7, 100);//100을 7번 반복해서 집어넣음.
	vector<int>::iterator it;
	it = first.begin() + 1;

	//2
	second.assign(it, first.end() - 1); // first의 처음과 끝을 제외한 원소들 넣는다.

	//3
	third.assign(first.begin(), first.end());

	//4
	third.assign(myints, myints + 4);

	map<string, int> m;
	vector<pair<string, int>> v;
	map<string, vector<pair<int, int>>> mm;
	vector<pair<string, pair<int, int>>> vv;

	//5
	m.insert({ "1", 1 });
	m.insert({ "2", 2 });
	m.insert({ "3", 3 });
	m.insert({ "4", 4 });
	v.assign(m.begin(), m.end());

	//6
	vector<pair<int, int>> vm;
	vm.push_back({ 1,2 });
	mm.insert({ "str",vm });

	vv.push_back({ "str",{1,2} });
	vv.push_back({ "str",{ 1,2 } });
	vv.push_back({ "str",{ 1,2 } });
	vv.push_back({ "str",{ 1,2 } });
	vv.push_back({ "str",{ 1,2 } });
	vv.push_back({ "str",{ 1,2 } });

	int temp = vv.front().second.first;

	vv.assign(mm.begin(), mm.end());

	return 0;
}
