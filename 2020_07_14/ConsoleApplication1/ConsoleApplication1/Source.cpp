#include <iostream>

using namespace std;
struct  Po
{
	int a;
	int b;
};

class po2
{
public:
	po2()
	{
		cout << "2) new�� ���ؼ� ������ ȣ��� " << endl;

	}
	~po2()
	{
		cout << "3) delete�� ���� �Ҹ��� ȣ���" << endl;
	}

};

int main()
{
	//C style
	Po* ptr = (Po*)malloc(sizeof(Po));
	free(ptr);

	//C++ style
	Po* ptr2 = new Po;
	delete ptr2;

	//C style
	po2* ptr3 = (po2*)malloc(sizeof(po2));
	cout << "1) malloc - �޸� �Ҵ� �� :�����ڴ� �Ҹ�?" << endl;
	free(ptr3);
	 
	//C++ style 
	po2* ptr4 = new po2();
	cout << "1)malloc -= �޸� �Ҵ糡 : �����ڴ� ?" << endl;
	delete (ptr4);

	return 0;
}