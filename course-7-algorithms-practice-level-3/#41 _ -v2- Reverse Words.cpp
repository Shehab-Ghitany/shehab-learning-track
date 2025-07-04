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

string ReverseString(string Write)
{
	string s;

	short length = Write.length();
	short j = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		if (Write[i] == ' ')
		{
			s += Write.substr(i+1, j) + " ";
			j = 0;
		}
		else
		{
			j++;
		}
	}

	s += Write.substr(0, j);

	return s;
}

int main()
{

	cout << ReverseString(ReadString()) << endl;

	return 0;
}