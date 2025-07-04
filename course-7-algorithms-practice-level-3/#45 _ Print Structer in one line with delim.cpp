#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance;
};

stClientData FillClientData()
{
	stClientData ClientData;

	cout << "Enter Account Number? ";
	cin >> ClientData.AccountNumber;
	cout << "Enter PinCode? ";
	cin >> ClientData.PinCode;
	cout << "Enter Name? ";
	cin.ignore();
	getline(cin, ClientData.Name);
	cout << "Enter Phone? ";
	cin >> ClientData.Phone;
	cout << "Enter AccountBalance? ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}


string StructToLineString(stClientData ClientData , string delim)
{
	vector<string>vString;

	vString.push_back(ClientData.AccountNumber);
	vString.push_back(ClientData.PinCode);
	vString.push_back(ClientData.Name);
	vString.push_back(ClientData.Phone);
	vString.push_back(to_string(ClientData.AccountBalance));


	string Write;

	for (string& s : vString)
	{
		Write += s + delim;
	}

	return Write.substr(0, Write.length() - delim.length());
}


int main()
{
	cout << "Please enter Client Data: " << endl << endl;

	stClientData ClientData = FillClientData();

	cout << "\n\n\nClient Record for Saving is:\n";
	cout << StructToLineString(ClientData, "#//#");

	return 0;
}