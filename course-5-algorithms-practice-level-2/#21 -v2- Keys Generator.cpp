#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int Readnumber()
{
    int i = 0;
    cout << "Please enter the number of keys you want ?" << endl;
    cin >> i;

    return i;
}


int RrandomNumber(int from, int to)
{

    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}

void printkeys(int n)
{

    for (int i = 1; i <= n;i++)
    {
        cout << "key [" << i << "] : ";

        for (int j = 1;j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                cout << char(RrandomNumber(65, 90));

            }
            if (j != 4)
            {
                cout << "-";
            }
        }
        cout << endl;
    }

}



int main()
{
    srand((unsigned)time(NULL));

    printkeys(Readnumber());

    return 0;
}
