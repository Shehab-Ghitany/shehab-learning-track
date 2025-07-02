#include <iostream>
#include <string>
using namespace std;

enum enPrime { Prime = 1, notPrime = 2 };



enPrime funPrime(int n)
{	
	int m = n / 2;

		for (int i = 2; i <= m;i++)
		{
			if (n % i == 0)
				return enPrime::notPrime;
		}
		return enPrime::Prime;

}


void PrintPrimenumbersto10()
{

	for (int i = 1; i <= 10; i++)
	{
		if (funPrime(i) == enPrime::Prime)
		{
			cout << i << endl;
		}

	}

}


int main()
{

	PrintPrimenumbersto10();

    return 0;
}
