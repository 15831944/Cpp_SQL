#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
/*
3
1234 3412
1000 1
1 16

test
1
1234 3412
LL

*/

using namespace std;

void solution()
{

}
int start = 0;
int endnum = 0;
string ans;
void input()
{
	cin >> start;
	cin >> endnum;
}
void bfs(int s)
{
	queue<pair<int, string>> q;
	q.push({ s,"" });
	while (!q.empty())
	{
		
		int x = q.front().first;
		string y = q.front().second;
		if (x == endnum)
		{
			ans = y;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//D
			if (i == 0)
			{
				s = x * 2;
				if (s > 9999)
					s = s%10000;
				q.push({ s,y + "D" });
			}
			//S
			else if (i == 1)
			{
				s = x - 1;
				if (s == 0)
					s = 9999;
				q.push({ s,"S" });
			}
			else if (i == 2)
			{
				//1234 -> 4123
				string tmp = to_string(x);
				char add = tmp[0];
				tmp.erase(0, 1);
				tmp = tmp + add;
				s = stoi(tmp);
				q.push({ s,"L" });
			}//R
			else
			{
				string tmp = to_string(x);
				int sizeNum = tmp.size();
				char add = tmp[sizeNum-1];
				tmp.erase(sizeNum-1, sizeNum);
				tmp = add +tmp ;
				s = stoi(tmp);
				q.push({ s,"R" });
			}

		}


	}
}
void ini()
{
	start = 0;
	endnum = 0;
	ans = "";


}
int n, m;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ini();
		input();
		bfs(start);
		cout << ans << endl;
	}
	
	return 0;
}