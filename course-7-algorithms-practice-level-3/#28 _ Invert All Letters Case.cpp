
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

string PrintInvertLetters(string Write)
{
	cout << "\nString after Upper :" << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		Write[i] = isupper(Write[i]) ? tolower(Write[i]) : toupper(Write[i]);
	}
	return Write;
}

int main()
{
	string Write = ReadString();

	cout << PrintInvertLetters(Write);

	return 0;
}