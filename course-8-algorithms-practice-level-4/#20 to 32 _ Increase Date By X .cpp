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

stDate IncreaseDateBy10Days(stDate Date)
{
    for (int i = 1 ; i <=10 ; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date,short Weeks)
{
    for (int i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (IsLastMonthInYear(Date.month))
    {
        Date.month = 1;
        Date.year++;
    }
    else
    {
        Date.month++;
    }

    if (Date.day > HowManyDaysInMonth(Date.year, Date.month))
    {
        Date.day = HowManyDaysInMonth(Date.year, Date.month);
    }

    return Date;
}

stDate IncreaseDateByXMonths(stDate Date,short Months)
{
    for (int i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.year++;

    return Date;
}

stDate IncreaseDateByXYears(stDate Date,short Years)
{
    for (int i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateByXYears_Faster(stDate Date,short Years)
{
    Date.year += Years;

    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.year+=10;

    return Date;
}

stDate IncreaseDateByXDecades(stDate Date,short Decades)
{
    for (int i = 1; i <= Decades; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate IncreaseDateByXDecade_Faster(stDate Date,short Decades)
{
    Date.year += 10 * Decades;

    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.year += 100;

    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    for (int i = 1 ; i <= 10 ; i++)
    {
        Date = IncreaseDateByOneCentury(Date);
    }

    return Date;
}


int main()
{
    stDate Date1 = ReadFullDate();
    stDate TempDate = Date1;

    cout << endl << "Date After:" << endl << endl;


    cout << "01-Adding one day is: ";
    TempDate = IncreaseDateByOneDay(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "02-Adding 10 days is: ";
    TempDate = IncreaseDateBy10Days(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "03-Adding One Week is: ";
    TempDate = IncreaseDateByOneWeek(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "04-Adding 10 Weeks is: ";
    TempDate = IncreaseDateByXWeeks(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "05-Adding One Month is: ";
    TempDate = IncreaseDateByOneMonth(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "06-Adding 5 Months is: ";
    TempDate = IncreaseDateByXMonths(TempDate,5);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "07-Adding One Year is: ";
    TempDate = IncreaseDateByOneYear(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "08-Adding 10 Years is: ";
    TempDate = IncreaseDateByXYears(TempDate, 10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "09-Adding 10 Years (faster) is: ";
    TempDate = IncreaseDateByXYears_Faster(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "10-Adding One Decade is: ";
    TempDate = IncreaseDateByOneDecade(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "11-Adding 10 Decades is: ";
    TempDate = IncreaseDateByXDecades(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "12-Adding 10 Decades (faster) is: ";
    TempDate = IncreaseDateByXDecade_Faster(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "13-Adding One Century is: ";
    TempDate = IncreaseDateByOneCentury(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "14-Adding One Millennium is: ";
    TempDate = IncreaseDateByOneMillennium(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;


    system("pause>0");
    return 0;
}
