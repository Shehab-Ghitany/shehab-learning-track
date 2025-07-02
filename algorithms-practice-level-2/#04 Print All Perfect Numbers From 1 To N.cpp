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


bool CheckifsumPerfectornot(int n)
{
	int sum = 0;
	for (int i =1 ; i <n ; i ++)
	if (n % i == 0)
	{
		sum += i;
	}

	return sum== n ;
}

/*void PrintPerfectornot(int n)
{
	if (CheckifsumPerfectornot(n))
	{
		cout << n << " is Perfect";
	}
	else
	{
		cout << n << " is not Perfect";
	}

}*/


void allPerfectnumbers(int n)
{

	for (int i = 1; i <= n; i++)
	{
		if (CheckifsumPerfectornot(i))
		{
			cout << i << " is Perfect" << endl;
		}/*
		else
			cout << i << " is not perfect" << endl;*/
	}


}


int main()
{

	//PrintPerfectornot(Readnumber("Please enter the number"));

	allPerfectnumbers(Readnumber("Please enter your number"));
    return 0;
}