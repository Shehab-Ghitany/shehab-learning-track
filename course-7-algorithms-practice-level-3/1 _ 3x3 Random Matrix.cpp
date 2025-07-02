#include <iostream>
using namespace std;


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int main() {
	srand((unsigned)time(NULL));

	int by33[3][3];


	cout << "The following is a 3x3 random matrix:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			by33[i][j] = RandomNumber(1, 100);

			if (by33[i][j] < 10 )
			cout << ' ' << by33[i][j] << "\t";
			else
			{
				cout << by33[i][j] << "\t";
			}
		}
		cout << endl;
	}


	return 0;
}