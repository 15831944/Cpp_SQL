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

void copyMap(int(*a)[12], int(*b)[12]) {
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j < W; j++) {
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
	if (range == 0) 
	{
		if (r + 1 > H) return;
		dropTheBall(r + 1, c, map[r + 1][c]);
	}
	else {
		queue<pair<pair<int, int>, int>> bombs;
		bombs.push({ { r,c },range });
		map[r][c] = 0;
		while (!bombs.empty()) 
		{
			int curR = bombs.front().first.first;
			int curC = bombs.front().first.second;
			int curRange = bombs.front().second;
			bombs.pop();
			map[curR][curC] = 0;
			for (int i = 1; i < curRange; i++) 
			{
				for (int j = 0; j < 4; j++) 
				{
					int nr = curR + i*dr[j];
					int nc = curC + i*dc[j];
					if (nr < 1 || nr > H || nc < 0 || nc > W - 1)
						continue;
					if (map[nr][nc] > 0) 
					{
						bombs.push({ { nr,nc },map[nr][nc] });
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
	for (int i = 0; i < W; i++) 
	{
		copyMap(map, copyM);
		dropTheBall(0, i, 0);
		playball(n - 1);
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

