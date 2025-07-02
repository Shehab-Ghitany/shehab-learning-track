#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string>vString, string delim)
{
	string Write;

	for (string& s : vString)
	{
		Write = Write + s + delim;
	}

	return Write.substr(0, Write.length() - delim.length());
}

string JoinString(string arr[], int length, string delim)
{
	string Write;

	for (int i = 0 ; i < length ; i++)
	{
		Write = Write + arr[i] + delim;
	}

	return Write.substr(0, Write.length() - delim.length());
}


int main()
{
	vector <string> Write = { "Mohammed" , "Fadi" , "Ali" , "Maher" };
	string arr[] = { "Mohammed" , "Fadi" , "Ali" , "Maher" };

	cout << "Vector after join: \n";
	cout << JoinString(Write, ", ") << endl;

	cout << "\n\nVector after join: \n";
	cout << JoinString(arr,4,", ") << endl;

	return 0;
}