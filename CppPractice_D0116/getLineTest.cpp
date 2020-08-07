#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main()
{

	wcout.imbue(locale("kor"));//한국으로 지역설정
	wcin.imbue(locale("kor"));
	wstring str1;
	 



	string s;
	getline(wcin, str1);

	wchar_t name[20];
	wchar_t dessert[20];
	wchar_t asdf[500];
	char asdff[500];



	string str;
	wstring str2; 

	wcout << "name" << endl;
	wcin.getline(name, 20);
	wcout << "dessert" << endl;
	wcin.getline(dessert, 20);
 
 
	wcout << "good" << dessert;
	wcout << "dessert " << name << "sir " << endl;




	return 0;
}