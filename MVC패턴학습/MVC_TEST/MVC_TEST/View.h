#pragma once

#include "conio.h"

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
		scanf("%s", sReturn);
	}

	void Wait()
	{
		getch();
	}
};