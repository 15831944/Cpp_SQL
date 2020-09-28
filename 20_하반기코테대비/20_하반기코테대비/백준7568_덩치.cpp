#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int n;
vector<pair<int, int> > v;
vector<int> score;
void solution()
{
	
	for (int i = 0; i < v.size(); i++)
	{
		score.push_back(1);
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[i].first < v[j].first)
			{
				if (v[i].second < v[j].second)
					score[i]++;
			}
		}
	}
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

}
int main()
{
	input();
	solution();
	for (int i = 0; i < score.size(); i++)
		cout << score[i] << " ";
	return 0;
}