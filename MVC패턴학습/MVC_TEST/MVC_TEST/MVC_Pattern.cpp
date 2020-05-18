// MVC_Pattern.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h";

#include "Controller.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Controller* insController = new Controller();

	insController->Start();

	return 0;
}

