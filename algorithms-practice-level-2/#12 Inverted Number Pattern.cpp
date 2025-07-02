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
    for (i; i >= 0;i--)
    {
    cout << endl;
        for (int c = i; c > 0; c--)
        {
            int j = i;

            cout << j;
        }
    }
}

int main()
{

    nestedloops(ReadPositiveNumber("Please enter number"));

    return 0;
}