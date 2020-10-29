#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
2
6
6 2 11 0 3 5
6 3 0 9 0 5
*/
vector<int> v;
int ans = 0;
void solution(int day, int width, int **blocks)
{
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	//1일차
	for (int i = 0; i< day; i++) // day 만큼 돈다.
	{
		if (i>0)
		{
			for (int t = 0; t < width; t++)
			{
				blocks[i][t] = blocks[i - 1][t] + blocks[i][t];
			}
		}
		int now = blocks[i][0];
		int maxNum = blocks[i][0];
		int tempNum;
		for (int j = 1; j<width; j++)
		{
			if (now <= blocks[i][j])
			{
				//cout << "j값 : " <<j <<endl;
				//max = 6 
				//cout<<"max 넘버 : "<< maxNum <<endl;
				for (int w = 0; w<j; w++)
				{
					if (maxNum > blocks[i][w])
					{
						ans += maxNum - blocks[i][w];
						blocks[i][w] = maxNum;
						//	cout << "ans : " << ans << endl;

					}
				}

				maxNum = blocks[i][j];
				tempNum = j;
				now = blocks[i][j];


			}
			else if (j == width - 1)
			{

				int tempMax = 0;
				for (int w = tempNum + 1; w<width; w++)
				{
					if (tempMax<blocks[i][w])
					{
						tempMax = blocks[i][w];
					}
				}

				for (int w = tempNum + 1; w<width; w++)
				{
					if (tempMax > blocks[i][w])
					{
						ans += tempMax - blocks[i][w];
						blocks[i][w] = tempMax;
					}
					//cout << "후처리 ans : " << ans << endl;
				}
			}
			if (maxNum < blocks[i][j])
			{
				maxNum = blocks[i][j];
			}
		}
	}
	for (int i = 0; i < day; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//	cout <<blocks[i][j] <<" ";	
		}
		//cout<<endl;

	}
	cout << ans << endl;
}

struct input_data {
	int day;
	int width;
	int **blocks;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.day;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.width;

	inputData.blocks = new int*[inputData.day];
	for (int i = 0; i < inputData.day; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.blocks[i] = new int[inputData.width];
		for (int j = 0; j < inputData.width; j++) {
			iss >> inputData.blocks[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}