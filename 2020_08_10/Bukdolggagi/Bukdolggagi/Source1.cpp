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

// �ʱ���� ī���ؾ���.
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
	//range==0 �̶�� ���� map[x][y] == 0 �̶�� �� 
	if (range == 0) 
	{
		if (r + 1 > H) return;
		dropTheBall(r + 1, c, map[r + 1][c]); //r+1�� ���ָ鼭 (= �Ʒ��� �����鼭) Ž��
	}
	else {
		queue<pair<pair<int, int>, int>> bombs;
		bombs.push({ { r,c },range });  //��ǥ�� �� ��(range)�� ����
		map[r][c] = 0;  //�ش� ��ǥ�� 0 ���� �ʱ�ȭ

		while (!bombs.empty()) 
		{
			int curR = bombs.front().first.first;  //���� R
			int curC = bombs.front().first.second; //���� C 
			int curRange = bombs.front().second; //����
			bombs.pop();  
			map[curR][curC] = 0;  // �� �� �ι�����?
			// ���� ��ŭ 
			for (int i = 1; i < curRange; i++) 
			{ 
				//�����¿�� 4��
				for (int j = 0; j < 4; j++) 
				{
					//�����¿� 0*dr[0] , 1*dr[1]  
					int nr = curR + i*dr[j];
					int nc = curC + i*dc[j];
					//���� ��
					if (nr < 1 || nr > H || nc < 0 || nc > W - 1)
						continue;
					//���� ���ڸ��� 0���� ũ�ٸ�
					if (map[nr][nc] > 0) 
					{
						//�� ��Ʈ�����ϴϱ� queue�� �ֱ�.
						bombs.push({ { nr,nc },map[nr][c] });
						//�ش� �ڸ�0���� �ʱ�ȭ ������ 0���� ����.
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
	//n==0 �̶�°��� n���� ��ȸ�� �� ���� 
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
	//10�� ����
	for (int i = 0; i < W; i++) 
	{
		/*
			�� W=10�϶� 10�� �����Ѵ�.
			���� ���� ���� ī�����ش�.
			1) dropthball 0�� �ƴ� ���ڸ� ã���� �׷κ��� ������ ��츦 ��� ���Ѵ�. queue�̿�
			2) blockSort() ���� ������ ��� ���� queue�� �ְ� �Ʒ��� ���� ������� �����Ѵ�. 13''2 --> 132 �̷���. queue �̿�
			3) playball (n-1) 0���� ū ������ �����ִ� ���� ��� ���Ѵ�. �� ���� ans ���� ������ ans�� �����Ͽ� min���� ���Ѵ�.
		*/
		copyMap(map, copyM);
		dropTheBall(0, i, 0); 
		playball(n - 1);//n-1���ִ°��� �ѹ��� ��ȸ�� ������ ��
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

