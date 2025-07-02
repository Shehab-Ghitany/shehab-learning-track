
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

string PrintLowerFirstLetterOfEachWord(string Write)
{
	bool isFirstLetter = true;

	cout << "\nString after conversion :" << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		if ((Write[i] != ' ') && isFirstLetter)
		{ 
			Write[i] = tolower(Write[i]);
		}

		isFirstLetter = Write[i] == ' ' ? true : false;
	}
	return Write;
}


int main()
{

	cout << PrintLowerFirstLetterOfEachWord(ReadString()) << endl;

	return 0;
}