#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct tagData
{
	char ID[20];
	char Password[20];
	int option;
};

struct Point {
	int x;
	int y;
};
 

struct Point2D
{
	int x;
	int y;

};

struct Point2
{
	int x;
	int y;

};

int main()
{

	char str[] = "hello world";
	str[3] = '3';
	cout << str << endl;

	char *str2 = "hello world"; //error
	str2[3] = '3';
	
	int num1 = 10;
	int &num2 = num1; 
	num2 += 10; //num1,2 ��� 20���� ��ȯ
	num1 -= 10;
	
	

	int a = 10;  
	int *ppp = &a;  //�����ͺ������� �ּҰ��� �Ҵ��.  
	int &r = a;   //���۷������� ��������� �״�� �Ҵ���.

	struct Point2 *aaa = NULL;
 
	if (aaa)
	{
		aaa->x = 120;
		aaa->y = 240;
	}
	else
		cout << "aaa is null" << endl;
	



	//struct ���� �޸� �Ҵ�
	struct Point p1 = { 1,2 };
	struct Point* p2 = &p1;
	struct Point* p3 = &p1;
	p2->x = 2;
	p2->y = 3;

	//tagData *p = new tagData[3];
	tagData *z = new tagData();
	struct Point2D *p[3];

	//p[0].option = 10;
	for (int i = 0; i < 3; i++)
	{
		cout << i << " : insert ID" << endl;
		cin >> z[i].ID;
		cout << i << " : insert PW" << endl;
		cin >> z[i].Password;
		cout << i << " : option" << endl;
		cin >>z[i].option;
		
	}

	cout << "Enter a positive integer" << endl;
	int length;
	cin >> length;

	int *arr = new int[length]; //new ������ ��� �迭���̴� ����� �ƴϾ��.
	cout << length << endl;
	
	for (int i = 0; i < length; i++)
	{
		int b;
		cin >> b;
		arr[i] = b;
	}

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;

	return 0;
}