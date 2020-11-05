
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>



using namespace std;
string arr[8] = { "A", "C", "F", "J", "M", "N", "R", "T" };
vector<string> v;
int answer = 0;
bool checkN(vector<string> s, vector<string> data)
{
	int checkNum = 0;
	for (int w = 0; w < data.size(); w++)
	{
		char n1 = data[w][0];
		char n2 = data[w][2];
		char compare = data[w][3];
		char number = data[w][4];
		int nuberParse = number - '0';

		int ch1;
		int ch2;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i][0] == n1)
			{
				ch1 = i;
			}
			else if (s[i][0] == n2)
			{
				ch2 = i;
			}
		}
		int temp = abs(ch1 - ch2);
		//>,<,=
		if (compare == '=')
		{
			if (temp == 1)
				checkNum++;


		}
		else if (compare == '>')
		{
			if (temp < nuberParse)
				checkNum++;


		}
		else if (compare == '<')
		{
			if (temp > nuberParse)
				checkNum++;


		}
	}

	if (checkNum == data.size())
	{
		return true;
	}
	else
		return false;
}
int solution(int n, vector<string> data)
{

	do
	{
		if (checkN(v, data))
			answer++;

	} while (next_permutation(v.begin(), v.end()));
	return answer;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		v.push_back(arr[i]);
	}
	solution(2, { "N~F=0", "R~T>2" });
	//cout<<answer<<endl;

	return 0;
}