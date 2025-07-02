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


int ReverseNumber(int Number)
{
    


    int Remainder = 0;  
    int Number2 = 0;    

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }

    return Number2;
}

void theend(int number , int number2)
{
    
    if (number != number2)
    {
        cout << endl << "No ,it is Not a Palindrome number ." << endl;
    }
    else
        cout << endl << "yes ,it is a Palindrome number ." << endl;

}




int main()
{
    int n = ReadPositiveNumber("Please enter the number : ");
    int r = ReverseNumber(n);

    theend(n,r);
    cout << endl;

    return 0;
}