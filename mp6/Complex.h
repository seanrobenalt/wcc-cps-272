#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex {
  friend ostream& operator<<(ostream& out, const Complex& theComplex);
  friend istream& operator>>(istream& in, Complex& theComplex);
  friend Complex operator+(const Complex& lhs, const Complex& rhs);
  friend Complex operator-(const Complex& lhs, const Complex& rhs);
  friend Complex operator*(const Complex& lhs, const Complex& rhs);
  friend Complex operator/(const Complex& lhs, const Complex& rhs);

public:
  Complex(double re = 0.0, double im = 0.0) {};
  double getReal(void) const;
  double getImaginary(void) const;
  void setReal(double re);
  void setImaginary(double im);
  void convertStringToComplex(const string& complexString);

private:
  double real;
  double imag;
};

#endif
