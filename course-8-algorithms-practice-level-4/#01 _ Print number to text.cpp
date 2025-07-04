#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Enter a Number?  ";
    cin >> Number;
    return Number;
}

string PrintNumberToText(int n)
{

    if (n == 0)
    {
        return "";
    }

    if (n >= 1 && n <= 19)
    {
        string arr[] = { "" , "One", "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" ,"Ten" ,
        "Eleven" , "Twelve" , "Thirteen" , "Fourteen" , "Fifteen" , "Sixteen" , "Seventeen" ,"Eighteen" , "Nineteen" };

        return arr[n] + " ";
    }

    if (n >= 20 && n <= 99)
    {
        string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return arr[n / 10] + " " + PrintNumberToText(n % 10);
    }

    if (n >= 100 && n <= 199)
    {
        return "One Hundred " + PrintNumberToText(n %100);
    }

    if (n >= 200 && n <= 999)
    {
        return PrintNumberToText(n / 100) + "Hundreds " + PrintNumberToText(n % 100);
    }

    if (n >= 1000 && n <= 1999)
    {
        return "One Thousand " + PrintNumberToText(n % 1000);
    }

    if (n >= 2000 && n <= 999999)
    {
        return PrintNumberToText(n / 1000) + "Thousands " + PrintNumberToText(n % 1000);
    }

    if (n >= 1000000 && n <= 1999999)
    {
        return "One Million " + PrintNumberToText(n % 1000000);
    }

    if (n >= 2000000 && n <= 999999999)
    {
        return PrintNumberToText(n/ 1000000) + "Millions " + PrintNumberToText(n% 1000000);
    }

    if (n >= 1000000000 && n <= 1999999999)
    {
        return"One Billion " + PrintNumberToText(n% 1000000000);
    }
 else 
    { 
        return   PrintNumberToText(n / 1000000000) + "Billions " + PrintNumberToText(n % 1000000000);
    }

}

int main()
{
    int n = ReadNumber();

    cout << PrintNumberToText(n) << endl;

    return 0;
}
