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


int CountF(int n, int f)
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


void PrintDigits(int cf)
{

    for (int i = 0; i <= 9; i++)
    {
        short Digit = 0;
        Digit = CountF(cf, i);

        if (Digit > 0)
        {
            cout << "Digit " << i << " Frequency is "
                << Digit << "Time(s)." << endl;

        }


    }

}



int main()
{
    PrintDigits(Readnumber("Please enter the number : "));


    return 0;
}