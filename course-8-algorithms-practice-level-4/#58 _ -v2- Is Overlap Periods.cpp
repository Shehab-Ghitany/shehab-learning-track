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


bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    if (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ?
        (Date1.month < Date2.month ? true : (Date1.month == Date2.month ?
            Date1.day < Date2.day : false)) : false);
}

enCompareDate CompareDate(stDate Date1, stDate Date2)
{
    if (IsDate1EqualDate2(Date1, Date2))
    {
        return enCompareDate::Equal;
    }
    else if (IsDate1LessThanDate2(Date1, Date2))
    {
        return enCompareDate::Before;
    }
    else
    {
        return enCompareDate::After;
    }

}


bool IsOverlapPeriods(stDate Period1Start, stDate Period1End, stDate Period2Start, stDate Period2End)
{
    return !(CompareDate(Period1End, Period2Start) == enCompareDate::Before ||
        CompareDate(Period1Start, Period2End) == enCompareDate::After);
}


void PrintResults()
{
    cout << "Enter Period 1:\n";
    cout << "Enter Start Date:\n\n";
    stDate Period1Start = ReadFullDate();
    cout << "\nEnter End Date:\n\n";
    stDate Period1End = ReadFullDate();

    cout << "\nEnter Period 2:\n";
    cout << "Enter Start Date:\n\n";
    stDate Period2Start = ReadFullDate();
    cout << "\nEnter End Date:\n\n";
    stDate Period2End = ReadFullDate();

    cout << endl;

    if (IsOverlapPeriods(Period1Start, Period1End, Period2Start, Period2End))
    {
        cout << "Yes,The Periods Overlap";
    }
    else
    {
        cout << "No, The Periods Don't Overlap.";
    }

}


int main()
{
    PrintResults();

    return 0;
}
