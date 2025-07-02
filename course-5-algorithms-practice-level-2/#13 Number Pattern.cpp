#include <iostream>
#include <string>
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


void nestedloops(int i)
{
    for (int c = 1;c <= i;c++)
    {
    cout << endl;
    for (int j = 1; j <= c; j++)
        {
        cout << c;
        }
    }
}


int main()
{

    nestedloops(ReadPositiveNumber("Please enter number"));

    return 0;
}