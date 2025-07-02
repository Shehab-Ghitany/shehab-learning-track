#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int RrandomNumber(int from, int to)
{
    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}


int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void FillArrays(int arr[100], int arrlength)
{
    for (int i = 0; i < arrlength;i++)
        arr[i] = i + 1;
}



void ShuffleArrays(int arr[100], int arrlength)
{

    for (int i = arrlength - 1; i > 0;i--)
    {
        int j = RrandomNumber(0, i);

        int temp = arr[i];

        arr[i] = arr[j];

        arr[j] = temp;

    }

}



void Printarray(int arr[100], int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int arrlength = ReadPositiveNumber("Enter Number Of Elements ?");


    FillArrays(arr, arrlength);

    cout << "\nArray Elements before shuffle : ";
    Printarray(arr, arrlength);

    ShuffleArrays(arr, arrlength);

    cout << "\nArray Elements after shuffle : ";
    Printarray(arr, arrlength);

    
    return 0;
}