#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enPrime { Prime = 1, notPrime = 2 };

enPrime funPrime(int num)
{

    int m = num / 2;

    for (int i = 2; i <= m;i++)
    {
        if (num % i == 0)
            return enPrime::notPrime;
    }
    return enPrime::Prime;
}


int RrandomNumber(int from, int to)
{
    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}


void FillArrays(int arr[100], int& arrlength)
{
    cout << "Enter Number Of Elements ?" << endl;
    cin >> arrlength;

    for (int i = 0; i < arrlength;i++)
        arr[i] = RrandomNumber(1, 100);
}


void Printarry(int arr[100], int& arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

}


void PrintCopyarray(int arrlength, int arrcopy[100])
{


    for (int i = 0; i < arrlength; i++)
    {
        arrcopy[i] = RrandomNumber(1, 100);
    }

}

void Sumarrays(int arr[100], int arrcopy[100],int arrlength)
{
    int sum = 0;

    for (int i = 0; i < arrlength; i++)
    {
       sum = arr[i] + arrcopy[i];
    cout << sum << " ";
    }

}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int arrcopy[100];
    int arrlength;

    FillArrays(arr, arrlength);


    cout << "\nArray Elements : ";
    Printarry(arr, arrlength);

    PrintCopyarray(arrlength, arrcopy);

    cout << "\nNumbers after Copy : ";
    Printarry(arrcopy, arrlength);

    cout << "\nSum of Array1 and Array2 elements : ";
    Sumarrays(arr, arrcopy, arrlength);

    return 0;
}