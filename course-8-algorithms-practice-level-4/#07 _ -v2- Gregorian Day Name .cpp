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
        int day = ReadNumber("\nPlease enter a Day? ");

        string weekDays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

        int NumberofDay = GregorianWeekDay(year, month, day);

        cout << endl;
        cout << "Date      :" << day << "/" << month << "/" << year << endl;
        cout << "Day Order :" << NumberofDay << endl;
        cout << "Day Name  :" << weekDays[NumberofDay] << endl;

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
