#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct aaa
{
	int p;
	vector<int> v;
};
aaa ar[10001];
int num1, num2;
int ans;
int cnt;


int solution(int n, vector<vector<int>> edges)
{
	int answer = 0;
	int aasd= edges.size();
	for (int i = 0; i < edges.size(); i++)
	{ 
		ar[edges[i][0]].v.push_back(edges[i][1]);
		ar[edges[i][1]].p = edges[i][0];
	}
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int x = q.front();
		int maxSon= 0;
		for (int i = 0; i < ar[x].v.size(); i++)
		{
			int temp = ar[x].v.size();
			maxSon = max(temp, maxSon);
			for (int w = 0; ar[x].v.size(); w++)
			{
				if (w == maxSon)
					continue;
				 
			}
		}
	}
	//ar[a].v.push_back(b);
	//ar[b].p = a;
	return answer;
}


 
int main()
{
	 

	solution(19, { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 }, { 3, 8 }, { 3, 9 }, { 4, 10 }, { 4, 11 }, { 5, 12 }, { 5, 13 }, { 6, 14 }, { 6, 15 }, { 6, 16 }, { 8, 17 }, { 8, 18 } });
	return 0;
}