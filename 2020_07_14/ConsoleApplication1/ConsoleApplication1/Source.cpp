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
		cout << "2) new에 의해서 생성자 호출됨 " << endl;

	}
	~po2()
	{
		cout << "3) delete에 의해 소멸자 호출됨" << endl;
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
	cout << "1) malloc - 메모리 할당 끝 :생성자는 불름?" << endl;
	free(ptr3);
	 
	//C++ style 
	po2* ptr4 = new po2();
	cout << "1)malloc -= 메모리 할당끝 : 생성자는 ?" << endl;
	delete (ptr4);

	return 0;
}