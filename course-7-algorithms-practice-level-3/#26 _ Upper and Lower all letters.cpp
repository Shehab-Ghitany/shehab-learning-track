
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

string PrintUpperAllLetters(string Write)
{
	cout << "\nString after Upper :" << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		Write[i] = toupper(Write[i]);
	}
	return Write;
}

string PrintLowerAllLetters(string Write)
{
	cout << "\nString after Lower :" << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		Write[i] = tolower(Write[i]);
	}
	return Write;
}

int main()
{
	string Write = ReadString();

	cout << PrintUpperAllLetters(Write) << endl;

	cout << PrintLowerAllLetters(Write) << endl;

	return 0;
}