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

bool IsVowel(char Letter)
{
	char arr[5] = { 'a','e','i','o','u' };

	for (int i = 0;i < 5;i++)
	{
		if (tolower(Letter) == arr[i])
			return true;
	}
	return false;
}

short VowelCounter(string Write)
{
	short VowelCounter = 0;

	for (int i = 0;i < Write.length();i++)
	{
		if (IsVowel(Write[i]))
			VowelCounter++;
	}

	return VowelCounter;
}


int main()
{
	string Write = ReadString();

	cout << "\nNumber of vowels is: " << VowelCounter(Write) << endl;

	return 0;
}