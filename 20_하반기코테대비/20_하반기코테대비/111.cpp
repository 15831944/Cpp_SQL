#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;


vector<int> solution(int N)
{ 
	int namerge; 
	vector<int> answer;
	vector<int> v[10];
	int ch;
	for (int n = 2; n < 10; n++)
	{
		int mul = 1;
		int mok = INT_MAX;
		while (1) 
		{
			if (mok == 0)break;
			if (mok == INT_MAX) {
				mok = N / n;
				namerge = N%n;
			}
			else {
				namerge = mok %n;
				mok = mok / n;
			}
			if (namerge == 0)
				continue;
			mul = mul *namerge;

		//q.push(namerge);
			//for (int i = 0; q.size(); i++) {
			//	ch = q.front();
				//q.pop();
				//cout << ch << endl;
			//}
		}
		v[n].push_back(mul);
	}
	int maxINT = -9875421;
	int nNum= -9875421;
	for (int i = 2; i < 10; i++)
	{
		if (v[i][0] > maxINT)
		{
			maxINT = v[i][0];
			nNum = i;
		}
	}
	answer.push_back(nNum);
	answer.push_back(maxINT);
	
	return answer;
}


 
int main()
{
 
	solution(10);//6,4
	solution(14);//5,8

	return 0;
}