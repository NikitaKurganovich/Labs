#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void validation_for_string(char* text);
int validation();
int size_of_string(char* text);
void longest_group_search(char* text, int size);

int main()
{
	char text[256];

	cout << "Entre a string: ";
	cout << endl;
	validation_for_string(text);
	cout << endl;

	int size = size_of_string(text);
	longest_group_search(text, size);
	cout << endl;
}

void validation_for_string(char* text)
{
	int index = 0;
	for (index; text[index] != '\0'; index++)
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

int size_of_string(char* text)
{
	int i = 0;
	while (true)
	{
		if (text[i] == '\0') break;
		i++;
	}
	return i;
}

void longest_group_search(char* text, int size)
{
	int biggest_group = 0;
	int identical_group = 0;

	for (int i = 0; i < size; i++)
	{
		int current_group_size = 0;
		if ((text[i] == '1') || (text[i] == '0'))
		{
			current_group_size++;

			for (int k = i + 1; k < size; k++)
			{
				if ((text[k] == '0') || (text[k] == '1'))
				{
					current_group_size++;
				}
				else
					break;
			}
		}
		if (current_group_size > biggest_group)
			{
				biggest_group = current_group_size;
				identical_group = 0;
			}
		else
			if (current_group_size == biggest_group)
				identical_group++;
	}

	if (identical_group == 0)
	{
		if (biggest_group == 0)
			cout << "String contains only spaces!" << endl;
		else
		{
			if (biggest_group == size)
				cout << "String doesn't contain any spaces!" << endl;
			else
				cout << "Count of symbols in longest group: " << biggest_group;
		}
	}
	else cout << "String contains " << identical_group + 1 << " groups that have " << biggest_group << " symbols!";
}
