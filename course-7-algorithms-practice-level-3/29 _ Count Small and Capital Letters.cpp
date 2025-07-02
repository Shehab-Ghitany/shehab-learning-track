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

enum enWhatCount { Small = 0, Capital = 1, All = 2 };

short CountLetterByEnum(string Write , enWhatCount WhatCount = enWhatCount::All)
{
	short Counter = 0;

	if (WhatCount == enWhatCount::All)
	{
		return Write.length();
	}

	for (int i = 0; i < Write.length(); i++)
	{
		if (WhatCount == enWhatCount::Capital && isupper(Write[i]))
		{
			Counter++;
		}
		else if (WhatCount == enWhatCount::Small && islower(Write[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

void PrintCountLetters(string Write)
{
	short CountUpper = 0, CountLower = 0;

	cout << "\nString Length = " << Write.length() << endl;

	for (int i = 0; i < Write.length(); i++)
	{
		if (isupper(Write[i]))
		{
			CountUpper++;
		}
		else if (islower(Write[i]))
		{
			CountLower++;
		};
	}
	
	cout << "Capital Letters Count = " << CountUpper << endl;
	cout << "Small Letters Count   = " << CountLower << endl;
}


int main()
{
	string Write = ReadString();

	PrintCountLetters(Write);
	cout << endl;

	cout << "\nString Length = " << CountLetterByEnum(Write) << endl;
	cout << "Capital Letters Count = " << CountLetterByEnum(Write, enWhatCount::Capital) << endl;
	cout << "Small Letters Count   = " << CountLetterByEnum(Write, enWhatCount::Small) << endl;
	return 0;
}