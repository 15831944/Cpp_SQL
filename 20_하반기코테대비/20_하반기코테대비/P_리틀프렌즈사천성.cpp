#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

struct pos
{
	int x, y;
};

using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<string> m_board;
vector<vector<pos>> alpha_pos;
bool visit[100][100];
int N, M;
bool reachable(char c, pos from, pos to)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = from.x + dx[i];
		int ny = from.y + dy[i];
		while (!(nx < 0 || nx >= M || ny < 0 || ny >= N))
		{
			if (nx == to.x && ny == to.y)
			{
				return true;
			}
			if (m_board[nx][ny] != '.')
			{
				break;
			}

			//위아래->양옆, 양옆->위아래
			//방향이 겹치지 않게 2방향으로만 뻗어나가기.
			for (int j = ((i + 1) % 2); j < 4; j += 2)
			{
				int nnx = nx + dx[j];
				int nny = nx + dy[j];
				while (!(nnx < 0 || nnx >= M || nny < 0 || nny >= N))
				{
					if (nnx == to.x && nny == to.y)
						return true;
					if (m_board[nnx][nny] != '.')
						break;
					nnx += dx[j];
					nny += dy[j];
				}
			}


			nx += dx[i];
			ny += dy[i];


		}
	}
	return false;
}
bool game(string &answer, int left)
{
	while (1)
	{
		bool match = false;
		for (int i = 0; i < 26; i++)
		{
			if (!alpha_pos[i].empty())
			{
				char c = i + 'A';
				pos from = alpha_pos[i][0];
				pos to = alpha_pos[i][1];

				//두 알파벳이 1번 이하로 꺽어서 닿을수 있는 경우

				if (reachable(c, from, to))
				{
					answer += c;
					//알파벳이 있던 자리 빈칸 alpha_pos 저장되어이 있던 위치 초기화
					m_board[from.x][from.y] = '.';
					m_board[to.x][to.y] = '.';
					alpha_pos[i].clear();
					match = true;
					left -= 2;
					break;
				}
			}
		}
		if (!match)
			break;
	}
	//모든 짝이 맞춰졌으면 true 반환
	return (left == 0);
}

string solution(int m, int n, vector<string> board)
{
	//전역변수로 처리
	M = m;
	N = n;
	m_board = board;
	alpha_pos = vector<vector<pos>>(26);
	//각 알파벳의 위치 2개를 찾아 alpha_pos 벡터에 저장.
	int left = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (isalpha(board[i][j]))
			{
				++left; 
				alpha_pos[board[i][j] - 'A'].push_back({ i,j });
			}
		}
	}
	string answer = "";
	if (game(answer, left))
		return answer;
	return "IMPOSSIBLE";
}
int main()
{ 	
	solution(3, 3, { "D.D", "ABA", "BEE" });
	return 0;
}

/*string answer = "";
	char tempStr;
	queue<pair<int, int>> q;
	int tempX = 0;
	int tempY = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			q.push({ i,j });
			if (q.size() == 1 && board[i][j] == '.')
			{
				q.pop();
				continue;
			}
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (board[x][y] != '.')
				{
					tempStr = board[i][j];
					visit[x][y] = true;
					tempX = x;
					tempY = y;
				}
				for (int w = 0; w < 4; w++)
				{
					int nx = x + dx[w];
					int ny = y + dy[w];

					if (nx<0 || ny <0 || nx>=m || ny >=n || board[nx][ny]=='*'  )
						continue;
					if (board[x][y] == '*' )
						continue;
					if (board[nx][ny] == '.')
					{
						q.push({ nx,ny });
						cnt++;
						if (cnt == 3)
							break;
					}
					else if (board[nx][ny] == tempStr && visit[nx][ny]==false)
					{
						board[nx][ny] = '.';
						board[tempX][tempY] = '.';
						answer += tempStr;
						break;
					}  
				}

			}
		}
	}
	 
	 return answer;*/