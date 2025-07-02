



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
        char letter = 'A';
    for (int i=1; i <= n;i++)
    {
        cout << endl;
        for (int j = 1; j <= i; j++)
        {

            cout << letter;

        }
        letter++;
    }
}

int main()
{

    nestedloops(ReadPositiveNumber("Please enter number"));

    return 0;
}