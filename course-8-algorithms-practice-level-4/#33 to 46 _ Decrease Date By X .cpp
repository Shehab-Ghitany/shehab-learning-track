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

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.day == 1)
    {
        if (Date.month ==1)
        {
            Date.day = 31;
            Date.month = 12;
            Date.year--;
        }
        else
        {
            Date.month--;
            Date.day = HowManyDaysInMonth(Date.year, Date.month);
        }
    }
    else
    {
        Date.day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date,short Days)
{
    for (int i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date,short Weeks)
{
    for (int i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.month==1)
    {
        Date.month = 12;
        Date.year--;
    }
    else
    {
        Date.month--;
    }

    if (Date.day > HowManyDaysInMonth(Date.year, Date.month))
    {
        Date.day = HowManyDaysInMonth(Date.year, Date.month);
    }

    return Date;
}

stDate DecreaseDateByXMonths(stDate Date,short Months)
{
    for (int i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.year--;

    return Date;
}

stDate DecreaseDateByXYears(stDate Date,short Years)
{
    for (int i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXYears_Faster(stDate Date,short Years)
{
    Date.year -= Years;

    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.year-=10;

    return Date;
}

stDate DecreaseDateByXDecades(stDate Date,short Decades)
{
    for (int i = 1; i <= Decades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate DecreaseDateByXDecade_Faster(stDate Date,short Decades)
{
    Date.year -= 10 * Decades;

    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.year -= 100;

    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.year -= 1000;

    return Date;
}


int main()
{
    stDate Date1 = ReadFullDate();
    stDate TempDate = Date1;

    cout << endl << "Date After:" << endl << endl;


    cout << "01-Substracting one day is: ";
    TempDate = DecreaseDateByOneDay(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "02-Substracting 10 days is: ";
    TempDate = DecreaseDateByXDays(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "03-Substracting One Week is: ";
    TempDate = DecreaseDateByOneWeek(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "04-Substracting 10 Weeks is: ";
    TempDate = DecreaseDateByXWeeks(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "05-Substracting One Month is: ";
    TempDate = DecreaseDateByOneMonth(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "06-Substracting 5 Months is: ";
    TempDate = DecreaseDateByXMonths(TempDate,5);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "07-Substracting One Year is: ";
    TempDate = DecreaseDateByOneYear(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "08-Substracting 10 Years is: ";
    TempDate = DecreaseDateByXYears(TempDate, 10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "09-Substracting 10 Years (faster) is: ";
    TempDate = DecreaseDateByXYears_Faster(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "10-Substracting One Decade is: ";
    TempDate = DecreaseDateByOneDecade(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "11-Substracting 10 Decades is: ";
    TempDate = DecreaseDateByXDecades(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "12-Substracting 10 Decades (faster) is: ";
    TempDate = DecreaseDateByXDecade_Faster(TempDate,10);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "13-Substracting One Century is: ";
    TempDate = DecreaseDateByOneCentury(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;

    cout << "14-Substracting One Millennium is: ";
    TempDate = DecreaseDateByOneMillennium(TempDate);
    cout << TempDate.day << '/' << TempDate.month << '/' << TempDate.year << endl;


    system("pause>0");
    return 0;
}
