#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	vector < vector<vector<vector<vector<int>>>>> arr(3, vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2, vector<vector<int>>(2))));
	for (int i = 0; i < info.size(); i++)
	{
		stringstream ss(info[i]);

		string temp;
		int a, b, c, d;

		ss >> temp;
		if (temp == "cpp")
			a = 0;
		else if (temp == "java")
			a = 1;
		else
			a = 2;

		ss >> temp;
		if (temp == "backend")
			b = 0;
		else
			b = 1;

		ss >> temp;
		if (temp == "junior")
			c = 0;
		else
			c = 1;

		ss >> temp;
		if (temp == "chicken")
			d = 0;
		else
			d = 1;

		int n;
		ss >> n;
		arr[a][b][c][d].push_back(n);

	}

	for (int i = 0; i < query.size(); i++)
	{
		stringstream sss(query[i]);
		bool a[3], b[2], c[2], d[2];
		string temp;
		sss >> temp;
		if (temp == "-")
		{
			a[0] = true;
			a[1] = true;
			a[2] = true;
		}
		else if (temp == "cpp")
		{
			a[0] = true;
			a[1] = false;
			a[2] = false;
		}
		else if (temp == "java")
		{
			a[0] = false;
			a[1] = true;
			a[2] = false;
		}
		else
		{
			a[0] = false;
			a[1] = false;
			a[2] = true;
		}

		sss >> temp;
		sss >> temp;

		if (temp == "-")
		{
			b[0] = true;
			b[1] = true;
		}
		else if (temp == "backend")
		{
			b[0] = true;
			b[1] = false;
		}
		else
		{
			b[0] = false;
			b[1] = true;
		}
		sss >> temp;
		sss >> temp;
		if (temp == "-")
		{
			c[0] = true;
			c[1] = true;
		}
		else if (temp == "junior")
		{
			c[0] = true;
			c[1] = false;
		}
		else
		{
			c[0] = false;
			c[1] = true;
		}

		sss >> temp;
		sss >> temp;

		if (temp == "-")
		{
			d[0] = true;
			d[1] = true;
		}
		else if (temp == "chicken")
		{
			d[0] = true;
			d[1] = false;
		}
		else
		{
			d[0] = false;
			d[1] = true;
		}

		int n;
		sss >> n;

		int result = 0;

		for (int aa = 0; aa < 3; aa++)
		{
			if (a[aa] == false)
				continue;
			for (int bb = 0; bb < 2; bb++)
			{
				if (b[bb] == false)
					continue;
				for (int cc = 0; cc < 2; cc++)
				{
					if (c[cc] == false)
						continue;
					for (int dd = 0; dd < 2; dd++)
					{
						if (d[dd] == false)
							continue;

						for (int k = 0; k < arr[aa][bb][cc][dd].size(); k++)
						{
							if (arr[aa][bb][cc][dd][k] >= n)
								result++;
						}

					}
				}
			}
		}

		answer.push_back(result);
	}

	return answer;
}