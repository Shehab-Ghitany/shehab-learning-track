
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum random { small_letters = 1, capital_letters = 2, special_character = 3, digit = 4 };

char RandomNumber(random type)
{

    //char Randomsletter = rand() % (to - from + 1) + from;

    char RandomSletter = rand() % (122 - 97 + 1) + 97;
    char RandomCletter = rand() % (90 - 65 + 1) + 65;
    char RandomScharacter = rand() % (38 - 33 + 1) + 33;
    char Randomdigit = rand() % (57 - 48 + 1) + 48;

    if (type == random::small_letters)
    {
        return RandomSletter;
    }
    else if (type == random::capital_letters)
    {
        return RandomCletter;
    }
    else if (type == random::special_character)
    {
        return RandomScharacter;
    }
    else if (type == random::digit)
    {
        return Randomdigit;
    }

}


int main()
{
    srand((unsigned)time(NULL));

    cout << RandomNumber(random::capital_letters) << endl;

    return 0;
}
