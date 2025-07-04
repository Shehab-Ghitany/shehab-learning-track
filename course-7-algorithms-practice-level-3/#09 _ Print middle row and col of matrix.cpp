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

void PrintMidRowOfMatrix(int by33[3][3], short Rows, short Cols)
{

	for (int i =1; i < Rows; i++)
	{
		for (int j =0; j < Cols; j++)
		{
			printf("%0*d\t", 2, by33[i][j]);
		}
		cout << endl;
	}
}

void PrintMidColOfMatrix(int by33[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 1; j < Cols; j++)
		{
			printf("%0*d\t", 2, by33[i][j]);
		}
	}
		cout << endl;
}


int main() {
	srand((unsigned)time(NULL));

	int by33[3][3], by33_2[3][3], Mul[3][3];


	FillMatrixWithRandomNumbers(by33, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(by33, 3, 3);

	cout << endl;

	cout << "Middle Row of Matrix1 is: " << endl;
	PrintMidRowOfMatrix(by33, 2, 3);

	cout << endl;

	cout << "Middle Col of Matrix1 is: " << endl;
	PrintMidColOfMatrix(by33, 3,2);



	return 0;
}