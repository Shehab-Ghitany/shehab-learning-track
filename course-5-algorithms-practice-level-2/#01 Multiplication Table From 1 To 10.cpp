#include <iostream>
#include <string>
using namespace std;


void firstlines()
{
    cout << endl << endl << "\t\t\t\tMultipliaction Table From 1 to 10\t" << endl << endl;
    cout << "\t";

    int i = 1;
    for (i; i <= 10; i++)
    {
        cout << "\t" << i;
    }

    cout << endl << "___________________________________________________________________________________________" << endl;
}


void Multiply1010()
{

    int j = 1;
    int k = 1;

    for (j; j <= 10; j++)
    {
        cout << j  << "\t|\t" << "";
        for (k; k <= 10; k++)
        {
            cout << j * k << "\t";
        }
        cout << endl;
        k = 1;
    }
}




int main()
{
    firstlines();

    Multiply1010();

    return 0;
}