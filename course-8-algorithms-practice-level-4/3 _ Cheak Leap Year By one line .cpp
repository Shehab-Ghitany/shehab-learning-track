#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Enter a Number?  ";
    cin >> Number;
    return Number;
}

bool IsLeapYearOrNot(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? true : false;
}

int main()
{
    char re = 'n';
    do {
        int year = ReadNumber();

        if (IsLeapYearOrNot(year))
        {
            cout << "Yes, Year [" << year << "] is a leap year.";
        }
        else
        {
            cout << "no, Year [" << year << "] is not a leap year.";
        }

        cout << endl << endl << "do you want to repeat again ?" << endl;
        cin >> re;
        cout << endl ;
    } while (re == 'y');

    return 0;
}
