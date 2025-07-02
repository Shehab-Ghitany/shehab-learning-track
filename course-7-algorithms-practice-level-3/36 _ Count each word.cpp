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

short CountWords(string Write)
{
	string delim = " ";
	short Counter = 0;
	cout << "\nThe number of words in your string is: ";

	short pos = 0;
	string sword;

	while ((pos = Write.find(delim)) != std::string::npos)
	{
		sword = Write.substr(0, pos);
		if (sword != "")
		{
			Counter++;
		}
		Write.erase(0, pos + delim.length());
	}

	if (Write != "")
	{
		Counter++;
	}

	return Counter;
}


int main()
{

	cout << CountWords(ReadString()) << endl;

	return 0;
}