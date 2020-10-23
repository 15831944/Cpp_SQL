#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;
int N, M, K;
int cnt = 0;
int sq[101][101];
int visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
priority_queue < int, vector < int >, greater < int > > pq;

int bfs(int y, int x) {
	int cnt = 1;
	queue < pair < int, int > > q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();
		for (int i = 0; i<4; i++) {
			int newy = ny + dy[i];
			int newx = nx + dx[i];
			if (newy > N || newy <= 0 || newx > M || newx <= 0)
				continue;
			if (visited[newy][newx])
				continue;
			if (sq[newy][newx] == 0) {
				visited[newy][newx] = 1;
				q.push(make_pair(newy, newx));
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int x1, y1, x2, y2;
	scanf_s("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= K; i++) {
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int a = x1 + 1; a <= x2; a++) {
			for (int b = y1 + 1; b <= y2; b++) {
				sq[b][a] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[i][j] == 0 && sq[i][j] == 0) {
				pq.push(bfs(i, j));
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	while (!pq.empty()) {
		int now = pq.top();
		printf("%d ", now);
		pq.pop();
	}
}