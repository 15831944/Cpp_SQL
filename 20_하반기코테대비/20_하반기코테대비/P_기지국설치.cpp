#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

bool vi[200000000];
int answer = 0; 
bool Fin = false;
void dfs(int cnt,int area, int n, int loc)
{
	
	if (cnt == area)
	{
		answer++;
		
		return;
	}
	for (int i = loc; i <= n+1; i++)
	{
		if (Fin)
			break;
		if (cnt != 0 && vi[i] == true)
		{
			cnt = 0; 
			answer++;
		}  
		else if (vi[i] == true)
			continue;
		
		if (vi[i] == false)
		{
			vi[i] = true; 
			cnt++;
			dfs(cnt,area,n,i+1);
			cnt = 0;
		}
		
		
		if (i == n)
		{
			Fin = true;
		}
			
	}
	
}
int solution(int n, vector<int> stations, int w)
{
	 

	int answer = 0;
	int start = 1;
	bool done = false;
	for (int i = 0; i < stations.size(); i++) {
		int l = stations[i] - w - 1; //������ ������ = 6
		int len = l - start + 1;//1����6���� ���� = 6
		if (len < 0) len = 0; //���̰� 0�����̸� 0���� 
		answer += len / (w * 2 + 1); // ��ü����/Ŀ�����ɹ���
		answer += (len % (w * 2 + 1) == 0) ? 0 : 1; // ����������+0 �ȶ������� +1 �ϳ��߰�
		int r = stations[i] + w + 1; 
		if (r > n) {
			done = true;
			break;
		}
		start = r;
	}
	if (!done) {
		int len = n - start + 1;
		answer += len / (w * 2 + 1);
		answer += (len % (w * 2 + 1) == 0) ? 0 : 1;
	}
	 
	 
	cout << answer << endl; 
	return answer;
}
int main()
{
	solution(16, { 9} ,2);
	solution(11, { 4, 11 }	,1);
	return 0;
}