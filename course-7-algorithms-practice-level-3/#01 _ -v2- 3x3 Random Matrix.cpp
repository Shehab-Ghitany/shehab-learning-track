

#include <iostream>
using namespace std;


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int by33[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			by33[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrixWithRanomNumbers(int by33[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << by33[i][j] << "\t";
		}
		cout << endl;
	}


}

int main() {
	srand((unsigned)time(NULL));

	int by33[3][3];


	cout << "The following is a 3x3 random matrix:" << endl;
	FillMatrixWithRandomNumbers(by33);
	PrintMatrixWithRanomNumbers(by33);

	return 0;
}
