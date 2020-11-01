
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100001

using namespace std;

struct aaa
{
	int subin;
	int time;
	//vector<int> loc;
	string str;
};

int n, k;
int answer = 1;
int ch;
bool visit[MAX];
int parent[MAX];
int tempcnt = 0;
int minN;
int cnt = 0;

bool first = false;
void bfs()
{
	//queue<pair<int, int>> q;
	queue<aaa> q2;
	string aa = to_string(n);
	q2.push({ n,0,aa});
	//q.push({ n,0 });
	visit[n] = true;
	while (!q2.empty())
	{
		int x = q2.front().subin;
		int time = q2.front().time;
		string loc = q2.front().str;

		q2.pop();

		visit[x] = true;
		//최초로 찾았을때
		if (x == k)
		{
			vector<int> p;
			//minN = time;
			cout << time << endl;
			//cout << loc << endl;
			
			while (x != n) {
				p.push_back(x);
				x = parent[x];
			}


			p.push_back(n);
			int m = p.size();
			for (int i = 0; i<m; i++) printf("%d ", p[m - i - 1]);
			printf("\n");
			return;


		
			
		}
		 

		//int nx = x + 1;
		if (x + 1<=MAX && !visit[x + 1])
		{
			//visit[x+1] = true;
			int tm = x + 1;
			int now = x;
			string no = to_string(now);
			string temp = to_string(tm);
			parent[x + 1] = x;
			q2.push({ x + 1,time + 1,loc +" "+temp});
		}
		if (x - 1 >= 0 && !visit[x - 1])
		{
			//visit[x-1] = true;

			int tm = x - 1;
			int now = x;
			string no = to_string(now);
			string temp = to_string(tm);
			parent[x - 1] = x;
			q2.push({ x - 1,time + 1, loc +" "+ temp });
			//q.push({ x - 1,time + 1 });
		}

		if (x * 2 <= MAX && !visit[x * 2])
		{

			
			int tm = x *2 ;
			int now = x;
			string no = to_string(now);
			string temp = to_string(tm);
			parent[x*2] = x;
			q2.push({ x *2 ,time + 1, loc +" "+ temp });

			//q.push({ 2 * x,time + 1 });
		}


	}
}
int main()
{
	cin >> n >> k;
	bfs();
	//cout << minN << endl;
	//cout << cnt << endl;
	return 0;
}