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

void ReplaceWord(string Write ,string ToReplace ,string Replacement )
{

	string delim = " ";

	cout << "\nString after Replace: " << endl;

	short pos = 0;
	string sword;

	while ((pos = Write.find(delim)) != std::string::npos)
	{
		sword = Write.substr(0, pos);

		if (sword != "")
		{
			if (sword == ToReplace )
				cout << Replacement << " ";
			else
				cout << sword << " ";
		}
		Write.erase(0, pos + delim.length());
	}

	if (Write != "")
	{
		if (Write == ToReplace)
			cout << Replacement << " ";
	else
		cout << Write << " ";
	}

}


int main()
{
	string Write = ReadString();
	string ToReplace = ("Jordan");
	string Replacement = "USA";


	ReplaceWord(Write, ToReplace, Replacement);
	cout << endl;

	return 0;
}