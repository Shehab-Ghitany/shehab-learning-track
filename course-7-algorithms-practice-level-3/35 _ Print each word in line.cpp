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

void PrintAllWords(string Write)
{
	string word = "";

	for (int i = 0;i < Write.length();i++)
	{
		if ((Write[i] != ' '))
		{
			word.push_back(Write[i]);
		}
		else
		{
			cout << word << endl;
			word = "";
		}
	}
	cout << word << endl;
}


int main()
{
	string Write= ReadString();

	cout << "\nYour string words are:" << endl;
	PrintAllWords(Write);

	cout << endl;
	return 0;
}