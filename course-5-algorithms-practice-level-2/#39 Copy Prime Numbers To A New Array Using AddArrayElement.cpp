#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int RrandomNumber(int from, int to)
{
    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}




void FillArrays(int arr[100], int& arrLength)
{
    cout << "Enter Number Of Elements ?" << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength;i++)
        arr[i] = RrandomNumber(1, 100);
}


void Printarry(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

}


void AddArrayElement(int number,int arr[100], int& arrLength )
{
    arrLength++;
    arr[arrLength - 1] = number;
}

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


void PrintCopyarray(int arr[100], int arrcopy[100],int arrLength, int& arrcopylength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (funPrime(arr[i]) == enPrime::Prime)
        {
            AddArrayElement(arr[i], arrcopy, arrcopylength);
        }

    }

}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int arrcopy[100];
    int arrLength =0;
    int arrcopylength=0;
    

    FillArrays(arr, arrLength);


    cout << "\nArray Elements :";
    Printarry(arr, arrLength);

    PrintCopyarray( arr, arrcopy, arrLength, arrcopylength);

    cout << "\nNumbers after Copy :";
    Printarry(arrcopy, arrcopylength);

    return 0;
}



