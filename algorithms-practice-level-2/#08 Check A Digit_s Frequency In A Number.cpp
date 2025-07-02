#include <iostream>
#include <string>
using namespace std;


int Readnumber(string M)
{
    int n;

    cout << M << endl;
    cin >> n;
    cout << endl;

    return n;
}


int PrintReverse(int n, int f)
{
    int Remainder = 0;
    int cf = 0;

    while (n > 0)
    {

        Remainder = n % 10;
        n = n / 10;

        if (Remainder == f)
        {
            cf++;
        }

    }

    return cf;
}

int main()
{
    int num1 = Readnumber("Enter the number : ");
    int num2 = Readnumber("Frequency = ");

    cout << "Digit " << num2 << " is " << PrintReverse(num1, num2) << " Time(s)";

    return 0;
}