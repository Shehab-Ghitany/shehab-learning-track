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

char ReadChar()
{
	char Letter;

	cout << "\nPlease Enter Your String?" << endl;
	cin >> Letter;

	return Letter;
}

short CountLetter(string Write,char Letter)
{
	short CountLetter = 0;

	for (int i = 0; i < Write.length(); i++)
	{
		if (Write[i] == Letter)
		{
			CountLetter++;
		}
	}
	
	return CountLetter;
}

short CountLettersmallandcapital(string Write, char Letter)
{
	short CountLetter = 0;

	for (int i = 0; i < Write.length(); i++)
	{
		if (Write[i] == (char)tolower(Letter) || Write[i] == (char)toupper(Letter))
		{
			CountLetter++;
		}
	}

	return CountLetter;
}


int main()
{
	string Write = ReadString();
	char Letter = ReadChar();

	cout << "\nLetter \'" << Letter << "\' Cout = " << CountLetter(Write, Letter) << endl;

	cout << "\nLetter \'" << (char)tolower(Letter) << "\' OR \'" << (char)toupper(Letter)
		 << "\' Cout = " << CountLettersmallandcapital(Write, Letter) << endl;

	return 0;
}