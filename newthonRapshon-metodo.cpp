#include <iostream>
#include <conio.h> 
#include <math.h>

using namespace std;

void iter(double x);
double f(double x);
double fp(double x);
void error(double xact, double xant);
void mostrar(double a, string tipo);

int main()
{
	int i = 0;
    while (true)
	{
		cout << "iteracion" << i <<endl;
		double x = 0;
		cout << "Valor de x";
		cin >> x;

		iter(x);

		i++;
	}

	getch();
	return 0;
}

void iter(double x)
{
	double xn = 0;
	string a = "xn: ";

	xn = x - (f(x) / fp(x));

	mostrar(xn, a);
	error(xn, x);

	cout << endl;
}

double f(double x)
{
	string a = "f: ";
	double f = pow(x, 3) + (2 * x) - 1;

	mostrar(f, a);
	return f;
}

double fp(double x)
{
	string a  = "f': ";
	double fp = 3 * pow(x, 2) + 2;

	mostrar(fp, a);
	return fp;
}

void error(double xact, double xant)
{
	string a = "Error: ";

	double err = 0;
	err = abs(xact - xant) * 100;

	mostrar(err, a);
}

void mostrar(double a, string tipo)
{
	cout << tipo << a << endl;
}