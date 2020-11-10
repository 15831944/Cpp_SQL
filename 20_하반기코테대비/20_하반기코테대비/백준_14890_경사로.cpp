
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100


using namespace std;
int n;
int l;
int map[MAX][MAX];
int garo()
{
	int garo = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		bool check = false;
		for (int j = 0; j < n-1; j++)
		{
			for (int w = j + 1; w < n; w++)
			{
				if (map[i][j] == map[i][w])
				{
					cnt++;
				}
				//갑자기 커진경우
				else if (map[i][j] < map[i][w])
				{
					if (abs(map[i][j] - map[i][w]) > 1)
					{
						check = true;
						break;
					}
						
					else 
					{
						//가능
						if (l <= cnt)
						{
							j = w;
							cnt = 0;
						}
						else
						{
							check = true;
							break;
						}
					}
				}
				else  if (map[i][j] > map[i][w])
				{
					if (abs(map[i][j] - map[i][w]) > 1)
					{
						check = true;
						break;
					}
					else
					{
						int tempcnt=0;
						for (int z = w; z < n; z++)
						{
							
							if (map[i][w] == map[i][z])
							{
								tempcnt++;
							}
							else
							{
								check = true;
								break;
							}
						}
						//가능
						if (tempcnt < l)
						{
							cnt = 0;
						}
						//불가
						else
						{
							break;
						}
					}
				}
				
			}
			if (check)
				break;
		}  
		if (!check)
			garo++;
	}
	return garo;
}
int sero()
{
	int sero = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		bool check = false;
		for (int j = 0; j < n - 1; j++)
		{
			for (int w = j + 1; w < n; w++)
			{
				if (map[j][i] == map[w][i])
				{
					cnt++;
				}
				//갑자기 커진경우
				else if (map[j][i] < map[w][i])
				{
					if (abs(map[j][i] - map[w][i]) > 1)
					{
						check = true;
						break;
					}

					else
					{
						//가능
						if (l <= cnt)
						{
							j = w;
							cnt = 0;
						}
						else
						{
							check = true;
							break;
						}
					}
				}
				else  if (map[j][i] > map[w][i])
				{
					if (abs(map[j][i] - map[w][i]) > 1)
					{
						check = true;
						break;
					}
					else
					{
						int tempcnt=0;
						for (int z = w; z < n; z++)
						{

							if (map[w][i] == map[z][i])
							{
								tempcnt++;
							}
							else if(map[w][i] != map[z][i])
							{
								//가능
								if (tempcnt >= l)
								{
									w = z - 1;
									j = z - 1;
									cnt = 0;
									break;
								}
								//불가
								else
								{
									check = true;
									break;
								}
							}
						}
						
					}
				}

			}
			if (check)
				break;
		}
		if (!check)
			sero++;
	}
	return sero;
}

int main()
{
	int answer = 0;
	cin >> n >>l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int ga = garo();
	int se = sero();
	answer = ga + se;
	cout << answer << endl;
	return 0;
}