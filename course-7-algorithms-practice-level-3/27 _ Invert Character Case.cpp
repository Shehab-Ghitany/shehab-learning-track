
#include <iostream>
#include <string>

using namespace std;


char ReadString()
{
	char Write;

	cout << "Please Enter Your Character?" << endl;
	cin >> Write;

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


int main()
{
	char Write = ReadString();

	cout << invertchar(Write) << endl;

	return 0;
}