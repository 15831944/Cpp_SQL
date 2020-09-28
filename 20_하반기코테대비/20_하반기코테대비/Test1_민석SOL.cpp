#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size(); i++)
	{
		if (new_id[i] == 46 || new_id[i] == 45 || new_id[i] == 95 || (new_id[i] >= 97 && new_id[i] <= 122) || (new_id[i] >= 48 && new_id[i] <= 57))
			answer += new_id[i];
		else if (new_id[i] >= 65 && new_id[i] <= 90)
			answer += new_id[i] + 32;
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == '.')
		{
			if (answer[i + 1] == '.')
			{
				answer.erase(answer.begin() + i);
				i--;
			}
		}
	}

	if (answer[0] == '.')
		answer.erase(answer.begin());
	if (answer[answer.size() - 1] == '.')
		answer.pop_back();

	if (answer.size() == 0)
		answer += "a";

	if (answer.size() > 15)
	{
		for (int i = answer.size(); i > 15; i--)
			answer.pop_back();
		if (answer[answer.size() - 1] == '.')
			answer.pop_back();
	}

	if (answer.size() < 3)
	{
		char c = answer[answer.size() - 1];
		for (int i = answer.size(); i < 3; i++)
			answer += c;
	}

	return answer;
}

int main()
{
	solution("...!@BaT#*..y.abcdefghijklm");
}