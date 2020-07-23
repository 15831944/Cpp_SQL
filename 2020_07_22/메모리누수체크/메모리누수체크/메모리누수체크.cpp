#include <iostream>
//메모리누수 체크 코드
//#include "pch.h"
//#include <Window.h>
#define _CRTDBF_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main()
{
	int* buff = new int[100];
	_CrtDumpMemoryLeaks();

}