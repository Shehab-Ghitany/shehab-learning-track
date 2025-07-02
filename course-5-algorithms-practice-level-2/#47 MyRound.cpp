#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


float Readnum()
{
    float num=0;

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


int MyRound(float num)
{
    if (addRemaindertoNumber(num) < 5)
    {
        return int(num);
    }
    else
    {
        return int(num) + 1;
    }

}


int main()
{
    float num = Readnum();

    cout << "\nMy Round Result: " << MyRound(num);

    cout << "\nC++ Round Result: " << round(num) << endl;

    return 0;
}