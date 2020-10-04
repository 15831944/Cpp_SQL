#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
//Ŭ������ ���,
struct Data
{
	int money;
	int when;
	//������.
	Data(int a, int b)
	{
		money = a;
		when = b;
	}
	//���ı��� Data &b ��� ���� ���� �����Ͷ�� ��
	bool operator<(Data &b)
	{
		// when : ��ü�� �ڱ⺯��(=this), �տ� ������ �������� ���� 
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
		//������ ȣ��
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