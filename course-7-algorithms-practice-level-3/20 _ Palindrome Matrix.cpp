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

bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols / 2; j++)
		{
			int R = (Cols - 1) - j;
			if (Matrix1[i][j] != Matrix1[i][R])
			{
				return false;
			}
		}
	}
	return true;
}


int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

	//FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	if (IsPalindromeMatrix(Matrix1, 3, 3))
	{
		cout << endl << "Yes: Matrix is Palindrome" << endl;
	}
	else
	{
		cout << endl << "No: Matrix is NOT Palindrome" << endl;
	}

	return 0;
}