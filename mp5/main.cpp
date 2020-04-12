#include "BinaryTreeType.h"

int main()
{
  BST<int> gradesTree;

  gradesTree.insert(20);
  gradesTree.insert(10);
  gradesTree.insert(5);
  gradesTree.insert(7);
  gradesTree.insert(30);
  gradesTree.insert(40);
  gradesTree.insert(35);

  cout << " -- inOrderTraversal -- \n";
  gradesTree.inOrderTraversal();
  cout << "\n -- preOrderTraversal -- \n";
  gradesTree.preOrderTraversal();
  cout << "\n -- postOrderTraversal -- \n";
  gradesTree.postOrderTraversal();
  cout << "\n -- inOrderTraversal after deleting 40 -- \n";
  gradesTree.deleteNode(40);
  gradesTree.inOrderTraversal();
  cout << "\n -- destructor destroys the tree -- \n";
}
