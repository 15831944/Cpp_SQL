#pragma once

#include "conio.h"
#include <iostream>
#include <stdio.h>

class View
{
public:
	View(void);
	~View(void);

	void ShowMessage(char *sMessage)
	{

		printf("%s\n", sMessage);
	}

	void ShowInputData(char* sReturn )
	{
		scanf_s("%s", sReturn);
	}

	void Wait()
	{
		 
	}
};