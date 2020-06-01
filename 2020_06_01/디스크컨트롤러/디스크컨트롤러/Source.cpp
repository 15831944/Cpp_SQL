#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void input()
{

}
int main()
{
	int num1, num2;
	int t;
	vector<int> Com;
	cin >> t;
	vector <vector<int>> v(t);
	for (int i = 0; i < v.size(); i++)
	{ 	
		cin >> num1 >> num2;
		v[num1].push_back(num2);  
	}
	for (int i = 0; i <t; i++)
	{
		Com.push_back(i);
	}
	
	do 
	{

		//1ºü
		int tmp = v[Com[0]][0] + v[Com[0]][1];
		//2ºü
		int tmp2 = tmp + v[Com[1]][1] - v[Com[1]][0];
		//3ºü
		int tmp3 = 
	} while (next_permutation(Com.begin(), Com.end()));

}