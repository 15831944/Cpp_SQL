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
		//열렸네 파일이 존재한다.
		//예제 단어 삭제
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
		//파일이 없네? 새로운 파일 만들어주고 예시단어를넣기
		//is_open이 false인 경우는 파일이 없거나, 해당 파일에 접근 불가인 경우
		ofstream writeToFile;
		writeToFile.open("1241.txt");

		for (int i = 0; i < len; i++)
		{
			string tmp = words[i];
			if (i != len - 1)
			{
				tmp += "\n"; //마지막 단어 뺴고 엔터에 넣어주기 
			}

			writeToFile.write(tmp.c_str(), tmp.size());
		}
		writeToFile.close(); //파일ㄷ ㅏㄷ기 
	}



	return 0;
}