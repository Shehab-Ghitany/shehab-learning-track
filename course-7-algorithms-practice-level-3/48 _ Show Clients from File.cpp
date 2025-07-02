#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

void PrintClientHeader()
{

	cout << string(5, '\t') << "Client List" << endl;
	cout << string(100, '_') << endl << endl;
	cout << left << setw(18) << "| Account Number";
	cout << setw(13) << "| Pin Code";
	cout << setw(40) << "| Client Name";
	cout << setw(17) << "| Phone";
	cout << setw(15) << "| Balance" << endl;
	cout << string(100, '_') << endl << endl;

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
	cout << left << "| " << setw(16) << ClientData.AccountNumber;
	cout << "| " << setw(11) << ClientData.PinCode;
	cout << "| " << setw(38) << ClientData.Name;
	cout << "| " << setw(15) << ClientData.Phone;
	cout << "| " << setw(13) << ClientData.AccountBalance << endl;
}

void ReadClientsFileOnScreen (string Write)
{
	vector <string> SplitString = VSplitString(Write, "#//#");
	stClientData ClientData = FillClientData(SplitString);

	PrintClientData(ClientData);
}

void PrintFileContent(string ClientsFileName)
{
	fstream myFile;

	myFile.open(ClientsFileName, ios::in);

	if (myFile.is_open())
	{
		string Line;

		while (getline(myFile, Line))
		{
			ReadClientsFileOnScreen(Line);
		}

		myFile.close();
	}

}

int main()
{
	PrintClientHeader();
	PrintFileContent(ClientsFileName);

	cout << endl << string(100, '_') << endl << endl;

	return 0;
}