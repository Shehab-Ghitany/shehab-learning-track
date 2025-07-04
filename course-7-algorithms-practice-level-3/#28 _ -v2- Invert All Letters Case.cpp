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

char invertchar(char Write)
{

	if (islower(Write))
	{
		Write = toupper(Write);
	}
	else if (isupper(Write))
	{
		Write = tolower(Write);
	}

	return Write;
}


string PrintInvertLetters(string Write)
{
	cout << "\nString after Upper :" << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		Write[i] = invertchar(Write[i]);
	}
	return Write;
}

int main()
{
	string Write = ReadString();

	cout << PrintInvertLetters(Write);

	return 0;
}