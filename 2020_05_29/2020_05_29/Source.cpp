#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>
 
int T; //TC
int from, to;

int answer;


using namespace std;
vector<char> v1;
vector<char> v2;
vector<char> v3;
vector<char> v4;
vector<vector<char>> totalVec;
void input()
{
	cin >> from >> to;
	
}
//D 
int D(int num)
{
	num = num * 2;


	if (num >= 9999)
	{
		num = num % 10000;
	}
	return num;
}
//S
int S(int num)
{
	num = num - 1;
	if (num == 0)
	{
		num = 9999;
	}
	return num;
}
//L
int L(int num)
{
	queue<char> q;
	string temp = to_string(num) ;
	 
	for (int i = 0; i < temp.size(); i++)
	{
		q.push(temp[i]);
	}
	char temp2 = q.front();
	q.pop();
	q.push(temp2); \
	string temp3;
	for (int i = 0; i < sizeof(num); i++)
	{
		temp3 += q.front();
		q.pop();
	}
	num = stoi(temp3);
	return num;
}
//R
int R(int num)
{
	list<char> li;
	string temp = to_string(num);
	for (int i = 0; i < temp.size(); i++)
	{
		li.push_back(temp[i]);
	}
	char temp2 = li.back();
	li.pop_back();
	li.push_front(temp2);
	string temp3;
	for (int i = 0; i < sizeof(num); i++)
	{
		temp3 += li.front();
		li.pop_front();
	}
	num = stoi(temp3);
	return num;

} 

void solve(int num, int fromNum)
{
	queue<int> q;
	v1.clear();
	
	q.push(num);
	while (!q.empty())
	{
		int func = q.front();
		q.pop();
		if (v1.size() > 100 || q.size() >100 ) break; 
		if (func == 0) //D
		{
			fromNum = D(fromNum);
			v1.push_back('D');
			if (fromNum == to)
			{
				answer = 1;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				q.push(i);
			}

		}
		else if (func == 1) //S 
		{
			fromNum = S(fromNum);
			v1.push_back('S');
			if (fromNum == to)
			{
				answer = 2;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				q.push(i);
			}
		}
		else if (func == 2) 
		{//L
			fromNum = L(fromNum);
			v1.push_back('L');
			if (fromNum == to)
			{
				answer = 3;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				q.push(i);
			}

		}
		else if (func == 3) 
		{ //R 
			fromNum = R(fromNum);
			v1.push_back('R');
			if (fromNum == to)
			{
				answer = 4;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				q.push(i);
			}
		}

	}
	
}
void main()
{


	input();
	for (int i = 0; i < 4; i++)
	{
		solve(i,from);
		totalVec.push_back(v1);
	}
	
	 
}