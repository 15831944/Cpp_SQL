#pragma once

class Model
{
private:
	char* m_sData;

public :
	Model();
	~Model();

public:
	char* GetData()
	{
		return m_sData;
	}

	void SetData(char* sData)
	{
		m_sData = sData;
	}

};
