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

bool IsLeapYearOrNot(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int HowManyDays(int nYear)
{
    if (IsLeapYearOrNot(nYear))
    {
        return 366;
    }
    else
    {
        return 365;
    }
}

int HowManyHours(int nDays)
{
    return nDays * 24;
}

int HowManyMinutes(int nHours)
{
    return nHours * 60;
}

int HowManySeconds(int nMinutes)
{
    return nMinutes * 60;
}


void PrintResults()
{
        int year = ReadNumber("Please enter a year to check?  ");
        int Days = HowManyDays(year);
        int Hours = HowManyHours(Days);
        int Minutes = HowManyMinutes(Hours);
        int Seconds = HowManySeconds(Minutes);
            
        cout << endl << "Number of Days    in Year [" << year << "] is " << Days << endl;
        cout << "Number of Hours   in Year [" << year << "] is " << Hours << endl;
        cout << "Number of Minutes in Year [" << year << "] is " << Minutes << endl;
        cout << "Number of Seconds in Year [" << year << "] is " << Seconds << endl;

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
