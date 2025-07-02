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

int ReadValidNumber()
{
	int Number;
	cout << "Enter the Number to look for in matrix ?  ";
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

bool IsNumberExistsInMatrix(int Num, int Matrix1[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Num == Matrix1[i][j])
			{
				return true;
			}
		}
	}
				return false;
}


int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;

	int Num = ReadValidNumber();
	if (IsNumberExistsInMatrix(Num,Matrix1, 3, 3))
	{
		cout << "Yes it is there.";
	}
	else
	{
		cout << "No It's Not there.";
	}
	
	cout << endl;

	return 0;
}