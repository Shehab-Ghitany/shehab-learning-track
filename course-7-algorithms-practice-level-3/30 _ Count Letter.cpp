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


string CountLetter(string Write,char Letter)
{
	short CountLetter = 0;


	for (int i = 0; i < Write.length(); i++)
	{
		if (Write[i] == Letter)
		{
			CountLetter++;
		}
	}
	
	string PrintResult = "Letter '" + string(1,Letter) + "' Count = " + to_string(CountLetter);

	return PrintResult;
}


int main()
{
	string Write = ReadString();
	char Letter = ReadChar();

	cout << CountLetter(Write, Letter) << endl;


	return 0;
}