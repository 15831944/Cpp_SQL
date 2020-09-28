#include <vector>
#include <string>

using namespace std;

int aa[16][16];
void solution(vector<vector<int>> v)
{
	vector<int> answer;
	for (int i = 0; i < v.size(); i++) //0,1,2,3,4
	{
		aa[i][v[i][0]] = v[i][1];
	}
	for (int i = 0; i < v.size() - 1; i++)
	{ //v[0][0] 기준 검사 -> v[1][0] , v[1][1]
		int cnt = 0;

		while (1)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (aa[i + 1][j] == 0 && aa[i + 1][j + 1] != 0)
				{
					//aa[1][0] = aa[0][0] - aa[1][1]
					aa[i + 1][j] = aa[i][j] - aa[i + 1][j + 1];
					cnt++;
				}
				else if (aa[i + 1][j] != 0 && aa[i + 1][j + 1] == 0)
				{
					//aa[1][1] = aa[0][0] - aa[1][1] 
					aa[i + 1][j + 1] = aa[i][j] - aa[i + 1][j];
					cnt++;
				}

			}

			if (cnt > i)
				break;
		}

	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			answer.push_back(aa[i][j]);
		}
	}

}
// [50, 22, 28, 4, 18, 10, 0, 4, 14, -4, 1, -1, 5, 9, -13]

int main()
{
	solution({ { 0, 50 },{ 0, 22 },{ 2, 10 },{ 1, 4 },{ 4, -13 } });
	return 0;
}