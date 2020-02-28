#pragma once
#include <iostream>
using namespace std;

template <typename T> class miniList;

template <typename T>
class ListNode {
  friend class miniList<T>;
private:
  ListNode<T> *nextPointer;
  T data;
public:
  ListNode(const T& info) : data(info), nextPointer(nullptr) {}
  T getData() const { return data; }
};

template <typename T>
class miniList {
private:
  ListNode<T> *firstPointer;
  ListNode<T> *lastPointer;
  ListNode<T> *getNewNode(const T& value);
public:
  miniList();

  void insertAtFront(const T& value);
  void insertAtBack(const T& value);
  void insertInOrder(const T& value);
  void mergeTwoSortedListsToAnother(miniList<T> &listOne, miniList<T> &listTwo) ;
  void removeFromFront();
  void removeFromBack();
  bool isEmpty() const;
  void print() const;
  void printCalculations() const;
  T front();
  T back();
  int size();
  miniList<T> operator=(const miniList<T>& rhs);
};

template <typename T>
ListNode<T>* miniList<T>::getNewNode(const T& value) {
  return new ListNode<T>(value);
}

template <typename T>
miniList<T>::miniList() : firstPointer(nullptr), lastPointer(nullptr) {}

template <typename T>
void miniList<T>::insertAtFront(const T& value) {
  ListNode<T> *newPointer = getNewNode(value);

  if (isEmpty())
    firstPointer = lastPointer = newPointer;
  else {
    newPointer->nextPointer = firstPointer;
    firstPointer = newPointer;
  }
}

template <typename T>
void miniList<T>::insertAtBack(const T& value) {
  ListNode<T> *newPointer = getNewNode(value);

  if (isEmpty())
    firstPointer = lastPointer = newPointer;
  else {
    lastPointer->nextPointer = newPointer;
    lastPointer = newPointer;
  }
}

template <typename T>
void miniList<T>::insertInOrder(const T& value) {
	ListNode<T> *temp = firstPointer;
  ListNode<T> *newPointer = getNewNode(value);

	if (isEmpty())
		firstPointer = lastPointer = newPointer;
	else {

    if (value == temp->data) {
      // do nothing
    }

		else if (value < temp->data)
			insertAtFront(value);

    else {

      while (temp->nextPointer != nullptr && !(value < temp->nextPointer->data && value > temp->data))
				temp = temp->nextPointer;

			if (temp->nextPointer == nullptr)
				insertAtBack(value);

      else {
				newPointer->nextPointer = temp->nextPointer;
				temp->nextPointer = newPointer;
			}
		}
	}
}

template <typename T>
void miniList<T>::mergeTwoSortedListsToAnother(miniList<T> &listOne, miniList<T> &listTwo) {
  ListNode<T> *currentPointer = listOne.firstPointer;

  while (currentPointer != nullptr) {
    insertInOrder(currentPointer->data);
    currentPointer = currentPointer->nextPointer;
  }

  currentPointer = listTwo.firstPointer;
  while (currentPointer != nullptr) {
    insertInOrder(currentPointer->data);
    currentPointer = currentPointer->nextPointer;
  }
}

template <typename T>
void miniList<T>::removeFromFront() {
  if (isEmpty())
    return;

  ListNode<T> *temp = firstPointer;
  if (firstPointer == lastPointer)
    firstPointer = lastPointer = nullptr;
  else
    firstPointer = firstPointer->nextPointer;

  delete temp;
}

template <typename T>
void miniList<T>::removeFromBack() {
  if (isEmpty())
    return;

  ListNode<T> *temp = firstPointer;
  if (firstPointer == lastPointer) {
    delete firstPointer;
    firstPointer = lastPointer = nullptr;
    return;
  }

  while (temp->nextPointer->nextPointer != nullptr)
    temp = temp->nextPointer;

  lastPointer = temp;
  delete temp->nextPointer->nextPointer;
  temp->nextPointer = NULL;
}

template <typename T>
bool miniList<T>::isEmpty() const {
  return firstPointer == nullptr;
}

template <typename T>
void miniList<T>::print() const {
  if (isEmpty()) {
    cout << "List is empty\n";
    return;
  }

  ListNode<T> *currentPointer = firstPointer;
  while (currentPointer != nullptr) {
    cout << currentPointer->data << "\t";
    currentPointer = currentPointer->nextPointer;
  }

  cout << "\n";
}

template <typename T>
void miniList<T>::printCalculations() const {
  if (isEmpty()) {
    cout << "List is empty\n";
    return;
  }

  int sum = 0;
  int total = 0;

  ListNode<T> *currentPointer = firstPointer;
  while (currentPointer != nullptr) {
    sum += currentPointer->data;
    currentPointer = currentPointer->nextPointer;
    total++;
  }

  cout << "The sum of the final list’s elements is : " << sum << "\n";

  float avg = sum/total;
  cout << "The average of the final list is : " << avg << "\n";
}

template <typename T>
T miniList<T>::front() {
  if (!isEmpty())
    return firstPointer->data;
  return NULL;
}

template <typename T>
T miniList<T>::back() {
  if (!isEmpty())
    return lastPointer->data;
  return NULL;
}

template <typename T>
int miniList<T>::size() {
  ListNode<T> *temp = firstPointer;
  int counter = 0;

  if (isEmpty())
    return counter;

  while(temp != lastPointer) {
    temp = temp->nextPointer;
    counter++;
  }
  return counter;
}

template <typename T>
miniList<T> miniList<T>::operator=(const miniList<T>& rhs) {

  ListNode<T> *temp = rhs.firstPointer;

  if (rhs.isEmpty())
    return miniList<T>();

  while (temp != nullptr) {
    this->insertAtBack(temp->data);
    temp = temp->nextPointer;
  }
}
