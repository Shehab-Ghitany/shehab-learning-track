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

int RowSum(int by33[3][3], short Rows, short Cols)
{
	int sum = 0;

	for (short j = 0; j < Cols; j++)
	{
		sum += by33[Rows][j];
	}
	return sum;
}

void SumInArray(int by33[3][3], short Rows, short Cols)
{
	int arr[3];

	for (short i = 0; i < Rows; i++)
	{
		arr[i] = RowSum(by33, i, Cols);

		cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	int by33[3][3];


	FillMatrixWithRandomNumbers(by33, 3, 3);
	cout << "The following is a 3x3 random matrix:" << endl;
	PrintMatrixWithRanomNumbers(by33, 3, 3);

	cout << endl << "The following are the sum of each row in the matrix: " << endl;
	SumInArray(by33, 3, 3);

	return 0;
}