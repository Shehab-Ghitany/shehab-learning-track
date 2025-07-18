#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int ReadNumber(string M)
{
    int Number;
    cout << M;
    cin >> Number;
    return Number;
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

int TotalDaysFromBeginningYear(int year, int month, int day)
{
        int TotalDays=0;
        for (int i = 1; i < month;i++)
        {
            TotalDays = TotalDays + HowManyDaysInMonth(year, i);
        }
        TotalDays = TotalDays + day;

        return TotalDays;
}

void ConvertTotalDaysToDate(int TotalDays,int year)
{
    cout << "Date for [" << TotalDays << "] is: ";

    int RemainderDays=0;
    int i = 0;
    
    while (TotalDays > 0)
    {
        i++;

        short DaysInMonth = HowManyDaysInMonth(year, i);

        if (TotalDays <= DaysInMonth)
        {
            RemainderDays = TotalDays;
            break;
        }
        else
        {
            TotalDays -= DaysInMonth;
        }

    }

    cout << RemainderDays << '/' << i << '/' << year;

}

int main()
{
    int day = ReadNumber("Please enter a Day? ");
    int month = ReadNumber("\nPlease enter a Month? ");
    int year = ReadNumber("\nPlease enter a Year? ");

    int TotalDays = TotalDaysFromBeginningYear(year, month, day);

    cout << "\nNumber of Days from the beginning of the year is " << TotalDays << endl << endl;
    ConvertTotalDaysToDate(TotalDays, year);

    system("pause>0");
    return 0;
}
