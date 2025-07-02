
#include <iostream>
#include <string>
using namespace std;



string Readnumber()
{
    string n;

    cout << "Please Type anything to (Reverse) it  : " << endl;
    getline(cin, n);

    return n;
}


void PrintReverse(string n)
{
    int b = n.length();

    for (b; b >= 0; b--)
    {
        cout << n[b] << endl;
    }

}



int main()
{

    PrintReverse(Readnumber());

    return 0;
}

