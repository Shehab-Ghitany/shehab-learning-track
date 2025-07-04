#include <iostream>
using namespace std;


int main()
{
	int F1 = 0, F2 = 1, F3 = 0;

	cout << F2 << "\t";

	for (int i = 0; i < 15; i++)
	{
		F3 = F1 + F2;

		cout << F3 << "\t";

		F1 = F2;
		F2 = F3;
	}

	cout << endl;

	return 0;
}