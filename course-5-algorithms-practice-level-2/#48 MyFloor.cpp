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


int MyFloor(float num)
{

    if (num > 0)
    {
        return int(num);

    }
    else
    {
        return (int)--num;
        
    }

}


int main()
{
    float num = Readnum();

    cout << "\nMy Round Result: " << MyFloor(num);

    cout << "\nC++ Round Result: " << floor(num) << endl;

    return 0;
}