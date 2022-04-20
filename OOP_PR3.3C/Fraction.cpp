#include "Fraction.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

Fraction::Fraction() {
    integer = 0;
    fraction = 0;
}

Fraction::Fraction(int f, int s) {
    integer = f;
    fraction = s;
}

Fraction::Fraction(Fraction& a) {
    integer = a.integer;
    fraction = a.fraction;
}

Fraction& Fraction::operator = (const Fraction& f) {
    integer = f.integer;
    fraction = f.fraction;
    return *this;
}

istream& operator >> (istream& in, Fraction& a)
{
    cout << " Set the integer "; in >> a.integer;
    cout << " Set the fraction "; in >> a.fraction;
    return in;
}

ostream& operator << (ostream& out, const Fraction& a)
{
    out << string(a);
    return out;
}

Fraction::operator string () const
{
    stringstream a;
    a <<  integer << "." << fraction << endl;
    return a.str();
}

void Read(Fraction& a)
{
    cout << "Set the number:" << endl; cin >> a;
}

void Display(Fraction& a)
{
    cout << a;
}

double toNumber(string str)
{
    double number;
    istringstream ( str ) >> number;
    return number;
}

double convertToDouble(Fraction& a)
{
    return toNumber(string(a));
}

Fraction toFraction(double n)
{
    stringstream s;
    s << n;
    string str = s.str();
    string integer_a = strtok(str.data(), ".");
    string fraction_a = strtok(0, "");

    Fraction nn;
    long int integer_b;
    istringstream ( integer_a ) >> integer_b;
    nn.set_integer(integer_b);
    
    unsigned short int fraction_b;
    istringstream ( fraction_a ) >> fraction_b;
    nn.set_fraction(fraction_b);
    
    return nn;
}

Fraction operator + (Fraction& a, Fraction& b)
{
    double sum =  convertToDouble(a) + convertToDouble(b);
    return toFraction(sum);
}

Fraction operator * (Fraction& a, Fraction& b)
{
    double sum =  convertToDouble(a) * convertToDouble(b);
    return toFraction(sum);
}
