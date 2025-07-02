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

short VowelCounter(string Write)
{
	short VowelCounter = 0;

	char arr[5] = { 'a','e','i','o','u' };

	for (int i = 0;i < Write.length() ;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			char Letter = Write.at(i);

			if (tolower(Letter) == arr[j])
				VowelCounter++;
		}
	}

	return VowelCounter;
}
	

int main()
{
	string Write= ReadString();

	cout << "\nNumber of vowels is: " << VowelCounter(Write) << endl;

	return 0;
}