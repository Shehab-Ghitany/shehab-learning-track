#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


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


bool WanttoAddmore()
{
    int add;
    do 
    {
        cout << "Do you want to add more numbers? [0]: No, [1]: Yes? ";
        cin >> add;
    } while (add < 0 || add > 1);

    return add ==1;
}

void ReadArrayFromUser(int arr[100], int& length)
{
    length = 0;

    do
    {
        arr[length] = ReadPositiveNumber("Please enter the number ");

        length++;

    } while (WanttoAddmore() == 1);

}


void PrintArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

}



int main()
{
    srand((unsigned)time(NULL));
    int length;
    int arr[100];

    ReadArrayFromUser(arr, length);

    cout << "\nArray length : " << length << endl;

    cout << "Array Elements : ";
    PrintArray(arr, length);

    return 0;  
}