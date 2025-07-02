#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void FillArrays(int arr[100], int& arrLength)
{
    arrLength = 10;

        arr[0] = 10;
        arr[1] = 10;
        arr[2] = 10;
        arr[3] = 50;
        arr[4] = 50;
        arr[5] = 70;
        arr[6] = 70;
        arr[7] = 70;
        arr[8] = 70;
        arr[9] = 90;
}

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Addnumbertoarr(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return true;
    }
    return false;
}


void addDistinctNumberstoNewArray(int arr[100], int arrcopy[100], int arrLength, int &arrcopyLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (!IsNumberInArray(arr[i], arrcopy, arrcopyLength))
        {
            Addnumbertoarr(arr[i], arrcopy, arrcopyLength);
        }
    }

}



int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int arrcopy[100];
    int arrLength = 0;
    int arrcopyLength = 0;

    FillArrays(arr, arrLength);

    cout << "Array 1 elements\n";
    PrintArray(arr, arrLength);

    addDistinctNumberstoNewArray(arr, arrcopy, arrLength, arrcopyLength);

    cout << "\nArray Distinct elements:\n";
    PrintArray(arrcopy, arrcopyLength);


    return 0;
}



