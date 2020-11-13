#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 1000
int n, m;
int SangNum;
int map[MAX][MAX];

struct SangA
{
	int r; //행
	int c; //열
	int speed; //스피드
	int dir; //방향 
	int SangSize; //상어의 크기

};
using namespace std;
queue<SangA> v;
int visit[MAX][MAX] = { 0, };
int position = 0;
int answer = 0;
void move()
{

	for (int i = 1; i <= m; i++)
	{
		int nowR = v.front().r;
		int nowC = v.front().c;
		int nowspeed = v.front().speed;
		int nowdir = v.front().dir;
		int nowsize = v.front().SangSize;
		v.pop();
		if (nowdir == 1)//위
		{
			//없애기
			if (visit[nowR][nowC] != 0)
			{
				visit[nowR][nowC] = 0;
				int nextR = nowR - nowspeed;
				if (nextR < 1)
				{
					int temp = (n - 1) * 2;
					nextR = nowspeed%temp;
					nowdir = 2;
				}
				//새로생김
				if (visit[nextR][nowC] < nowsize)
					visit[nextR][nowC] = nowsize;
				v.push({ nextR,nowC,nowspeed,nowdir,nowsize });
			}
		}
		else if (nowdir == 2)//아래
		{
			if (visit[nowR][nowC] != 0)
			{

				visit[nowR][nowC] = 0;
				int nextR = nowR + nowspeed;
				if (nextR > n)
				{
					int temp = (n - 1) * 2;
					nextR = nowspeed%temp;
					nowdir = 1;
				}
				if (visit[nextR][nowC] < nowsize)
					visit[nextR][nowC] = nowsize;
				v.push({ nextR,nowC,nowspeed,nowdir,nowsize });
			}
		}
		else if (nowdir == 3)//오른쪽
		{
			if (visit[nowR][nowC] != 0)
			{
				visit[nowR][nowC] = 0;
				int nextC = nowC + nowspeed;
				if (nextC > m)
				{
					int temp = (m - 1) * 2;
					nextC = nowspeed%temp;
					nowdir = 4;
				}
				if (visit[nowR][nextC] > nowsize)
					visit[nowR][nextC] = nowsize;

				v.push({ nowR,nextC,nowspeed,nowdir,nowsize });
			}
		}
		else if (nowdir == 4)//왼쪽
		{
			if (visit[nowR][nowC] != 0)
			{

				visit[nowR][nowC] = 0;
				int nextC = nowC - nowspeed;
				if (nextC < 0)
				{
					int temp = (m - 1) * 2;
					nextC = nowspeed%temp;
					nowdir = 3;
				}
				if (visit[nowR][nextC] > nowsize)
					visit[nowR][nextC] = nowsize;
				v.push({ nowR,nextC,nowspeed,nowdir,nowsize });
			}
		}

	}



}
void catchmeifyoucan()
{
	position++;
	for (int i = 1; i <= SangNum; i++)
	{
		if (visit[i][position] != 0)
		{
			answer += visit[i][position];
			visit[i][position] = 0;
			break;
		}
	}




}
int main()
{
	cin >> n >> m >> SangNum;

	SangA Sang;

	for (int i = 0; i <SangNum; i++)
	{

		int r, c;
		int speed;
		int dir;
		int SangSize;
		cin >> r >> c >> speed >> dir >> SangSize;


		Sang.r = r;
		Sang.c = c;
		Sang.speed = speed;
		Sang.dir = dir;
		Sang.SangSize = SangSize;
		v.push(Sang);
		visit[r][c] = SangSize;
	}

	while (m-->0)
	{
		catchmeifyoucan();
		move();
	}
	//answer = answer - 4;
	cout << answer << endl;
	return 0;
}