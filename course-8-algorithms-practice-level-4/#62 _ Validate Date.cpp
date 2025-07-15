#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable : 4996)

enum enCompareDate { Before = -1, Equal = 0, After = 1 };

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

    Date.day = ReadNumber("\nPlease enter a Day? ");
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


bool IsValidateDate(stDate Date)
{
    if (Date.day <= 0 || Date.month <= 0 || Date.year <= 0)
    {
        return false;
    }

    if (Date.day > HowManyDaysInMonth(Date.year, Date.month) || Date.month > 12)
    {
        return false;
    }

    return true;
}


void PrintResults()
{
    stDate Date= ReadFullDate();

    if (IsValidateDate(Date))
    {
        cout << endl << "Yes, Date is a valid date.";
    }
    else
    {
        cout << endl << "No, Date is Not a valid date.";
    }

}

int main()
{
    PrintResults();

    return 0;
}
