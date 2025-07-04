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

int GregorianWeekDay(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;

    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}

void PrintResults()
{
        int year = ReadNumber("Please enter a year? ");
        int month = ReadNumber("\nPlease enter a month? ");

        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        int NumberOfDays = HowManyDaysInMonth(year, month);
        int WeekDay = GregorianWeekDay(year, month, 1);

        cout << endl << "  " << string(15, '_') << months[month - 1] << string(15, '_') << endl;
        cout << endl << setw(5) << "Sun" << setw(5) << "Mon" << setw(5) << "Tue"
         << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat" << endl;

        int c = 0;

        for (int i = 0; i < WeekDay; i++)
        {
            cout << setw(5) << " ";
            c++;
        }

        for (int i = 1; i <= NumberOfDays; i++)
        {
            cout << setw(5) << i ;
                c++;
            if (c == 7)
            {
                c = 0;
                cout << endl;
            }
        }

        cout << endl << "  " << string(33, '_')<< endl;

}

int main()
{

    PrintResults();

    return 0;
}
