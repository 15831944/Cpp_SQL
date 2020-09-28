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
	int* ptr = new int;//ptr은 힙에서 4바이트로 할당됨.
	int* array = new int[10];//array는 힙에서 40바이트로 할당됨.

	//차례로 선언했지만 순차적 메모리 주소를 갖는 것은 아님
	int* ptr1 = new int;
	int* ptr2 = new int;

	//콜 스택 ex
	func();
	func2();
	func3();


	

}
 