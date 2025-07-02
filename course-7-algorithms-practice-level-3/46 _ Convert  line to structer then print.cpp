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
	double AccountBalance;
};

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

stClientData FillClientData(vector <string> SplitString)
{
	stClientData ClientData;

	ClientData.AccountNumber = SplitString[0];
	ClientData.PinCode = SplitString[1];
	ClientData.Name = SplitString[2];
	ClientData.Phone = SplitString[3];
	ClientData.AccountBalance = stod(SplitString[4]);

	return ClientData;
}

void PrintClientData(stClientData ClientData)
{
	cout << "Account Number : " << ClientData.AccountNumber;
	cout << "\nPin Code       : " << ClientData.PinCode;
	cout << "\nName           : " << ClientData.Name;
	cout << "\nPhone          : " << ClientData.Phone;
	cout << "\nAccount Balance: " << ClientData.AccountBalance;
}


int main()
{
	string Write = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";

	cout << "Line Record is: " << endl;
	cout << Write;


	vector <string> SplitString = VSplitString(Write, "#//#");
	stClientData ClientData = FillClientData(SplitString);

	cout << "\n\nThe following is the extracted client record: " << endl << endl;
	PrintClientData(ClientData);

	return 0;
}