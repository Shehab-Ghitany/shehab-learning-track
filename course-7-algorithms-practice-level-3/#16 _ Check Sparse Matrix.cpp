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

int ReadValidNumber()
{
	int Number;
	cout << "Enter the Number to count in matrix ?  " ;
	cin >> Number;

	while (cin.fail())
	{

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid one:" << endl;

		cin >> Number;
	}
	return Number;
}

bool CheckIfSparceMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	short CounterNum = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == 0)
			{
				CounterNum++;
			}
	
		}
	}

	if (CounterNum > 4)
	{
		return true;
	}
	else
	{
		return false;
	}

}


int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;

	if (CheckIfSparceMatrix(Matrix1,3,3))
	{
		cout << "Yes: It is Sparce.";
	}
	else
	{
		cout << "No: It's Not Sparce.";
	}

	return 0;
}
