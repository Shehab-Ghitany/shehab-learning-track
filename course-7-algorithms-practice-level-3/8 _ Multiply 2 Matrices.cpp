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
			printf("%0*d\t",2, by33[i][j]);
		}
		cout << endl;
	}
}

void Multiply2Matrices(int Mul[3][3],int by33[3][3], int by33_2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Mul[i][j] = by33[i][j] * by33_2[i][j];
		}
	}
}


int main() {
	srand((unsigned)time(NULL));

	int by33[3][3], by33_2[3][3], Mul[3][3];


	FillMatrixWithRandomNumbers(by33, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(by33, 3, 3);

	cout << endl;

	FillMatrixWithRandomNumbers(by33_2, 3, 3);
	cout << "Matrix2:" << endl;
	PrintMatrixWithRanomNumbers(by33_2, 3, 3);

	cout << endl;

	Multiply2Matrices(Mul, by33, by33_2, 3, 3);
	cout << "Results:" << endl;
	PrintMatrixWithRanomNumbers(Mul, 3, 3);

	return 0;
}