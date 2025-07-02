



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

void nestedloops(int n)
{
    for (int i=n; i >= 1;i--)
    {
        cout << endl;
        char letter = 'A' + (i - 1);
        for (int j = 1; j <= i; j++)
        {

            cout << letter;

        }
    }
}

int main()
{

    nestedloops(ReadPositiveNumber("Please enter number"));

    return 0;
}