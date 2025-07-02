#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void FillArrays(int arr[100], int& arrLength)
{
    arrLength = 6;

        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 30;
        arr[4] = 20;
        arr[5] = 10;
}

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


void CopyArrayAfteRreverse(int arr[100], int arrcopy[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arrcopy[i] = arr[arrLength - 1 - i];
    }

}


bool IsReverseArraysamesourceArray(int arr[100], int arrcopy[100], int arrLength)
{
    CopyArrayAfteRreverse(arr, arrcopy, arrLength);

    for (int i = 0; i < arrLength; i++)
    {
        if (arrcopy[i] != arr[i])
            return false;
    }
    return true;
}


void PrintPalindromeOrNot(int arr[100], int arrcopy[100], int arrLength)
{

    if (IsReverseArraysamesourceArray(arr, arrcopy, arrLength))
    {
        cout << endl << "yes ,it is a Palindrome number ." << endl;
    }
    else
        cout << endl << "No ,it is Not a Palindrome number ." << endl;

}


int main()
{

    int arr[100];
    int arrcopy[100];
    int arrLength = 0;

    FillArrays(arr, arrLength);

    cout << "Array 1 elements\n";
    PrintArray(arr, arrLength);

    CopyArrayAfteRreverse(arr, arrcopy, arrLength);

    cout << "\nArray after Reverse elements:\n";
    PrintArray(arrcopy, arrLength);

    PrintPalindromeOrNot(arr, arrcopy, arrLength);

    return 0;
}