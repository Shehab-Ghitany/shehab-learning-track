#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int Matrix1[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix1[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixWithRanomNumbers(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d\t", 2, Matrix1[i][j]);
		}
		cout << endl;
	}
}

int PrintSumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int SumAllDijits = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			SumAllDijits += Matrix1[i][j];
		}
	}

	return SumAllDijits;
}

bool CheckMatricesEquality(int Matrix1[3][3], int Matrix2[3][3])
{
	int M1 = PrintSumOfMatrix(Matrix1, 3, 3);
	int M2 = PrintSumOfMatrix(Matrix2, 3, 3);

	cout << endl;

	if (M1 != M2)
	{
		cout << "No: matrices are NOT equal.";
		return false;
	}
	else
	{
		cout << "Yes: matrices are equal.";
		return true;
	}

}


int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];


	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "Matrix2:" << endl;
	PrintMatrixWithRanomNumbers(Matrix2, 3, 3);

	CheckMatricesEquality(Matrix1, Matrix2);
	cout << endl;

	return 0;
}