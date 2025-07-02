#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int Readnumber()
{
    int numarrays;

        cout << "Enter Number Of Elements ?" << endl;
        cin >> numarrays;

        return numarrays;
}


void Readarrayelements(int arrayelement [100] , int numarrays)
{

    cout << endl << "Enter array elements : " << endl;
    for (int i = 0; i < numarrays; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arrayelement[i];
    }

}


void Printcheck(int arrayelement[100], int numarrays)
{
    int c = 0;
    int checknumber = 0;

    cout << "\nenter the number you want to check : ";
    cin >> checknumber;

    for (int i = 0; i < numarrays;i++)
    {
        if (checknumber == arrayelement[i])
        {
            c++;
        }
    }

    cout << "\nOriginal array: ";
    
    for (int i = 0;i < numarrays; i++)
    {
        cout << arrayelement[i] << " ";
    }


    cout << endl << checknumber << " is repeated " << c << " time";
    if (c > 1) { cout << "s"; }
}



int main()
{
    srand((unsigned)time(NULL));


    int arrayelement[100];
    int num = Readnumber();
    

    Readarrayelements(arrayelement, num);
    Printcheck(arrayelement,num);

    return 0;
}