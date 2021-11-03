#include <iostream>
#include <math.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

double function_Sx(double, double);
double function_Yx(double);
void Out_Rez(double, double, double, double, double);

double function_Sx(double num_n, double start) {
	double fun_Sx = 1, sum = 1;
	double const PI = 3.141;
	for (int k = 1; k <= num_n; k++)
	{
		sum = sum * (start / k);
		fun_Sx += sum * cos((k * PI) / 4);
	}
	return fun_Sx;
}

double function_Yx(double start) {
	double const PI = 3.141;
	return exp(start * cos(PI / 4)) * cos(start * sin(PI / 4));
}

void Out_Rez(double function_Sx, double function_Yx, double start, double end_num, double step) {
	cout << "Value of x: " << start << ", value of Y(x): " << function_Yx << ", value of S(x): " << function_Sx << ", value of Y(x) - S(x) " << function_Yx - function_Sx << endl;
}

int main() {
	double start, end_num, step, num_n;
	while (true)
	{
		cout << "Entre a start falue: " << endl;
		cin >> start;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect value!" << endl;
		}
		else break;
	}
	while (true)
	{
		cout << "Entre a final falue: " << endl;
		cin >> end_num;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect value!" << endl;
		}
		else break;
	}
	while (true)
	{
		cout << "Entre a number of operation: " << endl;
		cin >> num_n;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect value!" << endl;
		}
		else break;
	}
	while (true)
	{
		cout << "Entre a falue of step: " << endl;
		cin >> step;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect value!" << endl;
		}
		else break;
	}
	for (double i = start; i <= end_num; i += step)
	{
		Out_Rez(function_Sx(num_n, start), function_Yx(start), start, end_num, step);
		start += step;
	}
}