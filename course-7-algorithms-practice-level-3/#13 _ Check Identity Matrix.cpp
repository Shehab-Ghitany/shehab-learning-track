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
			Matrix1[i][j] = RandomNumber(0, 1);
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

bool CheckIdentityMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
		
			if (i == j && Matrix1[i][j] != 1)
			{
				cout << "No: matrix is NOT identity";
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0)
			{
				cout << "No: matrix is NOT identity";
					return false;
			}
		}
	}
				cout << "Yes: matrix is identity";
				return true;
}


int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3];


	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;
	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	cout << "Identity Matrix:" << endl;

	PrintMatrixWithRanomNumbers(Matrix, 3, 3);
	cout << endl;

	CheckIdentityMatrix(Matrix, 3, 3);

	cout << endl;

	return 0;
}