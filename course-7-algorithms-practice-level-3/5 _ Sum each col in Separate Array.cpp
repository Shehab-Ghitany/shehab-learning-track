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
			by33[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrixWithRanomNumbers(int by33[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << by33[i][j] << "\t";
		}
		cout << endl;
	}

}

int ColSum(int by33[3][3], short Rows, short Cols)
{
	int sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		sum += by33[i][Cols];
	}
	return sum;
}

void ReadColsSumInArray(int by33[3][3], int arrSum[], short Rows, short Cols)
{
	for (short j = 0; j < Cols; j++)
	{
		arrSum[j] = ColSum(by33, Rows, j);
	}
}

void PrintColsSumArray(int arrSum[], short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		cout << " Col " << i + 1 << " Sum = " << arrSum[i] << endl;
	}

}


int main() {
	srand((unsigned)time(NULL));

	int by33[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(by33, 3, 3);
	cout << "The following is a 3x3 random matrix:" << endl;
	PrintMatrixWithRanomNumbers(by33, 3, 3);

	cout << endl << "The following are the sum of each row in the matrix: " << endl;
	ReadColsSumInArray(by33, arrSum, 3, 3);
	PrintColsSumArray(arrSum, 3);

	return 0;
}