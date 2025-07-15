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

void FormatDate(string WriteDate)
{
    stDate Date = DateStringToStruct(WriteDate);

    cout << endl << Date.day << "/" << Date.month << "/" << Date.year << endl << endl;

    cout << Date.year << "/" << Date.month << "/" << Date.day << endl << endl;

    cout << Date.month << "/" << Date.day << "/" << Date.year << endl << endl;

    cout << Date.month << "-" << Date.day << "-" << Date.year << endl << endl;

    cout << Date.day << "-" << Date.month << "-" << Date.year << endl << endl;

    cout << "Day:" << Date.day << ", Month:" << Date.month << ", Year:" << Date.year;

}


void PrintResults()
{
    string WriteDate = "";

    cout << "Please Enter Date dd/mm/yyyy?  ";
    getline(cin >> ws, WriteDate);

    FormatDate(WriteDate);
}

int main()
{
    PrintResults();

    return 0;
}
