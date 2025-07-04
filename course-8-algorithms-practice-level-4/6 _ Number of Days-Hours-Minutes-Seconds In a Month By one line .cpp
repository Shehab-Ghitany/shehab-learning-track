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


int HowManyDaysInMonth(int nYear , int nMonth)
{
    if (nMonth < 1 || nMonth>12)
        return 0;

    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (nMonth == 2) ? (IsLeapYearOrNot(nYear) ? 29 : 28) : NumberOfDays[nMonth - 1];

}

int HowManyHours(int nYear,int nMonth)
{
    return HowManyDaysInMonth(nYear,nMonth) * 24;
}

int HowManyMinutes(int nYear,int nMonth)
{
    return HowManyHours(nYear,nMonth) * 60;
}

int HowManySeconds(int nYear,int nMonth)
{
    return HowManyMinutes(nYear,nMonth) * 60;
}


void PrintResults()
{
        int year = ReadNumber("Please enter a year to check?  ");
        int Month = ReadNumber("\nPlease enter a month to check?  ");

        cout << endl;
        cout << "Number of Days    in Month [" << year << "] is " << HowManyDaysInMonth(year, Month) << endl;
        cout << "Number of Hours   in Month [" << year << "] is " << HowManyHours(year, Month) << endl;
        cout << "Number of Minutes in Month [" << year << "] is " << HowManyMinutes(year, Month) << endl;
        cout << "Number of Seconds in Month [" << year << "] is " << HowManySeconds(year, Month) << endl;

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
