#include <iostream>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int N, W, H;
int map[16][12];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int ans = INF;

// 초기맵을 카피해야함.
void copyMap(int(*a)[12], int(*b)[12]) 
{
	for (int i = 1; i <= H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void blockSort() {
	for (int i = 0; i < W; i++) 
	{
		queue<int> block;
		for (int r = H; r > 0; r--) 
		{
			if (map[r][i] > 0) 
			{
				block.push(map[r][i]);
			}
		}
		for (int r = 1; r <= H; r++) 
			map[r][i] = 0;
		int h = H;
		while (!block.empty()) 
		{
			int range = block.front();
			block.pop();
			map[h][i] = range;
			h--;
		}
	}
}

void dropTheBall(int r, int c, int range) 
{
	//range==0 이라는 것은 map[x][y] == 0 이라는 것 
	if (range == 0) 
	{
		if (r + 1 > H) return;
		dropTheBall(r + 1, c, map[r + 1][c]); //r+1를 해주면서 (= 아래로 내리면서) 탐색
	}
	else {
		queue<pair<pair<int, int>, int>> bombs;
		bombs.push({ { r,c },range });  //좌표와 그 값(range)를 저장
		map[r][c] = 0;  //해당 좌표를 0 으로 초기화

		while (!bombs.empty()) 
		{
			int curR = bombs.front().first.first;  //현재 R
			int curC = bombs.front().first.second; //현재 C 
			int curRange = bombs.front().second; //범위
			bombs.pop();  
			map[curR][curC] = 0;  // 엥 왜 두번하지?
			// 범위 만큼 
			for (int i = 1; i < curRange; i++) 
			{ 
				//상하좌우라서 4번
				for (int j = 0; j < 4; j++) 
				{
					//상하좌우 0*dr[0] , 1*dr[1]  
					int nr = curR + i*dr[j];
					int nc = curC + i*dc[j];
					//범위 밖
					if (nr < 1 || nr > H || nc < 0 || nc > W - 1)
						continue;
					//만약 그자리가 0보다 크다면
					if (map[nr][nc] > 0) 
					{
						//또 터트려야하니깐 queue에 넣기.
						bombs.push({ { nr,nc },map[nr][c] });
						//해당 자리0으로 초기화 어차피 0으로 변함.
						map[nr][nc] = 0;
					}
				}
			}
		}
		blockSort();
	}
}

void playball(int n) 
{
	//n==0 이라는것은 n번의 기회를 다 쓴것 
	if (n == 0) 
	{
		int sum = 0;
		for (int i = 1; i <= H; i++) 
		{
			for (int j = 0; j < W; j++) 
			{
				if (map[i][j] > 0) sum++;
			}
		}
		if (ans > sum) ans = sum;
		return;
	}
	int copyM[16][12];
	//10번 실행
	for (int i = 0; i < W; i++) 
	{
		/*
			총 W=10일때 10번 수행한다.
			기존 원본 맵을 카피해준다.
			1) dropthball 0이 아닌 숫자를 찾으면 그로부터 터지는 경우를 모두 구한다. queue이용
			2) blockSort() 값이 터지면 모든 값을 queue에 넣고 아래서 부터 순서대로 삽입한다. 13''2 --> 132 이런식. queue 이용
			3) playball (n-1) 0보다 큰 숫자의 남아있는 공을 모두 구한다. 그 값이 ans 보다 작으면 ans에 저장하여 min값을 구한다.
		*/
		copyMap(map, copyM);
		dropTheBall(0, i, 0); 
		playball(n - 1);//n-1해주는것은 한번씩 기회를 날리는 것
		copyMap(copyM, map);
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) 
	{
		memset(map, 0, sizeof(map));
		cin >> N >> W >> H;
		for (int i = 1; i <= H; i++) 
		{
			for (int j = 0; j < W; j++) 
			{
				cin >> map[i][j];
			}
		}
		ans = INF;
		playball(N);
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}

