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

string IsLeapYearOrNot(int year)
{
    string s = "";

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        return s = "Yes, Year ["+to_string(year) + "] is a leap year.";
    }
    else
    {
        return s = "no, Year [" + to_string(year) + "] is not a leap year.";
    }
}

int main()
{
    char re = 'n';
    do {
        cout << IsLeapYearOrNot(ReadNumber()) << endl;
        cout << endl << "do you want to repeat again ?" << endl;
        cin >> re;
        cout << endl ;
    } while (re == 'y');

    return 0;
}
