#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct nodeType
{
  T info;
  nodeType<T> *lLink;
  nodeType<T> *rLink;
};

template <typename T>
class BinaryTreeType
{
protected:
  nodeType<T> *root;
public:
  BinaryTreeType();
  ~BinaryTreeType();
  bool isEmpty() const;
  virtual void insert(const T& item) = 0;
  virtual void deleteNode(const T& item) = 0;
  virtual bool search(const T& item) = 0;
  void inOrderTraversal() const;
  void preOrderTraversal() const;
  void postOrderTraversal() const;
  int sizeOf() const;
private:
  void inOrder(nodeType<T> *p) const;
  void preOrder(nodeType<T> *p) const;
  void postOrder(nodeType<T> *p) const;
  void destroy(nodeType<T> * &p);
  int size(nodeType<T> *p) const;
};

template <typename T>
class BST : public BinaryTreeType<T>
{
public:
  void insert(const T& item);
  void deleteNode(const T& item);
  bool search(const T& item) { return false; }
private:
  void deleteFromTree(nodeType<T> * &p);
};

template <typename T>
BinaryTreeType<T>::BinaryTreeType()
{
  root = nullptr;
}

template <typename T>
BinaryTreeType<T>::~BinaryTreeType()
{
  destroy(root);
}

template <typename T>
void BinaryTreeType<T>::destroy(nodeType<T> * &p)
{
  if (p != nullptr)
  {
    destroy(p->lLink);
    destroy(p->rLink);
    cout << "Destroying " << p->info << "\n";
    delete p;
    p = nullptr;
  }
}

template <typename T>
bool BinaryTreeType<T>::isEmpty() const
{
  return (root == nullptr);
}

template <typename T>
void BinaryTreeType<T>::postOrderTraversal() const
{
  postOrder(root);
}

template <typename T>
void BinaryTreeType<T>::postOrder(nodeType<T> *p) const
{
  if (p != nullptr)
  {
    postOrder(p->lLink);
    postOrder(p->rLink);
    cout << p->info << " ";
  }
}

template <typename T>
int BinaryTreeType<T>::sizeOf() const
{
  return size(root);
}

template <typename T>
int BinaryTreeType<T>::size(nodeType<T> *p) const
{
  if (p == nullptr)
    return 0;
  else
    return(size(p->lLink) + 1 + size(p->rLink));
}

template <typename T>
void BinaryTreeType<T>::preOrderTraversal() const
{
  preOrder(root);
}

template <typename T>
void BinaryTreeType<T>::preOrder(nodeType<T> *p) const
{
  if (p != nullptr)
  {
    cout << p->info << " ";
    preOrder(p->lLink);
    preOrder(p->rLink);
  }
}

template <typename T>
void BinaryTreeType<T>::inOrderTraversal() const
{
  inOrder(root);
}

template <typename T>
void BinaryTreeType<T>::inOrder(nodeType<T> *p) const
{
  if (p != nullptr)
  {
    inOrder(p->lLink);
    cout << p->info << " ";
    inOrder(p->rLink);
  }
}

template <typename T>
void BST<T>::deleteNode(const T& item)
{
  nodeType<T> *curr;
  nodeType<T> *trail;
  bool found = false;

  if (this->root == nullptr)
    cout << "Nothing to delete\n";
  else
  {
    curr = this->root;
    trail = curr;
    while (curr != nullptr && !found)
    {
      if (curr->info == item)
        found = true;
      else
      {
        trail = curr;
        if (curr->info > item)
          curr = curr->lLink;
        else
          curr = curr->rLink;
      }
    }

    if (found)
    {
      if (curr == this->root)
        deleteFromTree(this->root);
      else if (trail->info > item)
        deleteFromTree(trail->lLink);
      else
        deleteFromTree(trail->rLink);
    }
    else
      cout << "Item is not found\n";
  }
}

template <typename T>
void BST<T>::deleteFromTree(nodeType<T> * &p)
{
  nodeType<T> *curr;
  nodeType<T> *trail;
  nodeType<T> *temp;

  if (p == nullptr)
    cout << "Nothing to delete\n";
  else if (p->lLink == nullptr && p->rLink == nullptr)
  {
    temp = p;
    p = nullptr;
    delete temp;
  }
  else if (p->lLink == nullptr)
  {
    temp = p;
    p = temp->rLink;
    delete temp;
  }
  else if (p->rLink == nullptr)
  {
    temp = p;
    p = temp->lLink;
    delete temp;
  }
  else
  {
    curr = p->lLink;
    trail = nullptr;
    while (curr->rLink != nullptr)
    {
      trail = curr;
      curr = curr->rLink;
    }
    p->info = curr->info;
    if (trail == nullptr)
      p->lLink = curr->lLink;
    else
      trail->rLink = curr->lLink;
    delete curr;
  }
}

template <typename T>
void BST<T>::insert(const T& item)
{
  nodeType<T> *newNode;
  nodeType<T> *current;
  nodeType<T> *trail;

  newNode = new nodeType<T>;
  newNode->info = item;
  newNode->lLink = nullptr;
  newNode->rLink = nullptr;

  if (this->root == nullptr)
    this->root = newNode;
  else
  {
    current = this->root;
    trail = nullptr;
    while (current != nullptr)
    {
      trail = current;

      if (current->info == item)
      {
        cout << "No duplicates allowed\n";
        return;
      }
      else if (current->info > item)
        current = current->lLink;
      else
        current = current->rLink;
    }
    if (trail->info > item)
      trail->lLink = newNode;
    else
      trail->rLink = newNode;
  }
}
