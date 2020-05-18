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
		
		insView->ShowMessage("--------------�ƹ����ڳ� �Է��ϼ���------------");
		insView->ShowInputData(insModel->GetData());
		insView->ShowMessage("--------------���------------");
		DataProcessing(insModel->GetData());
		insView->ShowMessage(insModel->GetData());
		insView->ShowMessage("------------------------------");
		insView->Wait();
	}

	void DataProcessing(char* sData)
	{
		int nOneData = 0;

		//�Է¹��� ���� ���ڷ� ��ȯ�Ѵ�.
		nOneData = atoi(sData);

		//���Ѵ�
		nOneData = nOneData * 2;
		
		

		//�������ش�. �Ҵ縸�ϴ°�.
		sprintf(sData, "%d", nOneData);		
		//sprintf(sData, "%d", nOneData);	
		//sprintf(sData, "%d", nOneData);		
		//sprintf(sData, "%d" , 1234567); 
		//return nOneData;
	}	
};

