#include <iostream>
using namespace std;
void func()
{
	cout << "func" << endl;
	 
 }
void func2()
{ 
	cout << "func" << endl;
}
void func3()
{
	cout << "func" << endl;
}

int main()
{ 
	int* ptr = new int;//ptr�� ������ 4����Ʈ�� �Ҵ��.
	int* array = new int[10];//array�� ������ 40����Ʈ�� �Ҵ��.

	//���ʷ� ���������� ������ �޸� �ּҸ� ���� ���� �ƴ�
	int* ptr1 = new int;
	int* ptr2 = new int;

	//�� ���� ex
	func();
	func2();
	func3();


	

}
 