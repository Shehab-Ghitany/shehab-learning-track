#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int RrandomNumber(int from, int to)
{
    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}


void FillArrays(int arr[100],int &numarrays)
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


void PrintCopyarray(int arr[100], int numarrays , int arrcopy[100])
{
    for (int i = 0; i < numarrays; i++)
    {
        arrcopy[i] = arr[i];
    }

}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int arrcopy[100];
    int numarrays;
    
    FillArrays(arr, numarrays);


    cout << "\nArray Elements :";
    Printarry(arr, numarrays);


    PrintCopyarray(arr, numarrays, arrcopy);

    cout << "\nNumbers after Copy :";
    Printarry(arrcopy, numarrays);

    return 0;
}