#include <iostream>
#include <stack>
using namespace std;

void multibaseOutput(int decimal_num, int base_num, stack<int> _remainders) {

  if (decimal_num == 0) {
    while (!_remainders.empty())
    {
      int num = _remainders.top();

      if (num > 10) {
        int temp = num+55;
        char num_as_char = temp;
        cout << num_as_char;
      } else {
        cout << num;
      }
       _remainders.pop();
    }
    cout << '\n';
    return;
  }

  int x = decimal_num % base_num;
  _remainders.push(x);

  multibaseOutput(decimal_num/base_num, base_num, _remainders);
}

int main() {
  cout << "\n-----\nBegin base calculator machine problem\n\n";
  stack<int> remainders;

  int decimal = -1;
  while (decimal < 0) {
    cout << "\nInput a non-negative number: ";
    cin >> decimal;
  }

  int base = 1;
  while ((base < 2 || base > 16) && base != 0) {
    cout << "\nInput a base between 2 and 16: ";
    cin >> base;
  }

  if (decimal == 0 && base == 0) {
    return 0;
  } else {
    cout << endl << decimal << " base " << base << " is ";
    multibaseOutput(decimal, base, remainders);
  }

  return 0;
}
