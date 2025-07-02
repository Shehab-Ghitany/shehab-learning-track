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
        arr[i] = RrandomNumber(-100, 100);
}


void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


int PrintPositiveNumbers(int arr[100], int arrLength)
{
    int c=0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0)
        {
            c++;
        }
    }

    return c;
}


int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = 0;

    FillArrays(arr, arrLength);

    cout << "Array 1 elements\n";
    PrintArray(arr, arrLength);


    cout << endl  << "Positive Numbers count is : " << PrintPositiveNumbers(arr, arrLength);

    return 0;
}