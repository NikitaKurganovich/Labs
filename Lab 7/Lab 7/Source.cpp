#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void validation_for_string(char* text, int size);
int validation();

int main()
{
	cout << "Entre a string size: ";
	int size = validation();
	size++;

	char* text = new char[size];

	cout << "Entre a string: ";
	validation_for_string(text, size);

	delete[]text;
}

void validation_for_string(char* text, int size)
{
	int index = 0;
	for (index; index != size - 1; index++)
	{
		text[index] = _getch();
		if (text[index] == 13) break;
		if (!(text[index] == '0' || text[index] == '1' || text[index] == ' ')) continue;
		cout << text[index];
	}
	text[index] = '\0';
}

int validation()
{
	int n;
	while (true)
	{
		cin >> n;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!" << endl;
		}
		else break;
	}
	return n;
}
