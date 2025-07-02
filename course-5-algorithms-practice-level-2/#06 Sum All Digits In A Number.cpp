#include <iostream>
#include <string>
using namespace std;



int Readnumber()
{
    int n;

    cout << "Please Type anything to (Reverse) it  : " << endl;
    cin >> n;

    return n;
}


void PrintReverse(int n)
{
    int Remainder = 0;
    int sum = 0;

    while (n > 0)
    {
        Remainder = n % 10;
        n = n / 10;
        sum += Remainder;
    }    

    cout << endl << "Sum Of Digits = " << sum << endl;
}


int main()
{

    PrintReverse(Readnumber());

    return 0;
}