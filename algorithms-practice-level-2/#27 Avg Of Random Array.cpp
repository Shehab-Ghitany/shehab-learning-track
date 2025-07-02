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

float PrintAvenumber(int arr[100], int numarrays)
{

    cout << "\nAve numbere is : ";

    float sum = 0;

    for (int i = 0; i < numarrays; i++)
    {
        sum += arr[i];
    }

    float Ave = sum / numarrays;

    return Ave;
}


int main()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int num = Readnumber();
    
    resultofnumbers(arr, num);
    
    cout << PrintAvenumber(arr, num);

    return 0;
}