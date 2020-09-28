#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/lecture/18230?tab=note&speed=1.5
https://wantairpod.tistory.com/manage/newpost/?type=post&returnURL=%2Fmanage%2Fposts%2F
ют╥б
15
*/
using namespace std;

 

int main()
{
	int num;
	cin >> num;
	int count = 1;
	num--;
	int cnt = 0;
	while (num>0)
	{
		count++;
		num -= count;
		if (num%count == 0)
		{
			for (int i = 0; i < count; i++)
			{
				//cout << (num / count) + i;
			}
			cnt++;
		}
	}
	cout << cnt;
 
	return 0;
}