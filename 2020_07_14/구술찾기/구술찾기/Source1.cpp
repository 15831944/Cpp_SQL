 
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 101

int M, N;
int result = 0;
bool check[MAX]; 
bool v[MAX];
vector <int> LIST1[MAX];
vector <int> LIST2[MAX]; 

int PRO(int number, vector <int> vec[MAX], int Row) 
{
	int Lank = 1;
	for (int i = 0; i < vec[number].size(); i++)
	{
		
		if (!v[vec[number][i]])
		{
			v[vec[number][i]] = true;

			Lank += PRO(vec[number][i], vec, Row);
		}
	}
	return Lank;
}
 
int main() {
	 
	cin >> N >> M;

	for (int i = 0; i < M; i++) 
	{
		int Ball_1, Ball_2;
		cin >> Ball_1 >> Ball_2;
		LIST1[Ball_1].push_back(Ball_2);
		LIST2[Ball_2].push_back(Ball_1);
	}

	for (int i = 1; i <= N; i++) 
	{
		memset(v, false, sizeof(v)); 
		int cnt1 = PRO(i, LIST1, 0);

		if (cnt1 > (N + 1)/2)
			check[i] = true;
	}
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v)); 
		int cnt2 = PRO(i, LIST2, 1);
		if (cnt2 > (N + 1) / 2)
			check[i] = true;
	}

	for (int i = 0; i <= N; i++)
		if (check[i])
			result++;

	cout << result;
	return 0;
}

 