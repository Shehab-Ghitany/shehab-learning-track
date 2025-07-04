#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string Write;

	cout << "Please Enter Your String?" << endl;
	getline(cin, Write);

	return Write;
}


string JoinString(vector<string>vString, string delim)
{
	string Write;

	for (string& s : vString)
	{
		Write = Write + s + delim;
	}

	return Write.substr(0, Write.length() - delim.length());
}

vector <string> VSplitString(string Write, string delim = " ")
{
	vector <string> SplitString;

	short pos = 0;
	string sword;

	while ((pos = Write.find(delim)) != std::string::npos)
	{
		sword = Write.substr(0, pos);
		if (sword != "")
		{
			SplitString.push_back(sword);
		}
		Write.erase(0, pos + delim.length());
	}

	if (Write != "")
	{
		SplitString.push_back(Write);
	}
	return SplitString;
}

string PrintLowerAllLetters(string Write)
{
	for (int i = 0; i < Write.length(); i++)
	{
		Write[i] = tolower(Write[i]);
	}
	return Write;
}

string ReplaceWordInStringUsingSplit(string Write, string StringToReplace, string ReplaceTo, bool MatchCase=true)
{

	vector<string> vWrite = VSplitString(Write, " ");

		for (string& s : vWrite)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = ReplaceTo;
				}
			}
			else
			{
				if (PrintLowerAllLetters(s) == PrintLowerAllLetters(StringToReplace))
				{
					s = ReplaceTo;
				}
			}
		}
		return JoinString(vWrite, " ");
}


int main()
{
	string Write = "Welcome to Jordan , Jordan is a nice country";

	cout << "Original String: " << endl;
	cout << Write << endl;

	cout << "\nReplace with match case: " << endl;
	cout << ReplaceWordInStringUsingSplit(Write, "jordan","USA");
	cout << endl;

	cout << "\nReplace with dont match case: " << endl;
	cout <<ReplaceWordInStringUsingSplit(Write, "jordan", "USA",false);
	cout << endl;


	return 0;
}
