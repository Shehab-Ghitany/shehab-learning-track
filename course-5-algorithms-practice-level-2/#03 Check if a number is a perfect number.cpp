#include <iostream>
#include <string>
using namespace std;

enum enPerfect { Perfect = 1, notPerfect = 2 };


int Readnumber(string Message)
{
	int number;

	do
	{
		cout << Message << endl;
		cin >> number;
	} while (number <= 0);

	return number;
}


int CalcusumnumberstoknowPerfect(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
		{
			sum += i;
		}

	return sum;
}

enPerfect CheckifsumPerfectornot(int n)
{

	if (CalcusumnumberstoknowPerfect(n) == n)
	{
	return	enPerfect::Perfect;
	}
	else
		return enPerfect::notPerfect;

}


void PrintPerfectornot(int n)
{
	if (CheckifsumPerfectornot(n) == enPerfect::Perfect)
	{
		cout << n << " is Perfect\n";
	}
	else
	{
		cout << n << " is not Perfect\n";
	}

}


int main()
{

	PrintPerfectornot(Readnumber("Please enter the number"));

    return 0;
}