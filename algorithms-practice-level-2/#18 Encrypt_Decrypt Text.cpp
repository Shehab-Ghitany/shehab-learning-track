#include <iostream>
#include <string>
using namespace std;

string ReadPositiveNumber(string Message)
{
    string Number;

    cout << Message << endl;
    getline(cin, Number);
    return Number;
}

string encr(string n)
{
    string encr;

    for (int i = 0 ; i < n.length();i++)
    {
       encr+= n[i] + 2 ;
    }

        return encr;

}

string decr(string n)
{

    string decr;

    for (int i = 0; i < n.length();i++)
    {
        decr+= n[i] - 2;
    }

    return decr;



}

int main()
{
    string k = ReadPositiveNumber("enter your k");
    string ke = encr(k);

    cout << ke << endl;
    cout << decr(ke) << endl;

    return 0;
}