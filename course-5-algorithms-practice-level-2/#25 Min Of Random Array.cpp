#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int Readnumber()
{
    int numarrays;

        cout << "Enter Number Of Elements ?" << endl;
        cin >> numarrays;

        return numarrays;
}


int RrandomNumber(int from, int to)
{

    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}

void resultofnumbers(int arr[100],int numarrays)
{

    cout << "\nArray Elements: ";

    for (int i = 0; i < numarrays;i++)
    {
        arr[i] = RrandomNumber(1, 100);
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int PrintMaxnumber(int arr[100], int numarrays)
{

    cout << "\nMax number is : ";

    int Max = arr[0];

    for (int i = 0; i < numarrays; i++)
    {
        if (Max < arr[i])
        {
            Max = arr[i];
        }
        else
        {
            continue;
        }
    }


    return Max;
}


int PrintMinnumber(int arr[100], int numarrays)
{

    cout << "\nMin number is : ";

    int Max = arr[0];

    for (int i = 0; i < numarrays; i++)
    {
        if (Max > arr[i])
        {
            Max = arr[i];
        }
        else
        {
            continue;
        }
    }


    return Max;
}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int num = Readnumber();
    
    resultofnumbers(arr, num);
    
    cout << PrintMaxnumber(arr, num);
    cout << PrintMinnumber(arr, num);

    return 0;
}