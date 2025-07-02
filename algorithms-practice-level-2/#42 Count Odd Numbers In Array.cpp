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


void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

enum enoddeven { Even = 1, Odd = 2 };

enoddeven oddoreven(int num)
{
    int result = num % 2;

    if (result == 0)
    {
        return enoddeven::Even;
    }
    else
    {
        return enoddeven::Odd;
    }
}


int PrintOddNumbers(int arr[100], int arrLength)
{
    int c=0;

    for (int i = 0; i < arrLength; i++)
    {
        if (oddoreven(arr[i]) == enoddeven::Odd)
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


    cout << endl  << "Odd Numbers count is : " << PrintOddNumbers(arr, arrLength);

    return 0;
}



