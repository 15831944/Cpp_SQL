#include <iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;

int main(void)
{
	vector<string> words = { "BlockDmask","banana","code","program" };
	int len = static_cast<int>(words.size());

	ifstream readFromFile("12141.txt");

	if (readFromFile.is_open())
	{
		//���ȳ� ������ �����Ѵ�.
		//���� �ܾ� ����
		words.clear();

		while (!readFromFile.eof())
		{

			string tmp;
			getline(readFromFile, tmp);
			words.push_back(tmp);
		}

		readFromFile.close();

	}
	else
	{
		//������ ����? ���ο� ���� ������ְ� ���ôܾ�ֱ�
		//is_open�� false�� ���� ������ ���ų�, �ش� ���Ͽ� ���� �Ұ��� ���
		ofstream writeToFile;
		writeToFile.open("1241.txt");

		for (int i = 0; i < len; i++)
		{
			string tmp = words[i];
			if (i != len - 1)
			{
				tmp += "\n"; //������ �ܾ� ���� ���Ϳ� �־��ֱ� 
			}

			writeToFile.write(tmp.c_str(), tmp.size());
		}
		writeToFile.close(); //���Ϥ� ������ 
	}



	return 0;
}