#include <iostream>
#include <string>
using namespace std;



int Readnumber()
{
    int n;

    cout << "Enter the number" << endl;
    cin >> n;
    cout << endl;

    return n;
}


int countDigits(int n)
{
    int c = 0;

    while (n != 0)
    {
        n = n / 10;

        c++;
    }
    return c;
}


void Printnumbers(int c , int n)
{


    int i = c - 1;

    int ii = 1;
    int d = 1;
    for (ii;ii <= c-1;ii++ )
    {
           d *= 10;
    }

    int ii2 = 1;
    for (ii2 ; ii2 <= c ; ii2++)
    {
        int temp = n;

        temp = temp / d;
        d /= 10;

        int Remainder = temp % 10;


        cout << Remainder << endl;
    }


}


int main()
{
    int n = Readnumber();
    Printnumbers(countDigits(n),n);

    return 0;
}