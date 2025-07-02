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
        arr[i] = RrandomNumber(1, 100);
}


void Printarry(int arr[100], int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

}


int numbersearchfor(int arr[100], int arrlength, int numsearch)
{

    for (int i = 0;i < arrlength;i++)
    {
        if (numsearch == arr[i])
        {
            return i;
        }
    }
    return -1;
}

void Printsearchresult(int index, int numsearch)
{
    cout << "\nNumber you are loking for is : " << numsearch;

    if (index != -1)
    {
        cout << endl << "The number found at position : " << index;
        cout << endl << "The number found it's order : " << index + 1 << endl;
    }
    else
    {
        cout << "\nThe number is not found :-(\n";
    }

}

void SearchNumberInArray(int arr[100], int arrlength)
{
    int numsearch;

    cout << "\nPlease enter the number to search for? \n";
    cin >> numsearch;

    int index = numbersearchfor(arr, arrlength, numsearch);
    Printsearchresult(index, numsearch);
}



int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrlength = ReadPositiveNumber("Please enter number of array elements : ");

    FillArrays(arr, arrlength);

    cout << "Array1 elements : ";
    Printarry(arr, arrlength);

    SearchNumberInArray(arr, arrlength);

    return 0;
}