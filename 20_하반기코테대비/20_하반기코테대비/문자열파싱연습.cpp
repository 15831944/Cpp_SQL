#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
bool check[101] = { false, };
void solution(vector<string> ipAd)
{
	for (int i = 0; i < ipAd.size(); i++)
	{
		string Pad;
		vector<string> v;
		int cnt = 0;
		for (int j = 0; j < ipAd[i].size(); j++)
		{

			if (ipAd[i][j] == '.')
			{
				cnt++;
				if (cnt > 3)
				{
					check[i] = true;
					break;
				}
				int num = stoi(Pad);
				if (num > 255)
				{
					check[i] = true;
					break;
				}
				//v.push_back(Pad);
				Pad = "";
			}
			else
			{
				Pad += ipAd[i][j];
			}		
		}
	
	}
	for (int i = 0; i < ipAd.size(); i++)
		if (check[i])
			cout << "Ū : "<< i << endl;

}

int main()
{
	solution({ "192.168.0.1","192.168.0.1..","260.126.63.1","168.126.63.2" });
	return 0;
}