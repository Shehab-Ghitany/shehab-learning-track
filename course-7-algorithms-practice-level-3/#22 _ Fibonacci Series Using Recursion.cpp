#include <iostream>
using namespace std;


void PrintFibonacciUsingRecursion(short Number)
{
	static int F1 = 0, F2 = 1, F3 = 0;

	F3 = F1 + F2;
	if (2 < Number)
	{
		cout << F3 << "\t";

	F1 = F2;
	F2 = F3;

	PrintFibonacciUsingRecursion(Number-1);
	}

}


int main()
{
	cout << "0\t1\t";
	PrintFibonacciUsingRecursion(11);

	return 0;
}