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

stDate readDate(stDate Date)
{
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

bool IsLastDayInMonth(stDate Date)
{
    return Date.day == HowManyDaysInMonth(Date.year, Date.month);
}

bool IsLastMonthInYear(stDate Date)
{
    return Date.month == 12;
}


int main()
{
    stDate Date1;

    Date1 = readDate(Date1);

    cout << endl;

    IsLastDayInMonth(Date1) ? cout << "Yes, Day is Last Day in Month." :
        cout << "No, Day is NOT Last Day in Month.";
    cout << endl;
    IsLastMonthInYear(Date1) ? cout << "Yes, Month is Last Month in Year." :
        cout << "No, Month is NOT Last Month in Year.";


    system("pause>0");
    return 0;
}
