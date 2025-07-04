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
	double AccountBalance=0.0;
};

vector <string> VSplitString(string Write, string delim = " ")
{
	vector <string> SplitString;

	auto pos = 0;
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
	if (SplitString.size() >= 5) {
		ClientData.AccountNumber = SplitString[0];
		ClientData.PinCode = SplitString[1];
		ClientData.Name = SplitString[2];
		ClientData.Phone = SplitString[3];
		ClientData.AccountBalance = stod(SplitString[4]); }

	return ClientData;
}

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

void PrintClientData(stClientData ClientData)
{
	cout << left << "| " << setw(16) << ClientData.AccountNumber;
	cout << "| " << setw(11) << ClientData.PinCode;
	cout << "| " << setw(38) << ClientData.Name;
	cout << "| " << setw(15) << ClientData.Phone;
	cout << "| " << setw(13) << ClientData.AccountBalance << endl;
}

void ReadClientLineOnScreen(string Write)
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
			ReadClientLineOnScreen(Line);
		}

		myFile.close();
	}

}

void PrintClientsOnlyOnScreen()
{
	PrintClientHeader();
	PrintFileContent(ClientsFileName);

	cout << endl << string(100, '_') << endl << endl;
}




stClientData ConvertLinetoRecord(string Line , string delim = "#//#")
{
	stClientData ClientData;
	vector <string> SplitString;
	SplitString = VSplitString(Line, delim);

	if (SplitString.size() >= 5) {
		ClientData.AccountNumber = SplitString[0];
		ClientData.PinCode = SplitString[1];
		ClientData.Name = SplitString[2];
		ClientData.Phone = SplitString[3];
		ClientData.AccountBalance = stod(SplitString[4]); }

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

stClientData FillClientDataEdit(stClientData ClientData, string AccountNumber)
{
	ClientData.AccountNumber = AccountNumber;
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

bool WantUpdate()
{
	char SureUpdate = 'y';

	cout << "\n\nAre you sure you want update this client? y/n ?  ";
	cin >> SureUpdate;
	if (tolower(SureUpdate) == 'y')
	{
		return true;
	}
	return false;
}

vector <stClientData> DataAfterEdit(string AccountNumber, vector <stClientData> ClientsAfterEdit)
{
	vector <stClientData> AllClientsBeforeEdit = LoadClientDataFromFile(ClientsFileName);

	for (stClientData& C : AllClientsBeforeEdit)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C = FillClientDataEdit(C, AccountNumber);
			ClientsAfterEdit.push_back(C);
		}
		else
		{
			ClientsAfterEdit.push_back(C);
		}
	}
	return ClientsAfterEdit;
}

void DataFileAfterEdit_aClient(string AccountNumber)
{
	vector <stClientData> ClientsAfterEdit;
	ClientsAfterEdit = DataAfterEdit(AccountNumber, ClientsAfterEdit);

	ClearFile(ClientsFileName);

	for (stClientData& C_AfterEdit : ClientsAfterEdit)
	{
		string LineOfClient = StructToLineString(C_AfterEdit, "#//#");
		SaveRecordIntoFile(ClientsFileName, LineOfClient);
	}
	cout << "\n\nClient Updated Successfuly." << endl;
}


int main()
{
	char again = 'y';

	do {
	PrintClientsOnlyOnScreen();

	stClientData Client;
	string AccountNumber = ReadClientAccountNumber();

		if (FindClientByAccountNumber(AccountNumber, Client))
		{
			PrintClientCard(Client);

			if (WantUpdate()) {
				DataFileAfterEdit_aClient(AccountNumber);
			}
		PrintClientsOnlyOnScreen();
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Fount!" << endl << endl;
		}

		cout << endl << endl << "Want Do you want to update another client? (y/n):  ";
		cin >> again;

		system("cls");
	} while (tolower(again) == 'y');

	return 0;
}