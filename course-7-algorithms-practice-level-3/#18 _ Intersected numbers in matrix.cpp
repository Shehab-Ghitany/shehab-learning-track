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

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			int Num = Matrix1[i][j];
			if (IsNumberExistsInMatrix(Num, Matrix2, 3, 3))
			{
				cout << setw(3) << Num << "\t";
			}
		}
	}

	cout << endl;
}


int main() {
	srand((unsigned)time(NULL));

	//int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	//int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrixWithRanomNumbers(Matrix1, 3, 3);

	cout << endl;

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "Matrix2:" << endl;
	PrintMatrixWithRanomNumbers(Matrix2, 3, 3);

	cout << endl << "Intersected Numbers are:" << endl;
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	return 0;
}