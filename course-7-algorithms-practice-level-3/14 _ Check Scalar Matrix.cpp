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
			Matrix1[i][j] = RandomNumber(0, 10);
		}
	}
}

void PrintMatrixWithRanomNumbers(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%d\t", Matrix1[i][j]);
		}
		cout << endl;
	}
}

bool CheckScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
		
			if (i == j && Matrix1[i][j] != Matrix1[0][0])
			{
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0)
			{
					return false;
			}
		}
	}
				return true;
}


int main() {
	srand((unsigned)time(NULL));

	//int Matrix1[3][3];
	int Matrix1[3][3] = { {3,0,0},{0,3,0},{0,0,3} };

	//FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;

	if (CheckScalarMatrix(Matrix1, 3, 3))
	{
		cout << "Yes: matrix is Scalar.";
	}
	else
	{
		cout << "No: matrix is NOT Scalar.";
	}


	cout << endl;

	return 0;
}