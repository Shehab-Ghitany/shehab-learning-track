#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int RrandomNumber(int from, int to)
{
    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}


void FillArrays(int arr[100], int& numarrays)
{
    cout << "Enter Number Of Elements ?" << endl;
    cin >> numarrays;

    for (int i = 0; i < numarrays;i++)
        arr[i] = RrandomNumber(1, 100);
}


void Printarry(int arr[100], int numarrays)
{
    for (int i = 0; i < numarrays; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

}


void PrintCopyarray(int arr[100], int arr2[100], int numarrays)
{

    for (int i = 0 ; i < numarrays ; i ++ )
    {
        arr2[i] = arr[numarrays - 1 - i];
    }

}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int numarrays;


    FillArrays(arr, numarrays);

    int arr2[100];

    PrintCopyarray(arr, arr2, numarrays);


    cout << "\nArray Elements :";
    Printarry(arr, numarrays);


    cout << "\nNumbers after Reverse :";
    Printarry(arr2, numarrays);

    return 0;
}