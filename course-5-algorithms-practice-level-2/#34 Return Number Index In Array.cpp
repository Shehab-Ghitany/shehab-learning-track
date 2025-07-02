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



void FindAndPrintElement(int arrayelement[100], int numarrays)
{
    int c = 0;
    int checknumber = 0;
    string non = " ";

    cout << "\nPlease enter the number to search for? \n";
    cin >> checknumber;

    for (int i = 0; i < numarrays;i++)
    {
        if (checknumber == arrayelement[i])
        {
            c = i;
        }
        else
            non = "\nThe number is not found :-(\n";
    }

    cout << "\nNumber you are loking for is : " << checknumber;
    if (checknumber == arrayelement[c])
    {

        cout << endl << "The number found at position : " << c;
        cout << endl << "The number found it's order : " << c + 1 << endl;
    }
    else
    {
        cout << non;
    }

}



int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int n = ReadPositiveNumber("Please enter number of array elements : ");

    FillArrays(arr, n);

    cout << "Array1 elements : ";
    Printarry(arr, n);

    FindAndPrintElement(arr, n);


    return 0;  
}