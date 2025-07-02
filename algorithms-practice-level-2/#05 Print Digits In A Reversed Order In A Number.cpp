#include <iostream>
#include <string>
using namespace std;



int Readnumber()
{
    int n;

    cout << "Please enter the number" << endl;
    cin >> n;

    return n;
}


void PrintReverse(int n)
{
    int i = 1;

    int b;
    b = to_string(n).length();

    for (b; b >= 0 ; b--)
    {
        cout << to_string(n)[b] << endl;
    }

}



int main()
{

    PrintReverse(Readnumber());

    return 0;
}
