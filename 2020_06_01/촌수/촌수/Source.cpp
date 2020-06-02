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
	//ROOT 이면..
	if (ar[num1].p == 0 && ar[num1].v.size() == 0)
		return;
	if (ar[num2].p == 0 && ar[num2].v.size() == 0)
		return;
	vv[0].push_back(num1);
	int x =num1;
	while (1)
	{
		if (ar[x].p == 0) //즉 부모가 없으면 
		{
			//vv[0].push_back(0);//부모삽입
			break;
		}
		vv[0].push_back(ar[x].p);//부모삽입
		x = ar[x].p;  // x를 부모로 바꿈 그 부모를 찾기위해  따라서 v[1]에는 부모들이 쌓임 
	}
	vv[1].push_back(num2);
	int y =num2 ;
	while (1)
	{
		if (ar[y].p == 0)
		{
			break;
		}
		vv[1].push_back(ar[y].p); //두번째숫자의 부모들 넣음
		y = ar[y].p; //부모 체인지  맨끝까지 올라감 
		//즉 3,7은 각자의 맨끝인 1까지 삽입 
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
				ans = -1; //조상이 같지 않음! 남남
			}*/
			
		}

	//	sort(vv[0].rbegin(), vv[0].rend());
//		sort(vv[1].rbegin(), vv[1].rend());

		if (flag == true) //조상을 찾았다면!
		{
			//추가
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