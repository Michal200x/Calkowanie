#include<iostream>
#include<iomanip>
#include <cmath>
#include <math.h>

using namespace std;

double fsin(double x)
{
    return sin(x);
}
double f(double x)
{
    return x * x + 2 * x + 5;
}
double fexp(double x)
{
    return exp(x);
}


double Pole1(double a, double b, double n)
{
    double x = (b - a) / n; 
    double S = 0.0; 
    double srodek = a + (b - a) / (2.0 * n); 

    for (int i = 0; i < n; i++)
    {
        S += fsin(srodek); 
        srodek += x;    
    }
    return S * x;
}
double Pole2(double a, double b, double n)
{
    double x = (b - a) / n;
    double S = 0.0;
    double srodek = a + (b - a) / (2.0 * n);

    for (int i = 0; i < n; i++)
    {
        S += f(srodek);
        srodek += x;
    }
    return S * x;
}
double Pole3(double a, double b, double n)
{
    double x = (b - a) / n;
    double S = 0.0;
    double srodek = a + (b - a) / (2.0 * n);

    for (int i = 0; i < n; i++)
    {
        S += fexp(srodek);
        srodek += x;
    }
    return S * x;
}
double PoleTrap1(double a, double b, double n)
{
    double x = (b - a) / n; 
    double s = 0.0;
    for (int i = 1; i < n; i++)
    {
        s += fsin(a + i * x);
    }
    s = (s + (fsin(a) + fsin(b) ) / 2 ) * x;

    return s;
}
double PoleTrap2(double a, double b, double n)
{
    double x = (b - a) / n;
    double s = 0.0;
    for (int i = 1; i < n; i++)
    {
        s += f(a + i * x);
    }
    s = (s + (f(a) + f(b)) / 2) * x;

    return s;
}
double PoleTrap3(double a, double b, double n)
{
    double x = (b - a) / n;
    double s = 0.0;
    for (int i = 1; i < n; i++)
    {
        s += fexp(a + i * x);
    }
    s = (s + (fexp(a) + fexp(b)) / 2) * x;

    return s;
}
double PolePar1(double a, double b, double n)
{
    double s = 0.0, srodek = 0.0;
    double dx, x;
    dx = (b - a) / n;
    for (int i = 1; i <= n; i++)
    {
        x = a + i * dx;
        srodek += fsin(x - dx / 2);
        if (i < n)
        {
            s += fsin(x);
        }
    }
    s = dx / 6 * (fsin(a) + fsin(b) + 2 * s + 4 * srodek);

    return s;
}
double PolePar2(double a, double b, double n)
{
    double s = 0.0, srodek = 0.0;
    double dx, x;
    dx = (b - a) / n;
    for (int i = 1; i <= n; i++)
    {
        x = a + i * dx;
        srodek += f(x - dx / 2);
        if (i < n)
        {
            s += f(x);
        }
    }
    s = dx / 6 * (f(a) + f(b) + 2 * s + 4 * srodek);

    return s;
}
double PolePar3(double a, double b, double n)
{
    double s = 0.0, srodek = 0.0;
    double dx, x;
    dx = (b - a) / n;
    for (int i = 1; i <= n; i++)
    {
        x = a + i * dx;
        srodek += fexp(x - dx / 2);
        if (i < n)
        {
            s += fexp(x);
        }
    }
    s = dx / 6 * (fexp(a) + fexp(b) + 2 * s + 4 * srodek);

    return s;
}

int main()
{
    double a, b, n;
    cout << "Podaj przedzial [a, b]" << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Podaj liczbe n figor: ";
    cin >> n;

    cout << endl << "Wartosc calki metoda prostokatow dla sin(x): " << Pole1(a, b, n) << endl;
    cout << "Wartosc calki metoda prostokatow dla (x^2 + 2x + 5): " << Pole2(a, b, n) << endl;
    cout << "Wartosc calki metoda prostokatow dla exp(x): " << Pole3(a, b, n) << endl;

    cout << endl << "---------------------------------------------------" << endl;

    cout  << endl << "Wartosc calki metoda trapezow dla sin(x): " << PoleTrap1(a, b, n) << endl;
    cout << "Wartosc calki metoda trapezow dla (x^2 + 2x + 5): " << PoleTrap2(a, b, n) << endl;
    cout << "Wartosc calki metoda trapezow dla exp(x): " << PoleTrap3(a, b, n) << endl;
   
    cout << endl << "---------------------------------------------------" << endl;

    cout << endl << "Wartosc calki metoda parabol dla sin(x): " << PolePar1(a, b, n) << endl;
    cout << "Wartosc calki metoda parabol dla (x^2 + 2x + 5): " << PolePar2(a, b, n) << endl;
    cout << "Wartosc calki metoda parabol dla exp(x): " << PolePar3(a, b, n) << endl;

    return 0;
}