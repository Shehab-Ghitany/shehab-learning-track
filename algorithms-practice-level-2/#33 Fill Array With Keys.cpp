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


enum random { small_letters = 1, capital_letters = 2, special_character = 3, digit = 4 };

char RandomNumber(random type)
{
    char rsl = RrandomNumber(97, 122);
    char rcl = RrandomNumber(65, 90);
    char rsc = RrandomNumber(33, 38);
    char rd = RrandomNumber(48, 57);

    if (type == random::small_letters)
    {
        return rsl;
    }
    else if (type == random::capital_letters)
    {
        return rcl;
    }
    else if (type == random::special_character)
    {
        return rsc;
    }
    else if (type == random::digit)
    {
        return rd;
    }

}


string generatenum()
{

    string key = "";

        for (int i = 1; i <= 4;i++)
        {
            for (int j = 1;j <= 4; j++)
            {
                key += RandomNumber(random::capital_letters);
            }
            if (i != 4) { key += "-"; }
        }
        key += "\n";

    return key;
}

void arrays(string arr[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = generatenum();
        cout << "Array[" << i+1 << "] : " << arr[i];
    }

}


int main()
{
    srand((unsigned)time(NULL));

    string arr[100];
    int n = Readnumber();

    arrays(arr, n);

    return 0;
}