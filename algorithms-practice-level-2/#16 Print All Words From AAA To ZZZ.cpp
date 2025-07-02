



#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void nestedloops()
{

    for (int z = 65; z  <= 90 ; z++)
    {
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                cout << char(z) << char(i) << char(j) << endl;
            }

        }
    }


}

int main()
{

    nestedloops();

    return 0;
}