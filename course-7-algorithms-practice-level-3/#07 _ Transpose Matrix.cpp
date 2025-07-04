#include <iostream>
#include <iomanip>
using namespace std;


void FillMatrixWithOrderedNumbers(int by33[3][3], short Rows, short Cols)
{
	int Dijit_1To10=1;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
				by33[i][j] = Dijit_1To10++;
		}
	}
}

void PrintMatrixWithOrderdNumbers(int by33[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << by33[i][j] << "\t";
		}
		cout << endl;
	}

}

void PrintTransposeMatrix(int by33[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << by33[j][i] << "\t";
		}
		cout << endl;
	}

}


int main() {
	srand((unsigned)time(NULL));

	int by33[3][3];


	FillMatrixWithOrderedNumbers(by33, 3, 3);
	cout << "The following is a 3x3 Orderd matrix:" << endl;
	PrintMatrixWithOrderdNumbers(by33, 3, 3);

	cout << "The following is the transpose matrix:" << endl;
	PrintTransposeMatrix(by33, 3, 3);

	return 0;
}