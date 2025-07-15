#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable : 4996)


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

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ?
        (Date1.month < Date2.month ? true : (Date1.month == Date2.month ?
            Date1.day < Date2.day : false)) : false);
}


void PrintResults()
{
    cout << "Enter Date1:" << endl;
    stDate Date1 = ReadFullDate();
    cout << "\nEnter Date2:" << endl;
    stDate Date2 = ReadFullDate();

    cout << endl;

    if (IsDate1LessThanDate2(Date1, Date2))
    {
        cout << "No,Date1 is not After Date2.";
    }
    else
    {
        cout << "Yes, Date1 is After Date2.";
    }
}

int main()
{
    PrintResults();

    return 0;
}
