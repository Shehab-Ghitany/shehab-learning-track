#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


float Readnum()
{
    float num = 0;

    cout << "Please enter the number : " << endl;
    cin >> num;

    return num;
}

int addRemaindertoNumber(float num)
{
    int Remainder = num * 10;
    Remainder = Remainder % 10;

    return Remainder;
}


float MyRound(float num)
{
    float j = addRemaindertoNumber(num);

    if (num > 0)
    {
        if (j <= 4)
        {
            j = j / 10;
            return num - j;
        }
        else
        {
            j = j / 10;
            return (num - j) + 1;
        }
    }
    else if (num < 0)
    {
        if (j >= 5)
        {
            j = j / 10;

            return (num + j) - 1;
        }
        else
        {
            j = j / 10;
            return num - j;
        }

    }


}


int main()
{
    float num = Readnum();

    cout << "\nMy Round Result: " << MyRound(num);

    cout << "\nC++ Round Result: " << round(num) << endl;

    return 0;
}

