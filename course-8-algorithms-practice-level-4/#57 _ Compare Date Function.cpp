#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable : 4996)

enum enCompareDate{Before=-1 , Equal = 0 , After = 1};

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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    if (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ?
        (Date1.month < Date2.month ? true : (Date1.month == Date2.month ?
            Date1.day < Date2.day : false)) : false);
}

enCompareDate CompareDate(stDate Date1, stDate Date2)
{
    if (IsDate1EqualDate2(Date1, Date2))
    {
        return enCompareDate::Equal;
    }
    else if (IsDate1LessThanDate2(Date1, Date2))
    {
        return enCompareDate::Before;
    }
    else
    {
        return enCompareDate::After;
    }

}


void PrintResults()
{
    cout << "Enter Date1:" << endl;
    stDate Date1 = ReadFullDate();
    cout << "\nEnter Date2:" << endl;
    stDate Date2 = ReadFullDate();

    cout << endl;

    cout << "Compare Result = " << CompareDate(Date1, Date2);

}


int main()
{
    PrintResults();

    return 0;
}
