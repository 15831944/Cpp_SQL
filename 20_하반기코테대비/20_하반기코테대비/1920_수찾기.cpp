
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#define MAX 100001
#pragma warning(disable: 4996)
 
using namespace std;
 


int arr[MAX];
void binary_search_Func(int n, int key)
{
	int left = 0;//0
	int right = n - 1; //4
	int mid = 0;
	while (right - left >= 0)
	{
		mid = (right + left) / 2;
		if (arr[mid] == key)
		{
			printf("1\n");
			return;
		}
		else if (arr[mid] > key)
		{
			right = mid -1 ;
			
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}

	}
	printf("0\n");
	return;

}
int main()
{
 
	int tmp; int n, m;
	scanf("%d", &n);

	for (int i = 0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);   //quick sort를 이용해 배열 오름차순으로 정렬

						  //입력
	scanf("%d", &m);

	for (int i = 0; i<m; i++) {
		
		scanf("%d", &tmp);
		binary_search_Func(n, tmp);
	}

	 
	return 0;
}