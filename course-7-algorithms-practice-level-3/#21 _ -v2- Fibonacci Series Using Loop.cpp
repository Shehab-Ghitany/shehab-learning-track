#include <iostream>
using namespace std;


void PrintFibonacciUsingLoop(short Number)
{
	int F1 = 0, F2 = 1, F3 = 0;

	cout << F1 << '\t' << F2 << '\t';

	for (int i = 0; i < Number - 2; i++)
	{
		F3 = F1 + F2;

		cout << F3 << "\t";

		F1 = F2;
		F2 = F3;
	}

	cout << endl;


}

int main()
{

	PrintFibonacciUsingLoop(10);

	return 0;
}