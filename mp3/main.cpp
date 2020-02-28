#include <cstddef>
#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main() {
  cout << "Starting the linked list machine problem for CPS 272 by Sean Robenalt\n\n";

  miniList<int> myListOf20;
  miniList<int> myListOf15;

  int counter = 1;

  int MAX_ENTER_20 = 20;
  int MAX_ENTER_15 = 15;

  while (counter <= MAX_ENTER_20) {
    int randomNum1 = rand() % 100 + 0;

    myListOf20.insertInOrder(randomNum1);

    if (counter <= MAX_ENTER_15) {
      int randomNum2 = rand() % 100 + 0;

      myListOf15.insertInOrder(randomNum2);
    }
    counter++;
  }

  cout << "If the first list has\n";
  myListOf20.print();

  cout << "\nAnd the second list has\n";
  myListOf15.print();

  miniList<int> myMergedList;
  myMergedList.mergeTwoSortedListsToAnother(myListOf20, myListOf15);

  cout << "\nThe result will be\n";
  myMergedList.print();

  cout << "\n";
  myMergedList.printCalculations();

  return 0;
}
