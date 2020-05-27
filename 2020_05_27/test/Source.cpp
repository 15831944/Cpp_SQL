#include <iostream>
#include <vector>
#include <queue>
#include <string>
int N, M; // 정점, 간선
int num1, num2;
int to, from; //진입 진출 노드 
int arr[20][20] = { 0, };
int answer;
int cnt= 1;
bool flag;
using namespace std;

int solve()
{
	vector<int> v1;
	vector<int> v2;
	num1 = 2;
	num2 = 10;
	queue<int> q1;
	queue<int> q2; 
	q1.push(0);
	q2.push(0);
	while (!q1.empty() || !q2.empty())
	{
		if(!q1.empty() ) q1.pop();
		if (!q2.empty()) q2.pop();
		for (int i = 1; i <= N; i++)
		{
			if (arr[i][num1] == 1)
			{
				v1.push_back(i);
				num1 = i;
				q1.push(i);
				break;
			}

		}
		for (int i = 1; i <= N; i++)
		{
			if (arr[i][num2] == 1)
			{
				v2.push_back(i);
				num2 = i;
				q2.push(i);
				break;
			}

		}


	}
	
	for (int i = 0; i < v1.size(); i++)
	{
		if (flag == true) break;
		for (int j = 0; j < v2.size();j++)
		{
			if (v1[i] == v2[j])
			{
				answer = v1[i];
				flag = true;
				break;
			}
		}
	}
	queue<int> q3; 
	int temp = answer;
	q3.push(temp);
	
	while(!q3.empty())
	{
		temp = q3.front();
		q3.pop(); 
		for (int i = 1; i <= N; i++)
		{
			if (arr[temp][i] == 1)
			{
				q3.push(i);
				cnt++;
			}
		}
	}
	cout << answer << " " << cnt << endl;
	return 0;
}
int main()
{

	cin >> N;
	cin >> M;
	////cin >> num1;
	//cin >> num2;
	for (int i = 0; i < M; i++)
	{
		cin >> to;
		cin >> from;
		arr[to][from] = 1;
	}
	solve();


	return 0;
}