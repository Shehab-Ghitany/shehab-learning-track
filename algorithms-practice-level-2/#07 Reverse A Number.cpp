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


int PrintReverse(int n)
{
    int Remainder = 0;
    int Reverse = 0;

    while (n > 0)
    {
        Remainder = n % 10;
        Reverse = (Reverse * 10) + Remainder;
        n = n / 10;
    }

    return Reverse;
}

int main()
{

    cout << PrintReverse(Readnumber());

    return 0;
}