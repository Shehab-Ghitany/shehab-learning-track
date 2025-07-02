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

vector <string> VJoinString(string delim = " ")
{
	vector <string> SplitString;
	
	char ans = 'N';

	do
	{
		if (ans == 'Y' || ans == 'y')
		{
			SplitString.push_back(delim);
		}

		string Write;

		cout << "Please Enter Your String?" << endl;
		cin >> Write;


		cout << endl << "do you want to add another string ? Y/N ?  ";
		cin >> ans;

		cout << endl;
	

		if (Write != "")
	{
		SplitString.push_back(Write);
	}

	} while (ans == 'Y' || ans == 'y');

	return SplitString;
}


int main()
{

	vector <string> SplitString = VJoinString(" ");
	
	for (string& Words : SplitString)
	{
		cout << Words;
	}

	cout << endl;


	return 0;
}