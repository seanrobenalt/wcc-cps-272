#include <iostream>

#include "Complex.h"

using namespace std;

istream &operator>>(istream &in, Complex &theComplex)
{
  double re;
  double im;

	if (in >> re >> im) {
    theComplex.setReal(re);
    theComplex.setImaginary(im);
  };

	return in;
}

ostream &operator<<(ostream &out, const Complex &theComplex)
{
  out << theComplex.getReal() << " " << theComplex.getImaginary() << "\n";

	return out;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
  Complex c;
  c.real = lhs.real + rhs.real;
  c.imag = lhs.imag + rhs.imag;
  cout << "\n(" << lhs.real << " + " << lhs.imag << ")i" << " + (" << rhs.real << " + " << rhs.imag << ")i = ";
  cout << c.real << " + " << c.imag << "i\n";
  return c;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
  Complex c;
  c.real = lhs.real - rhs.real;
  c.imag = lhs.imag - rhs.imag;
  cout << "\n(" << lhs.real << " + " << lhs.imag << ")i" << " - (" << rhs.real << " + " << rhs.imag << ")i = ";
  cout << c.real << " - " << c.imag << "i\n";
  return c;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
  Complex c;
  c.real = (lhs.real * rhs.real) - (lhs.imag * rhs.imag);
  c.imag = lhs.imag - rhs.imag;
  cout << "\n(" << lhs.real << " + " << lhs.imag << ")i" << " * (" << rhs.real << " + " << rhs.imag << ")i = ";
  cout << c.real << " * " << c.imag << "i\n";
  return c;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
  Complex c;
  c.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag))/((rhs.real * rhs.real) + (rhs.imag * rhs.imag));
  c.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag))/((rhs.real * rhs.real) + (rhs.imag * rhs.imag));
  cout << "\n(" << lhs.real << " + " << lhs.imag << ")i" << " / (" << rhs.real << " + " << rhs.imag << ")i = ";
  cout << c.real << " / " << c.imag << "i\n";
  return c;
}

double Complex::getReal() const
{
  return real;
}

double Complex::getImaginary() const
{
  return imag;
}

void Complex::setReal(double re)
{
  real = re;
}

void Complex::setImaginary(double im)
{
  imag = im;
}

void Complex::convertStringToComplex(const string& complexString)
{
  string temp = complexString;
  temp.pop_back();

  char delimiter;

  if (temp.find('+'))
  {
    delimiter = '+';
  }
  else if (temp.find('-'))
  {
    delimiter = '-';
  }
  else if (temp.find('*'))
  {
    delimiter = '*';
  }
  else if (temp.find('/'))
  {
    delimiter = '/';
  }
  else
    cout << "\nInvalid operator.\n";

  real = stod(temp.substr(0, temp.find(delimiter)));
  imag = stod(temp.substr(temp.find(delimiter)+1, temp.size()));
}
