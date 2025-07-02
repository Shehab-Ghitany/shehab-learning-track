#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string Write;

	cout << "Please Enter Your String?" << endl;
	getline(cin, Write);

	return Write;
}

string TrimLeft(string Write)
{

	for (short i = 0; i < Write.length();i++)
	{
		if (Write[i] != ' ')
		{
			return Write.substr(i, Write.length() - i);
		}
	}
		return "";
}

string TrimRight(string Write)
{

	for (int i = Write.length() - 1; i >= 0;i--)
	{
		if (Write[i] != ' ')
		{
			return Write.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string Write)
{
	return TrimLeft(TrimRight(Write));
}


int main()
{
	string Write = "         Mohammmed Abu-Hadhoud         ";

	cout << "\nString       = " << Write << endl;
	cout << "\nTrim Left    = " << TrimLeft(Write);
	cout << "\nTirm Right   = " << TrimRight(Write);
	cout << "\nTirm Right   = " << Trim(Write) << endl;

	return 0;
}