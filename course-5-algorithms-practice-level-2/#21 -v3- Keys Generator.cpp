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

string GenerateKey()
{
    string key;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1;j <= 4; j++)
        {
            key += (char)RrandomNumber(65, 90);

        }
        if (i != 4)
        {
            key += "-";
        }
    }

    return key;
}

string printend(int n)
{

    string end = "";

    for (int i = 1; i <= n;i++)
    {
        end += "key [" + to_string(i) + "] : ";
        end += GenerateKey();
        end += "\n";
    }

    return end;
}


int main()
{
    srand((unsigned)time(NULL));


    cout << printend(Readnumber());

    return 0;
}
