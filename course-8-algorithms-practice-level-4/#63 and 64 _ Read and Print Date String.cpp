#include <iostream>
#include <string>
#include <vector>
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

stDate ReadFullDate()
{
    stDate Date;

    Date.day = ReadNumber("\nPlease enter a Day? ");
    Date.month = ReadNumber("Please enter a Month? ");
    Date.year = ReadNumber("Please enter a Year? ");

    return Date;
}

vector <string> VSplitString(string Write, string delim = " ")
{
    vector <string> SplitString;

    short pos = 0;
    string sword;

    while ((pos = Write.find(delim)) != std::string::npos)
    {
        sword = Write.substr(0, pos);
        if (sword != "")
        {
            SplitString.push_back(sword);
        }
        Write.erase(0, pos + delim.length());
    }

    if (Write != "")
    {
        SplitString.push_back(Write);
    }
    return SplitString;
}

stDate DateStringToStruct(string WriteDate)
{
    stDate Date;
    vector <string> vDate = VSplitString(WriteDate, "/");

    Date.day = stoi(vDate[0]);
    Date.month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);

    return Date;
}

string DateStructToString(stDate Date)
{
    string FullDateString = "";

    FullDateString = to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);

    return FullDateString;
}


void PrintResults()
{
    string WriteDate = "";

    cout << "Please Enter Date dd/mm/yyyy?  ";
    getline(cin >> ws, WriteDate);

    stDate Date = DateStringToStruct(WriteDate);
    cout << endl << "Day:" << Date.day;
    cout << endl << "Month:" << Date.month;
    cout << endl << "Year:" << Date.year;

    cout << endl << endl << "You Entered: " << DateStructToString(Date);

}

int main()
{
    PrintResults();

    return 0;
}
