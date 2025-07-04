#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int by33[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			by33[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixWithRanomNumbers(int by33[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d\t", 2, by33[i][j]);
		}
		cout << endl;
	}
}

int PrintSumOfMatrix(int by33[3][3], short Rows, short Cols)
{
	int SumAllDijits = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			SumAllDijits += by33[i][j];
		}
	}

	return SumAllDijits;
}


int main() {
	srand((unsigned)time(NULL));

	int by33[3][3];


	FillMatrixWithRandomNumbers(by33, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(by33, 3, 3);

	cout << endl << "Sum of Matrix is: " << PrintSumOfMatrix(by33, 3, 3);

	return 0;
}