#include "BinaryTreeType.h"
#include <string>
#include <sstream>

int main()
{
  BST<string> stringTree;

  string entry;
  cout << "Enter a sentence: ";
  getline(cin, entry);

  istringstream iss(entry);

  do {
    string temp;

    iss >> temp;

    stringTree.insert(temp);

  } while (iss);

  cout << "\n -- postOrderTraversal -- \n\n";
  stringTree.postOrderTraversal();
  cout << "\n -- preOrderTraversal -- \n\n";
  stringTree.preOrderTraversal();
  cout << "\n -- inOrderTraversal -- \n\n";
  stringTree.inOrderTraversal();

  int size = stringTree.sizeOf();
  cout << "\n -- Size of tree is: " << size << "\n";

  cout << "\n -- destructor destroys the tree -- \n";
}
