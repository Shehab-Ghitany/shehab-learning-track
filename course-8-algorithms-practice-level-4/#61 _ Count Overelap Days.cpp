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
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n\n";
    Period.EndDate = ReadFullDate();

    return Period;
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


int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    short DaysCounter = 0;

    while (!IsDate1EqualDate2(Period1.StartDate, Period1.EndDate))
    {
        if (((CompareDate(Period1.StartDate, Period2.StartDate) == enCompareDate::After) && (CompareDate(Period1.EndDate, Period2.EndDate) == enCompareDate::Before))
            || (IsDate1EqualDate2(Period1.StartDate, Period2.StartDate)) || (IsDate1EqualDate2(Period1.StartDate, Period2.EndDate)))
        {
            DaysCounter += 1;
        }

        Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
    }

    return DaysCounter;
}


void PrintResults()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    cout << endl << "Overlap Days Counter Is: " << CountOverlapDays(Period1, Period2) << endl;

}


int main()
{
    PrintResults();

    return 0;
}
