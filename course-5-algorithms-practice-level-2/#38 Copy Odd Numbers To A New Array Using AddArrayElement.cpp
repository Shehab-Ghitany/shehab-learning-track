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

void PrintCopyarray(int arr[100], int arrcopy[100],int arrLength, int& arrcopylength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (oddoreven(arr[i]) == enoddeven::Odd)
        {
            AddArrayElement(arr[i], arrcopy, arrcopylength);
        }
        else
        {
            continue;
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