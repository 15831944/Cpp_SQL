#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
int N, M; // 정점, 간선
int num1, num2 = 987654;
int to, from; //진입 진출 노드 
char arr[100][100];
int answer;
int cnt;
bool flag;
int temp = 100;
using namespace std;
/*8 8*/

int sovle()
{
	
	
	for (int w = 0; w <= M - 8; w++)
	{
		cnt = 0;
		for (int i = w; i < w + 7 ; i++)
		{
			for (int z = 0; z <= N - 8; z++)
			{
				for (int j = z; j < z + 5; j+=2)
				{
					if (arr[i][j] == arr[i][j + 1])
					{
						cnt++;
						//swap(arr[i][j], arr[i][j + 1]);
					}
				 

				}
			}
		}
	}
	
	temp = min(cnt, temp);
	cout << temp << endl;

	return 0;
}
int main()
{
	memset(arr, 0x00, sizeof(arr));
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	sovle();

	return 0;
}
