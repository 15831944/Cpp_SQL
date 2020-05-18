#pragma once

#include <stdlib.h>
#include <string.h>

#include "Model.h"
#include "View.h"

class Controller
{
public:
	//Model* insModel;
	//View* insView;

	Controller(void);
	~Controller(void);

	void Start()
	{
		//insModel = new Model();
		//insView = new View();
		View* insView =new View();
		Model* insModel= new Model();
		
		insView->ShowMessage("--------------아무숫자나 입력하세요------------");
		insView->ShowInputData(insModel->GetData());
		insView->ShowMessage("--------------결과------------");
		DataProcessing(insModel->GetData());
		insView->ShowMessage(insModel->GetData());
		insView->ShowMessage("------------------------------");
		insView->Wait();
	}

	void DataProcessing(char* sData)
	{
		int nOneData = 0;

		//입력받은 값을 숫자로 변환한다.
		nOneData = atoi(sData);

		//곱한다
		nOneData = nOneData * 2;
		
		

		//리턴해준다. 할당만하는것.
		sprintf(sData, "%d", nOneData);		
		//sprintf(sData, "%d", nOneData);	
		//sprintf(sData, "%d", nOneData);		
		//sprintf(sData, "%d" , 1234567); 
		//return nOneData;
	}	
};

