#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


char RandomNumber(char from, char to)
{



    char Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}


int main()  
{
    srand((unsigned)time(NULL));

    cout << RandomNumber(97, 122) << endl;

    cout << RandomNumber(65, 90) << endl;
    
    cout << RandomNumber(33, 38) << endl;

    cout << RandomNumber(48, 57) << endl;

    return 0;
}