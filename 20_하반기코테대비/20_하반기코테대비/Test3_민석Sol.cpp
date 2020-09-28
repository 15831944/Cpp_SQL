#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> in[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	for (int i = 0; i < info.size(); i++)
	{
		stringstream ss(info[i]);
		string s;
		vector<int> v;
		while (ss >> s)
		{
			if (s == "java")
			{
				v.push_back(0);
			}
			else if (s == "cpp")
			{
				v.push_back(1);
			}
			else if (s == "python")
			{
				v.push_back(2);
			}
			else if (s == "backend")
			{
				v.push_back(0);
			}
			else if (s == "frontend")
			{
				v.push_back(1);
			}
			else if (s == "junior")
			{
				v.push_back(0);
			}
			else if (s == "senior")
			{
				v.push_back(1);
			}
			else if (s == "chicken")
			{
				v.push_back(0);
			}
			else if (s == "pizza")
			{
				v.push_back(1);
			}
			else
			{
				in[v[0]][v[1]][v[2]][v[3]].push_back(stoi(s));
			}
		}

	}

	for (int i = 0; i < query.size(); i++)
	{
		stringstream ss(query[i]);
		string s;
		vector<int> v;
		int res = 0;
		int xx = 0;
		while (ss >> s)
		{
			if (s == "and")
				continue;
			if (s == "java")
			{
				v.push_back(0);
			}
			else if (s == "cpp")
			{
				v.push_back(1);
			}
			else if (s == "python")
			{
				v.push_back(2);
			}
			else if (s == "backend")
			{
				v.push_back(0);
			}
			else if (s == "frontend")
			{
				v.push_back(1);
			}
			else if (s == "junior")
			{
				v.push_back(0);
			}
			else if (s == "senior")
			{
				v.push_back(1);
			}
			else if (s == "chicken")
			{
				v.push_back(0);
			}
			else if (s == "pizza")
			{
				v.push_back(1);
			}
			else if (s == "-")
			{
				v.push_back(-1);
			}
			else
			{
				xx = stoi(s);
			}
		}

		queue<pair<int, vector<int>>> q;
		vector<int> aa;
		q.push({ 0, aa });
		while (!q.empty())
		{
			int x = q.front().first;
			vector<int> qq = q.front().second;
			q.pop();

			if (x == 4)
			{
				for (int w = 0; w < in[qq[0]][qq[1]][qq[2]][qq[3]].size(); w++)
				{
					if (in[qq[0]][qq[1]][qq[2]][qq[3]][w] >= xx)
						res++;
				}
				continue;
			}

			if (v[x] == -1)
			{
				if (x == 0)
				{
					qq.push_back(0);
					q.push({ x + 1, qq });
					qq.pop_back();
					qq.push_back(1);
					q.push({ x + 1, qq });
					qq.pop_back();
					qq.push_back(2);
					q.push({ x + 1, qq });
				}
				else
				{
					qq.push_back(0);
					q.push({ x + 1, qq });
					qq.pop_back();
					qq.push_back(1);
					q.push({ x + 1, qq });
				}
			}
			else
			{
				qq.push_back(v[x]);
				q.push({ x + 1, qq });
			}
		}
		answer.push_back(res);
	}

	return answer;
}

int main()
{
	solution({ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" }, { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" });
}