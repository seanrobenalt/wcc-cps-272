#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

bool balanced(string str) {
  stack<char> opening_brackets;

  bool parenthesis = false;

  for (int i = 0; i < str.length(); i++) {

    if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
      parenthesis = true;
      opening_brackets.push(str[i]);
    }

    if (!opening_brackets.empty()) {

      switch (str[i]) {
        case '}':
          if (opening_brackets.top() == '{') {
            opening_brackets.pop();
            continue;
          } else
            break;
        case ')':
          if (opening_brackets.top() == '(') {
            opening_brackets.pop();
            continue;
          } else
            break;
        case ']':
          if (opening_brackets.top() == '[') {
            opening_brackets.pop();
            continue;
          } else
            break;
      }
    } else
      break;
  }

  if ((opening_brackets.empty()) && (parenthesis == true))
    return true;
  else
    return false;
}

int main() {
  cout << "\n-----\nBegin balanced parenthesis machine problem by Sean Robenalt - CPS 272 Online\n\n";

  string file_name;
  cout << "\nEnter the filename: ";
  cin >> file_name;

  ifstream file(file_name);

  bool is_balanced = true;

  string line;
  while (getline(file, line)) {
    if (balanced(line) == false)
      is_balanced = false;
  }

  cout << "The symbols in " << file_name << " are ";

  if (is_balanced)
    cout << "balanced.\n";
  else
    cout << "not balanced.\n";

  return 0;
}
