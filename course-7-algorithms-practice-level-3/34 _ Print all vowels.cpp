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

void PrintAllVowels(string Write)
{
	for (int i = 0;i < Write.length();i++)
	{
		if (IsVowel(Write[i]))
			cout << Write[i] << "    ";
	}
}


int main()
{
	string Write= ReadString();

	cout << "\nVowels in string are: ";
	PrintAllVowels(Write);

	cout << endl;
	return 0;
}