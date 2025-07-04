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

stClientData ConvertLinetoRecord(string Line , string delim = "#//#")
{
	stClientData ClientData;
	vector <string> SplitString;

	SplitString = VSplitString(Line, delim);

	ClientData.AccountNumber = SplitString[0];
	ClientData.PinCode = SplitString[1];
	ClientData.Name = SplitString[2];
	ClientData.Phone = SplitString[3];
	ClientData.AccountBalance = stod(SplitString[4]);

	return ClientData;
}

vector <stClientData> LoadClientDataFromFile(string ClientsFileName)
{
	vector <stClientData> vClients;

	fstream myFile;
	myFile.open(ClientsFileName, ios::in);

	if (myFile.is_open())
	{
		string Line;
		stClientData Client;

		while (getline(myFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}

		myFile.close();
	}
	return vClients;
}

void PrintClientCard(stClientData Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, stClientData& Client)
{
	vector <stClientData> vClients = LoadClientDataFromFile(ClientsFileName);

	for (stClientData& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "Please enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool WantDelete()
{
	char SureDelete = 'y';

	cout << "\n\nAre you sure you want delete this client? y/n ?  ";
	cin >> SureDelete;
	if (tolower(SureDelete) == 'y')
	{
		return true;
	}
	return false;
}

vector <stClientData> DataEditAfterDelete(string AccountNumber, vector <stClientData> ClientsAfterDelete)
{
	vector <stClientData> AllClientsBeforeEdit = LoadClientDataFromFile(ClientsFileName);

	for (stClientData& C : AllClientsBeforeEdit)
	{
		if (C.AccountNumber != AccountNumber)
		{
			ClientsAfterDelete.push_back(C);
		}
	}
	return ClientsAfterDelete;
}

void ClearFile(string ClientsFileName)
{
	fstream myFile;

	myFile.open(ClientsFileName, ios::out);

	if (myFile.is_open())
	{

		myFile.close();
	}
}

string StructToLineString(stClientData ClientData, string delim)
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

void SaveRecordIntoFile(string ClientsFileName, string ConvertRecordToLine)
{
	fstream myFile;

	myFile.open(ClientsFileName, ios::out | ios::app);

	if (myFile.is_open())
	{
		myFile << ConvertRecordToLine << endl;

		myFile.close();
	}

}

void DataFileAfterDelete_aClient(string AccountNumber)
{

	if (WantDelete())
	{
	vector <stClientData> ClientsAfterDelete;

		ClientsAfterDelete = DataEditAfterDelete(AccountNumber, ClientsAfterDelete);

		ClearFile(ClientsFileName);

		for (stClientData& C_AfterDelete : ClientsAfterDelete)
		{
			string LineOfClient = StructToLineString(C_AfterDelete, "#//#");
			SaveRecordIntoFile(ClientsFileName, LineOfClient);
		}
		cout << "\n\nClient Deleted Successfuly." << endl;
	}
}


int main()
{
	stClientData Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);

		DataFileAfterDelete_aClient( AccountNumber);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Fount!" << endl;
	}

	return 0;
}