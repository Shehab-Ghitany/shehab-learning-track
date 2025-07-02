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

vector <string> VSplitString(string Write , string delim = " ")
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


int main()
{
	vector <string> SplitString = VSplitString(ReadString()," ");

	cout << "\nTokens = " << SplitString.size() << endl;

	for (string & Words : SplitString)
		cout << Words << endl;


	return 0;
}