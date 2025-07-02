
#include <iostream>
#include <string>

using namespace std;


string ReadString()
{
	string Write;

	cout << "Please Enter Your String?" << endl;
	getline(cin, Write);

	return Write;
}

void PrintFirstLetter(string Write)
{
	bool isFirstLetter = true;

	cout << "\nString after conversion :" << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		if ((Write[i] != ' ') && isFirstLetter)
		{
			cout << char(toupper(Write[i])) ;
		}
		else 
		{
			cout << Write[i];
		}

		isFirstLetter = Write[i] == ' ' ? true : false;
	}

}


int main()
{

	PrintFirstLetter(ReadString());
	cout << endl;

	return 0;
}