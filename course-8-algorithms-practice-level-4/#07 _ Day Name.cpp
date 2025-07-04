#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string M)
{
    int Number;
    cout << M;
    cin >> Number;
    return Number;
}

void PrintResults()
{
        int year = ReadNumber("Please enter a year? ");
        int month = ReadNumber("\nPlease enter a month? ");
        int day = ReadNumber("\nPlease enter a Day? ");


        tm userTime = {};
        userTime.tm_year = year - 1900;
        userTime.tm_mon = month - 1;
        userTime.tm_mday = day;

        time_t t = mktime(&userTime);

        int weekday = userTime.tm_wday;

        string weekDays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

        cout << endl;
        cout << "Date      :" << day << "/" << month << "/" << year << endl;
        cout << "Day Order :" << userTime.tm_wday << endl;
        cout << "Day Name  :" << weekDays[userTime.tm_wday] << endl;

}

int main()
{
    char re = 'n';
    do {

        PrintResults();

        cout << endl << endl << string(5, '-') << " do you want to repeat again ? " << string(6, '-') << endl;
        cin >> re;
        cout << endl ;
    } while (re == 'y');


    return 0;
}