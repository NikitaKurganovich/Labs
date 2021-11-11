#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int SIZE_OF_TEXT_ARRAY = 100;

char message_for_height[SIZE_OF_TEXT_ARRAY] = "Entre a height of array: ";
char message_for_width[SIZE_OF_TEXT_ARRAY] = "Entre a width of array: ";
char message_for_minimum[SIZE_OF_TEXT_ARRAY] = "Entre a minimum of range: ";
char message_for_maximum[SIZE_OF_TEXT_ARRAY] = "Entre a maximum of range: ";

int validation(char* message);
void randomizing_array(int** array, int height, int width);
void vector_creation(int**, int, int, int*);

int main()
{
	int height = validation(message_for_height);

	int width = validation(message_for_width);

	int** array = new int* [height];
	for (int i = 0; i < height; i++) array[i] = new int[width];

	randomizing_array(array, width, height);
	int* vector = new int[height];
	vector_creation(array, height, width, vector);
	delete[]vector;
	for (int i = 0; i < width; i++) delete[]array[i];
	delete[]array;
}

void randomizing_array(int** array, int width, int height)
{
	int min_of_range = validation(message_for_minimum);

	int max_of_range = validation(message_for_maximum);

	srand(time(0));
	for (int k = 0; k < height; k++)
	{
		for (int i = 0; i < width; i++)
		{
			array[k][i] = rand() % (max_of_range - min_of_range + 1) + min_of_range;
			cout << array[k][i] << "| ";
		}
		cout << endl;
	}
}

void vector_creation(int** array, int height, int width, int* vector)
{

	int index = width / 2;

	cout << "Your vector: " << endl;

	for (int k = 0; k < height; k++)
	{
		for (int i = 0; i < index; i++)
		{
			if (array[k][i] == array[k][width - i - 1 ]) vector[k] = 1;
			else
			{
				vector[k] = 0;
				break;
			}
		}
		cout << vector[k] << " |";
	}
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
			cout << "Invalid input!" << endl;
		}
		else break;
	}
	return n;
}