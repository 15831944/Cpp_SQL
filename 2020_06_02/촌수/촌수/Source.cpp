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
int num1,num2;
int ans;
int cnt;

void input()
{
	for(int i =0 ; i < 7 ; i++)
	{
		int a, b;
		cin >> a >> b; //1,2 
		ar[a].v.push_back(b);
		ar[b].p = a;
	}

}

void dfs(int n)
{
	int temp;
	temp = ar[n].p;
	if (n == ans || ans ==-1 ||temp ==0)
	{
		return;
	}
	cnt++;
	
	
	if (temp != 0)
		dfs(temp);
	else
		return;
}
void solve()
{
	vector<int> vv[2];
	int x =num1;
	while (1)
	{
		if (ar[x].p == 0) //�� �θ� ������ 
		{
			vv[0].push_back(0);//�θ����
			break;
		}
		vv[0].push_back(ar[x].p);//�θ����
		x = ar[x].p;  // x�� �θ�� �ٲ� �� �θ� ã������  ���� v[1]���� �θ���� ���� 
	}
	int y =num2 ;
	while (1)
	{
		if (ar[y].p == 0)
		{
			break;
		}
		vv[1].push_back(ar[y].p); //�ι�°������ �θ�� ����
		y = ar[y].p; //�θ� ü����  �ǳ����� �ö� 
		//�� 3,7�� ������ �ǳ��� 1���� ���� 
	}
	
	sort(vv[0].begin(), vv[0].end());
	sort(vv[1].begin(), vv[1].end());

	for (int i = 0; i < vv[0].size(); i++)
	{
		bool flag = false;
		for (int j = 0; j< vv[1].size(); j++)
		{
			if (vv[0][i] == vv[1][j])
			{
				ans = vv[0][i];
				flag = true;
				break;
			}
			else 
			{
				ans = -1; //������ ���� ����! ����
			}
			
		}
		if (flag == true) break;
	}
	dfs(num1);
	dfs(num2);
}

void main()
{
	cin >> num1 >> num2;
	input();
	solve();
	if (cnt == 0)
	{
		cnt = -1;
	}
	cout << cnt << endl;
}