#include <iostream>
#include <string>

using namespace std;


string ReadString()
{
	string Write;

	do
	{
		cout << "Please Enter Your String?" << endl;
		getline(cin, Write);

	} while (Write.empty() );

		return Write;
}

void PrintFirstLetter()
{
	string Write = ReadString();

	cout << Write[0] << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		if ((Write[i] == ' ') && (Write[i + 1] != ' '))
		{
			cout << Write[i+1] << endl;
		}
	}

}


int main()
{
	PrintFirstLetter();

	return 0;
}