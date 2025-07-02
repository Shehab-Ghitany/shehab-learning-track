#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

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


int main()
{
    srand((unsigned)time(NULL));

    cout << RandomNumber(random::small_letters) << endl;
    cout << RandomNumber(random::capital_letters) << endl;
    cout << RandomNumber(random::special_character) << endl;
    cout << RandomNumber(random::digit) << endl;


    return 0;
}