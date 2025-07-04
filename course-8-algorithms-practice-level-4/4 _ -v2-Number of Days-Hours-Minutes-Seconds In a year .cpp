#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string M)
{
    int Number;
    cout << M;
    cin >> Number;
    return Number;
}

bool IsLeapYearOrNot(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int HowManyDays(int nYear)
{
   return IsLeapYearOrNot(nYear) ? 366 : 365;
}

int HowManyHours(int nYear)
{
    return HowManyDays(nYear) * 24;
}

int HowManyMinutes(int nYear)
{
    return HowManyHours(nYear) * 60;
}

int HowManySeconds(int nYear)
{
    return HowManyMinutes(nYear) * 60;
}


void PrintResults()
{
        int year = ReadNumber("Please enter a year to check?  ");
            
        cout << endl << "Number of Days    in Year [" << year << "] is " << HowManyDays(year) << endl;
        cout << "Number of Hours   in Year [" << year << "] is " << HowManyHours(year)<< endl;
        cout << "Number of Minutes in Year [" << year << "] is " << HowManyMinutes(year) << endl;
        cout << "Number of Seconds in Year [" << year << "] is " << HowManySeconds(year) << endl;

}

int main()
{
    char re = 'n';
    do {

        PrintResults();

        cout << endl << endl << string(5, '-') << " do you want to repeat again ? " << string(6, '-') << endl;
        cin >> re;
        cout << endl ;
    } while (re == 'y');

    return 0;
}
