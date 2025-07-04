#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#pragma warning(disable : 4996)
struct stDate
{
    int day = 0;
    int month = 0;
    int year = 0;
};

bool IsLeapYearOrNot(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ?
        (Date1.month < Date2.month ? true : (Date1.month == Date2.month ?
            Date1.day < Date2.day : false)) : false);

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
    return (Date.day == HowManyDaysInMonth(Date.year, Date.month));
}

bool IsLastMonthInYear(short month)
{
    return (month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.month))
        {
            Date.month = 1;
            Date.day = 1;
            Date.year++;
        }
        else
        {
            Date.day = 1;
            Date.month++;
        }
    }
    else
    {
        Date.day++;
    }
    return Date;
}

int DiffrenceDays2Dates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1LessThanDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }

    return (IncludeEndDay) ? ++Days : Days;

}

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

stDate CurrentDate()
{
    stDate NowDate;

    time_t t = time(0);

    tm* now = localtime(&t);

    NowDate.year = now->tm_year + 1900;
    NowDate.month = now->tm_mon + 1;
    NowDate.day = now->tm_mday;

    return NowDate;
}

int main()
{
    cout << "Please Enter Your Date Of Birth:";

    stDate Date1 = ReadFullDate();
    stDate Date2 = CurrentDate();

    cout << endl;

    cout << "Your Age is : " << DiffrenceDays2Dates(Date1, Date2) << " Day(s).";

    system("pause>0");
    return 0;
}
