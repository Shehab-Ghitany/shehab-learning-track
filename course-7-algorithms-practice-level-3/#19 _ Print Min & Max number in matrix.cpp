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
			Matrix1[i][j] = RandomNumber(0, 100);
		}
	}
}

void PrintMatrixWithRanomNumbers(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix1[i][j] << '\t';
		}
		cout << endl;
	}
}

int PrintMinimumNumber(int Matrix1[3][3], short Rows, short Cols)
{
	int MinNum = Matrix1[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (MinNum > Matrix1[i][j])
			{
				MinNum = Matrix1[i][j];
			}
		}
	}
	return MinNum;
}

int PrintMaximumNumber(int Matrix1[3][3], short Rows, short Cols)
{
	int MaxNum = Matrix1[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (MaxNum < Matrix1[i][j])
			{
				MaxNum = Matrix1[i][j];
			}
		}
	}
	return MaxNum;
}


int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;
	cout << "Minimum Number is: " << PrintMinimumNumber(Matrix1, 3, 3);

	cout << endl << endl;
	cout << "Maximum Number is: " << PrintMaximumNumber(Matrix1, 3, 3);

	cout << endl;

	return 0;
}