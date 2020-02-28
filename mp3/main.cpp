#include <cstddef>
#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main() {
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

  myListOf20.print();
  myListOf15.print();

  return 0;
}
