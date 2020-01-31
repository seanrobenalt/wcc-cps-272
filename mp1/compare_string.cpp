#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  cout << "\n-----\nBegin string comparison machine problem by Sean Robenalt - CPS 272 Online\n\n";
  bool matches_pattern = true;

  stack<char> reverse_string;

  string user_input;
  cout << "\nInput two strings separated by a #: ";
  cin >> user_input;

  string first;

  bool first_string = true;
  for (int i = 0; i < user_input.length(); i++) {

    if (user_input[i] == '#') {
      first_string = false;
    } else if (first_string) {
      first += user_input[i];
    } else {
      reverse_string.push(user_input[i]);
    }
  }

  if (first.length() != reverse_string.size()) {
    matches_pattern = false;
  } else {
    int i = 0;
    while (!reverse_string.empty())
    {
       if (reverse_string.top() != first[i]) {
         matches_pattern = false;
         break;
       }
       reverse_string.pop();
       i++;
    }
  }

  if (matches_pattern)
    cout << user_input << " Matches pattern.\n";
  else
    cout << user_input << " Doesn't match pattern.\n";

  return 0;
}
