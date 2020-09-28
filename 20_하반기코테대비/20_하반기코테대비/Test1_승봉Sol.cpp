#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		new_id[i] = tolower(new_id[i]);
	}

	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] != '.' && new_id[i] != '-' && new_id[i] != '_')
		{
			if (new_id[i] < 'a' || new_id[i] > 'z')
			{
				if (new_id[i] < '0' || new_id[i] > '9')
					new_id[i] = ' ';
			}
		}
	}

	string temp = "";
	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] != ' ')
		{
			temp += new_id[i];
		}
	}

	new_id = temp;
	temp = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		if (i == 0)
		{
			temp += new_id[i];
		}
		else
		{
			if (new_id[i] == '.' && temp.back() == '.')
				continue;

			temp += new_id[i];
		}
	}

	new_id = temp;

	if (new_id.length() > 1 && new_id[0] == '.')
		new_id.erase(0, 1);

	if (new_id.back() == '.')
		new_id.pop_back();

	if (new_id.length() == 0)
		new_id += "a";

	new_id = new_id.substr(0, 15);

	if (new_id.back() == '.')
		new_id.pop_back();

	if (new_id.length() < 3)
	{
		char t = new_id.back();

		while (new_id.length() < 3)
		{
			new_id.push_back(t);
		}
	}

	answer = new_id;
	return answer;
}


int main()
{
	string a = "123_.def";

	solution(a);

	return 0;
}