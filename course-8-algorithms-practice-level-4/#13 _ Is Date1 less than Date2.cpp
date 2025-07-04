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


int ReadNumber(string M)
{
    int Number;
    cout << M;
    cin >> Number;
    return Number;
}


string Compare2Dates(stDate Date1, stDate Date2)
{
   if (Date1.year < Date2.year ||
        (Date1.year == Date2.year && Date1.month < Date2.month) ||
        (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day < Date2.day))
    {
        return "Yes, Date1 is Less than Date2.";
    }
    else if (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day)
    {
        return "Date1 is equal to Date2.";
    }
    else
    {
        return "No, Date1 is not Less than Date2.";
    }

}


int main()
{
    stDate Date1, Date2;

    Date1.day = ReadNumber("Please enter a Day? ");
    Date1.month = ReadNumber("Please enter a Month? ");
    Date1.year = ReadNumber("Please enter a Year? ");

    Date2.day = ReadNumber("\nPlease enter a Day? ");
    Date2.month = ReadNumber("Please enter a Month? ");
    Date2.year = ReadNumber("Please enter a Year? ");

    cout << endl;

    cout << Compare2Dates(Date1, Date2);

    system("pause>0");
    return 0;
}
