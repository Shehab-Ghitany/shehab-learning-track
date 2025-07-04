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

void ConvertTotalDaysToDate(int AddDays,int year,int month,int day)
{
    cout << "\nDate after adding [" << AddDays << "] days is: ";

    for (int i = AddDays; i > 0; i--)
    {
        if (day == HowManyDaysInMonth(year, month))
        {
            month++;
            day = 1;

            if (month == 13)
            {
                year++;
                month = 1;
            }

        }
        else
        {
            day++;
        }

    }

    cout << day << '/' << month << '/' << year;

}


int main()
{
    int day = ReadNumber("Please enter a Day? ");
    int month = ReadNumber("\nPlease enter a Month? ");
    int year = ReadNumber("\nPlease enter a Year? ");

    int AddDays = ReadNumber("\nHow many days to add? ");


    ConvertTotalDaysToDate(AddDays, year, month, day);

    system("pause>0");
    return 0;
}
