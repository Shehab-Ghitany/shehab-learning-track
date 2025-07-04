#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string RemovePunctuationFromString(string Write)
{
	char s = ',';
	string text = "";

	for (int i = 0; i < Write.length();i++)
	{
		s = Write[i];
		if (!ispunct(s))
		{
			text += s;
		}
	}
	return text;
}

int main()
{
	string Write = "Welcome to Jordan, Jordan is a nice country; it's amazing. ";

	cout << "Original String: " << endl;
	cout << Write << endl;

	cout << "\Punctuation: " << endl;
	cout << RemovePunctuationFromString(Write);
	cout << endl;

	return 0;
}
