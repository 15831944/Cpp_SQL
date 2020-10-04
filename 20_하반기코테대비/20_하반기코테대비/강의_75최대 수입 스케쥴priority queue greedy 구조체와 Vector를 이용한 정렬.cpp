#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
//클래스는 상속,
struct Data
{
	int money;
	int when;
	//생성자.
	Data(int a, int b)
	{
		money = a;
		when = b;
	}
	//정렬기준 Data &b 라는 것은 뒷쪽 데이터라는 뜻
	bool operator<(Data &b)
	{
		// when : 객체의 자기변수(=this), 앞에 것으로 기준으로 정렬 
		return when > b.when;
	}
};



int main()
{
	int n, a, b, res = 0, max = 98654321;
	vector<Data> T;
	priority_queue<int> pq;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		//생성자 호출
		T.push_back(Data(a, b));
		if (b > max)
			max = b;
	}
	for (int i = max; i >= 1; i--)
	{
		for (int j =0 ; j < n; j++)
		{
			if (T[j].when < i)break;
			pq.push(T[j].money);
		}
		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}

	}
	//cout << res << endl;
	return 0;
}