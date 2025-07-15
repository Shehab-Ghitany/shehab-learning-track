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

bool IsItBussinessDay(int NumberofDay)
{

    if (NumberofDay == 5 || NumberofDay == 6)
        return false;
    else
        return true;
}

int DiffrenceDays2Dates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1LessThanDate2(Date1, Date2))
    {
        int NumberofDay = GregorianWeekDay(Date1.year, Date1.month, Date1.day);

        if (IsItBussinessDay(NumberofDay))
            Days++;


        Date1 = IncreaseDateByOneDay(Date1);

    }

    return (IncludeEndDay) ? ++Days : Days;

}

void PrintResults()
{
    cout << "Vacation Starts:" << endl;
    stDate VacationStarts = ReadFullDate();
    cout << "\nVacation Ends:" << endl;
    stDate VacationEnds = ReadFullDate();

    string weekDays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    int NumberofDay = GregorianWeekDay(VacationStarts.year, VacationStarts.month, VacationStarts.day);
    cout << "\nVacation From: " << weekDays[NumberofDay] << " , " << VacationStarts.day << "/" << VacationStarts.month << "/" << VacationStarts.year << endl;
    NumberofDay = GregorianWeekDay(VacationEnds.year, VacationEnds.month, VacationEnds.day);
    cout << "Vacation To: " << weekDays[NumberofDay] << " , " << VacationEnds.day << "/" << VacationEnds.month << "/" << VacationEnds.year << endl << endl;


    cout << "Actucal Vacation Days is: " << DiffrenceDays2Dates(VacationStarts, VacationEnds);



}

int main()
{
    PrintResults();

    return 0;
}
