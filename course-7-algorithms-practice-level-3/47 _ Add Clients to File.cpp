#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

struct stClientData {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

void ResetScreen()
{
	system("cls");
	system("color 0F");

}

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

string ConvertRecordToLine(stClientData ClientData, string delim = "#//#") {
	string  Write = "";

	Write += ClientData.AccountNumber + delim;
	Write += ClientData.PinCode + delim;
	Write += ClientData.Name + delim;
	Write += ClientData.Phone + delim;
	Write += to_string(ClientData.AccountBalance);

	return Write;
}

void SaveRecordIntoFile(string ConvertRecordToLine)
{
	fstream myFile;

	myFile.open("MyClients.txt", ios::out | ios::app);

	if (myFile.is_open())
	{
		myFile << ConvertRecordToLine << endl ;

		myFile.close();
	}

}


int main()
{
	char addmore = 'y';

	do {

		ResetScreen();

		cout << "Adding New Client: " << endl << endl;

		stClientData ClientData = FillClientData();

		string Write = ConvertRecordToLine(ClientData, "#//#");
		SaveRecordIntoFile(Write);

		cout << "\n\nClient Added Successfully, do you want to add more clients?\n";
		cin >> addmore;

	} while (addmore == 'Y' || addmore == 'y');

	return 0;
}