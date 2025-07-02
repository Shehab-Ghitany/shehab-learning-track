#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
	char Letter;

	cout << "\nPlease Enter Your String?" << endl;
	cin >> Letter;

	return Letter;
}

bool IsVowel(char Letter)
{
	char arr[5] = { 'a','e','i','o','u' };

	for (int i=0;i<5;i++)
	{
		if (tolower(Letter) == arr[i])
			return true;
	}
	return false;
}
	

int main()
{
	char Letter = ReadChar();

	cout << endl;

	if (IsVowel(Letter))
	{
		cout << "Yes Letter \'" << Letter << "\' is vowel" << endl;
	}
	else
	{
		cout << "No Letter \'" << Letter << "\' is NOT vowel" << endl;
	}

	return 0;
}