



#include <iostream>
#include <string>
using namespace std;

string ReadPositiveNumber(string Message)
{
    string Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < "AAA" || Number > "ZZZ");

    return Number;
}

void nestedloops(string n )
{
    bool found = false;
    int c=1;

    for (int z = 65; z  <= 90 ; z++) {
        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++)
            {
                cout << "Trail [" << c << "] : " << char(z) << char(i) << char(j) << endl;

                string r = "";
                r+= char(z);
                r+= char(i);
                r+= char(j);

                if (n == r)
                {
                    cout << "\n\n\nPassword is " << r << endl << endl;

                    cout << "Found after " << c << " Trail(s)" << endl;
                    found = true;
                    break;
                }
                c++;
            }
            if (found)
                break;
        }
        if (found)
            break;
    }

}

int main()
{

    nestedloops(ReadPositiveNumber("enter letters"));

    return 0;
}