#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


int Readnum()
{
    int num=0;

    cout << "Please enter the number : " << endl;
    cin >> num;

    return num;
}

int MyABS(int num)
{
    int Result = 0;

    //Result = (num - num - num);
    //Result = num - num * 2;
    //Result = num * -1;
    Result = -num;

    if (num < 0)
    {
        return Result;
    }
    else
    {
        return num;
    }
}


int main()
{
    int num = Readnum();

    cout << "\nMy abs Result: " << MyABS(num);

    cout << "\nC++ abs Result: " << abs(num) << endl;

    return 0;
}