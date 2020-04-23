#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
  string firstComplex;
  string secondComplex;

  Complex complexOne;
  Complex complexTwo;

  cout << "\nEnter first complex number: ";
  cin >> firstComplex;
  complexOne.convertStringToComplex(firstComplex);

  cout << "\nEnter second complex number: ";
  cin >> secondComplex;
  complexTwo.convertStringToComplex(secondComplex);

  complexOne + complexTwo;
  complexOne - complexTwo;
  complexOne * complexTwo;
  complexOne / complexTwo;

  return 0;
}
