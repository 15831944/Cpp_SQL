#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

void Func(int k, int n) 
{
	if (k <= 0) { cout << "0보다 큰수만 변환 할수있음" << endl; return; }
	if (n < 2 || n>16) { cout << "2진수부터 16진수까지만 변환이 가능" << endl; return; }
	cout << "숫자" << k << "를" << n << "진수로 변환" << endl;
	cout << k << "->";
	int mok = INT_MAX;
	int namerge;
	stack<int> s;
	int ch;

	while (1) {
		if (mok == 0)break;
		if (mok == INT_MAX) {
			mok = k / n;
			namerge = k%n;
		}
		else {
			namerge = mok %n;
			mok = mok / n;
		}
		s.push(namerge);
	}
}


vector<int> solution(int N)
{
	vector<int> answer;

	return answer;
}

int main()
{
	Func(233, 2);
	//solution(10);//6,4
	//solution(14);//5,8
	
	return 0;
}