#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


int main(void)
{
	
	int arr[10] = {1,2,4,5,6,6,7,7,7,9 };
 
	cout << "lower_bound(6) : " << lower_bound(arr, arr + 10, 6) - arr  << endl; //4
	cout << "lower_bound(7) : " << lower_bound(arr, arr + 10, 7) - arr  << endl; //6
	cout << "lower_bound(8) : " << lower_bound(arr, arr + 10, 8) - arr  << endl; //9
	cout << "lower_bound(9) : " << lower_bound(arr, arr + 10, 11) - arr  << endl; //9

 
	cout << "upper_bound(6) : " << upper_bound(arr, arr + 10, 6) - arr  << endl; //6
	cout << "upper_bound(7) : " << upper_bound(arr, arr + 10, 7) - arr  << endl; //9
	cout << "upper_bound(8) : " << upper_bound(arr, arr + 10, 8) - arr  << endl; //9
	cout << "upper_bound(9) : " << upper_bound(arr, arr + 10, 10) - arr  << endl; //10
	 
}