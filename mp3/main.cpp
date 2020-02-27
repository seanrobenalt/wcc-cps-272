#include <cstddef>
#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main() {
  miniList<char> myList;

  myList.insertAtFront('c');
  myList.insertAtFront('a');
  myList.insertAtFront('r');
  myList.insertAtBack('e');
  myList.insertAtBack('c');
  myList.insertAtBack('a');
  myList.insertAtBack('r');

  myList.print();

  return 0;
}
