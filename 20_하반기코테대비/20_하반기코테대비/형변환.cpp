#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

 
int main()
{
	//String<->char , char<->int, 

	//string -> int
	string s1;
	int n1 = stoi(s1);
	//int - >string
	int n2;
	string s2 = to_string(n2);


	//char->string
	char ch1[] = { "jiji" };
	char *ch2="123";
	string s3(ch1);
	string s4(ch2);

	//string ->char


	//char -> int
	char ch3;
	int num = ch3 - '0';
	
	return 0;
}