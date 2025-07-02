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


int MyCeil(float num)
{

    if (num > 0)
    {
        return int(num) + 1;
    }
    else
    {
        return int(num) ;
    }

}


int main()
{
    float num = Readnum();

    cout << "\nMy Ceil Result: " << MyCeil(num);

    cout << "\nC++ Ceil Result: " << ceil(num) << endl;

    return 0;
}