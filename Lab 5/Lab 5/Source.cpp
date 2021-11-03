#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

int validation(char* message);
void randomizing_array(int* array, int size);
void manual_array(int* array, int size);
int operation(int* array, int size);

int main()
{
	const int SIZE_OF_TEXT_ARRAY = 100;
	char input;
	char message_for_array[SIZE_OF_TEXT_ARRAY] = "Entre a size of array: ";

	int size = validation(message_for_array);

	int* array = new int[size];

	cout << "Would you like to generate array (y - yes, n - no (manual input))? ";
	while (true)
	{
		cin >> input;
		switch (tolower(input))
		{
		case 'y': cout << "Array will be generated! ";
			randomizing_array(array, size);
			break;
		case 'n': cout << "Enter the array manually! ";
			manual_array(array, size);
			break;
		default: cout << "Invalid input!" << endl; continue;
		}
		break;
	}
	operation(array, size);

	delete[]array;
}

void randomizing_array(int* array, int size)
{
	const int SIZE_OF_TEXT_ARRAY = 100;
	while(true)
	{
	char message_for_minimum[SIZE_OF_TEXT_ARRAY] = "Entre a minimum of range: ";
	int min_of_range = validation(message_for_minimum);

	char message_for_maximum[SIZE_OF_TEXT_ARRAY] = "Entre a maximum of range: ";
	int max_of_range = validation(message_for_maximum);

	if (max_of_range <= min_of_range)
		{
		cout << "Error! Invalid range!" << endl;
		continue;
		}

	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % (max_of_range - min_of_range + 1) + min_of_range;
		if (i == size - 1) cout << array[i] << endl;
		else cout << array[i] << ", ";
	}
	break;
	}
}

void manual_array(int* array, int size)
{
	const int SIZE_OF_TEXT_ARRAY = 100;

	cout << "Your manual array: " << endl;

	char message_for_manual_array[SIZE_OF_TEXT_ARRAY] = " ";
	for (int i = 0; i < size; i++)
	{
		array[i] = validation(message_for_manual_array);
		if (i == size - 1) cout << array[i] << endl;
		else cout << array[i] << ", ";
	}
}

int operation(int* array, int size)
{
	int last_positive_index = size - 1, sum = 0;

	for (int i = last_positive_index; i > 0; i--)
	{
		if (array[i] > 0)
		{
			last_positive_index = i;
			break;
		}
	}
	if (array[last_positive_index] < 0)
	{
		cout << "There are no positive numbers in the array!" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < last_positive_index; i++)
		{
			sum += array[i];
		}
		cout << "The sum of the array elements up to the last positive element: " << sum;
	}
	return sum;
}

int validation(char* message)
{
	int n;
	while (true)
	{
		cout << message;
		cin >> n;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input !" << endl;
		}
		else break;
	}
	return n;
}