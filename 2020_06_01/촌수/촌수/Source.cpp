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
	int numSize;
	cin >> numSize;
	for(int i =0 ; i < numSize; i++)
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
	//ROOT �̸�..
	if (ar[num1].p == 0 && ar[num1].v.size() == 0)
		return;
	if (ar[num2].p == 0 && ar[num2].v.size() == 0)
		return;
	vv[0].push_back(num1);
	int x =num1;
	while (1)
	{
		if (ar[x].p == 0) //�� �θ� ������ 
		{
			//vv[0].push_back(0);//�θ����
			break;
		}
		vv[0].push_back(ar[x].p);//�θ����
		x = ar[x].p;  // x�� �θ�� �ٲ� �� �θ� ã������  ���� v[1]���� �θ���� ���� 
	}
	vv[1].push_back(num2);
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
	
	
	

	for (int i = 0; i < vv[0].size(); i++)
	{
		
		bool flag = false;
		int res;
		for (int j = 0; j< vv[1].size(); j++)
		{
			if (vv[0][i] == vv[1][j])
			{
				res = vv[0][i];
				flag = true;
				break;
			}
			/*else 
			{
				ans = -1; //������ ���� ����! ����
			}*/
			
		}

	//	sort(vv[0].rbegin(), vv[0].rend());
//		sort(vv[1].rbegin(), vv[1].rend());

		if (flag == true) //������ ã�Ҵٸ�!
		{
			//�߰�
			for (int w = 0; w < vv[0].size(); w++)
			{
				cnt++;
				if (vv[0][w] == res)
				{
					break;
				} 
			}
			for (int w = 0; w < vv[1].size(); w++)
			{
				cnt++;
				if (vv[1][w] == res)
				{
					break;
				}
			}
			cnt -= 2;
			break;
		}
	}
 
}

int main()
{
	int tm;
	cin >> tm;
	cin >> num1 >> num2;
	input();
	solve();
	if (cnt == 0)
	{
		cnt = -1;
	}
	cout << cnt << endl;
	return 0;
}