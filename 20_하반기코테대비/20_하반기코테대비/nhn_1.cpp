#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
/*
2
B2(RG)
3(R2(GB))
*/
using namespace std;
vector<string> ans;
int n;
string answer;
vector<string> v[100];
void solution(int numOfOrder, vector<string> orderArr)
{
	for(int i = 0 ; i <orderArr.size();i++)
	{
		answer = orderArr[i];
		
		for (int j = 0; j < answer.size(); j++) 
		{
			//¼ýÀÚ¹ß°ß
			if (isdigit(answer[j]) != 0)
			{
				int cnt = 0;
				if (answer[j + 1] == '(')
				{
					cnt++;
					for (int w = j + 2; w < orderArr[i].size(); w++)
					{
						if (answer[w] == '(')
						{
							cnt++;
						}
						else if (answer[w] == ')')
						{
							cnt--;
							if (cnt == 0)
							{
								//num ÆÄ½Ì
								char temp = answer[j];
								int num = temp - '0';
								string totalStr;
								
								for (int t = j + 1; t <= w; t++)
								{
									totalStr += answer[t];
								}

								answer.erase(j , w+1);
								string aa="HELLO";
								aa[1] = 'M';
								for (int z = j; z < w+1; z++)
								{
									answer[z] = totalStr[z];
									//answer[z] =
									
								}
							}
						}
					}
				}
				else
				{
					//num ÆÄ½Ì
					char temp = orderArr[i][j];
					int num = temp - '0';
					string totalStr;
					for (int w = j + 1; w < j+2; j++)
					{
						totalStr += orderArr[i][w];
					}
					for (int i = 1; i <= num; i++)
					{
						answer += totalStr;
					}
				}
		
			}
		}
	}


}
int main()
{
	cin >> n; 
	solution(n, {"3(R2(GB))","B(RGB(RG))"});
	return 0;
}