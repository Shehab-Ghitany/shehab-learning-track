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

    Date.day = ReadNumber("\nPlease enter a Day? ");
    Date.month = ReadNumber("Please enter a Month? ");
    Date.year = ReadNumber("Please enter a Year? ");

    return Date;
}

int GregorianWeekDay(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;

    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
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

bool IsItEndOfWeek(string weekDays)
{
    if (weekDays == "Saturday")
    {
        return true;
    }
    return false;
}

bool IsItWeekEnd(string weekDays)
{
    if (weekDays == "Friday" || weekDays == "Saturday")
    {
        return true;
    }
    return false;
}

bool IsItBussinessDay(string weekDays)
{
    if (weekDays != "Friday" && weekDays != "Saturday")
    {
        return true;
    }
    return false;
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ?
        (Date1.month < Date2.month ? true : (Date1.month == Date2.month ?
            Date1.day < Date2.day : false)) : false);

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

void PrintResults()
{
    //stDate Date = ReadFullDate();
    stDate Date = CurrentDate();

    string weekDays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    int NumberofDay = GregorianWeekDay(Date.year, Date.month, Date.day);

    cout << "Today is " << weekDays[NumberofDay] << " , " << Date.day << "/" << Date.month << "/" << Date.year << endl << endl;
    cout << "Is it End of Week? " << endl;
    if (IsItEndOfWeek(weekDays[NumberofDay]))
    {
        cout << "Yes it is Saturday, it's end of week.";
    }
    else
    {
        cout << "No Not end of week.";
    }

    cout << endl << endl << "Is it Weekend?" << endl;
    if (IsItWeekEnd(weekDays[NumberofDay]))
    {
        cout << "Yes it is a week end.";
    }
    else
    {
        cout << "No it is not a week end.";
    }

    cout << endl << endl << "Is it Bussiness Day?" << endl;
    if (IsItBussinessDay(weekDays[NumberofDay]))
    {
        cout << "Yes it is a business day.";
    }
    else
    {
        cout << "No it is not a business day.";
    }

    short CountEndOfWeek = 0;
    while (!IsItEndOfWeek(weekDays[NumberofDay]))
    {
        NumberofDay++;
        CountEndOfWeek++;
        if (NumberofDay == 7)
        {
            NumberofDay = 0;
        }
    }

    cout << "\n\nDays until end of week : " << CountEndOfWeek << " Day(s)." << endl;

    short LastDay = HowManyDaysInMonth(Date.year, Date.month);
    short CountEndOfMonth = (LastDay - Date.day) + 1;

    cout << "Days until end of month : " << CountEndOfMonth << " Day(s)." << endl;

    stDate endYearDate =Date;
    endYearDate.month = 12;
    endYearDate.day = 31;

    cout << "Days until end of year : " << DiffrenceDays2Dates(Date,endYearDate,true) << " Day(s)." << endl;

}

int main()
{
    PrintResults();

    return 0;
}
