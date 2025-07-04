#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct stDate
{
    int day = 0;
    int month = 0;
    int year = 0;
};


int ReadNumber(string M)
{
    int Number;
    cout << M;
    cin >> Number;
    return Number;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.day = ReadNumber("Please enter a Day? ");
    Date.month = ReadNumber("Please enter a Month? ");
    Date.year = ReadNumber("Please enter a Year? ");

    return Date;
}

bool IsLeapYearOrNot(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int HowManyDaysInMonth(int nYear, int nMonth)
{
    if (nMonth < 1 || nMonth>12)
        return 0;

    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (nMonth == 2) ? (IsLeapYearOrNot(nYear) ? 29 : 28) : NumberOfDays[nMonth - 1];

}

void IncreaseDateByOneDay(stDate Date)
{
    cout << "Date after adding one day is: ";

    if (Date.day == HowManyDaysInMonth(Date.year, Date.month))
    {
        Date.day = 1;
        Date.month++;

        if (Date.month == 13)
        {
            Date.month = 1;
            Date.year++;
        }
    }
    else
    {
        Date.day++;
    }

    cout << Date.day << '/' << Date.month << '/' << Date.year << endl;

}

int main()
{
    stDate Date1 = ReadFullDate();

    cout << endl;

    IncreaseDateByOneDay(Date1);

    system("pause>0");
    return 0;
}
