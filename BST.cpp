#include <iostream>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode() {
    data = 0;
    left = NULL;
    right = NULL;
  }
};
class BST {
public:
  TreeNode* root;

  BST()
  {
    root = NULL;
  }

  //1. add notes to the bst
  void addNode(int value)
  {
    TreeNode* temp = new TreeNode;
    temp->data = value;
    if (root == NULL) {
      root = temp;
    }
    else {
      TreeNode* slow, * fast;
      slow = fast = root;

      while (fast != NULL)
      {
        if (fast->data == value)
        {
          cout << "Duplicate value, we will not add X" << endl;
          return;
        }
        if (value < fast->data)
        {
          slow = fast;
          fast = fast->left;
        }
        else {
          slow = fast;
          fast = fast->right;
        }

      }
      if (value < slow->data) {
        slow->left = temp;
      }
      else {
        slow->right = temp;
      }
      cout << "Just added: " << value << " to the BST!" << endl;
    }
  }
  //2. search for a value
  void search(int key, TreeNode* start)
  {
    if (start == NULL) {
      cout << "Could not find : " << key << endl;
      return;
    }
    else {
      if (key == start->data)
      {
        cout << "Found it!" << endl;
        return;
      }
      else if (key < start->data)
        search(key, start->left);
      else
        search(key, start->right);
    }
  }
  //3. delete a value from the BST
  void remove(int key, TreeNode* start) {
    if (start == NULL) {
      cout << "Empty tree, nothing to delete " << endl;
      return;
    }
    TreeNode* slow, * fast;
    slow = fast = start;

    while (fast != NULL && fast->data != key)
    {
      if (key < fast->data)
      {
        slow = fast;
        fast = fast->left;
      }
      else {
        slow = fast;
        fast = fast->right;
      }
    }

    if (fast == NULL) {
      cout << "Value not found, can not delete" << endl;
      return;
    }

    //if the value exists:

    if (fast->left == NULL && fast->right == NULL) {
      //case 1 Delete
      if (slow->left == fast) {

        slow->left = NULL;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
      else {
        slow->right = NULL;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
    }
    else if (fast->left != NULL && fast->right == NULL) {
      //case 2 delete
      if (slow->left == fast) {
        slow->left = fast->left;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
      else {
        slow->right = fast->left;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
    }
    else if (fast->left == NULL && fast->right != NULL) {
      //also case 2 delete
      if (slow->left == fast) {
        slow->left = fast->right;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
      else {
        slow->right = fast->left;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
    }
    else {
      //case 3 delete
      int minVal = minValueRightSubTree(fast->right);
      fast->data = minVal;
      remove(minVal, fast->right);
    }

  }
  //finding lowest number on right side of tree
  int minValueRightSubTree(TreeNode* start)
  {
    if (start == NULL)
    {
      return -1;
    }
    else {
      TreeNode* temp = start;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      return temp->data;
    }
  }
  //4. function(s) to display the BST
//4.1 Preorder
  void preorder(TreeNode* start)
  {
    if (start == NULL)
    {
      return;
    }
    else {
      //ROOT
      cout << start->data << endl;
      //LEFT
      preorder(start->left);
      //RIGHT
      preorder(start->right);
    }
  }
  void postOrder(TreeNode* start)
  {
    if (start == NULL)
      return;

    else {
      //LEFT
      postOrder(start->left);
      //RIGHT
      postOrder(start->right);
      //ROOt
      cout << start->data << endl;
    }
  }

  void inOrder(TreeNode* start)
  {
    if (start == NULL)
      return;
    else {
      //LEFT
      inOrder(start->left);
      //ROOT
      cout << start->data << endl;
      //RIGHT
      inOrder(start->right);

    }
  }
};

int main()
{
  BST myTree;
  int choice, value;
  myTree.addNode(30);
  myTree.addNode(15);
  myTree.addNode(60);
  myTree.addNode(7);
  myTree.addNode(22);
  myTree.addNode(45);
  myTree.addNode(75);
  myTree.addNode(17);
  myTree.addNode(27);

  while (1) {
    cout << "Press 1 to add a value " << endl;
    cout << "Press 2 for pre-order " << endl;
    cout << "Press 3 for post-order" << endl;
    cout << "Press 4 for in-order" << endl;
    cout << "Press 5 to search" << endl;
    cout << "Press 6 to delete " << endl;
    cin >> choice;

    switch (choice) {
    case 1: cout << "What value? " << endl;
      cin >> value;
      myTree.addNode(value);
      break;

    case 2: cout << "==========" << endl;
      myTree.preorder(myTree.root);
      cout << "==========" << endl;
      break;

    case 3: cout << "=========" << endl;
      myTree.postOrder(myTree.root);
      cout << "==========" << endl;
      break;

    case 4: cout << "=========" << endl;
      myTree.inOrder(myTree.root);
      cout << "==========" << endl;
      break;

    case 5: cout << "What value?" << endl;
      cin >> value;
      myTree.search(value, myTree.root);
      break;

    case 6: cout << "Delete what value?" << endl;
      cin >> value;
      myTree.remove(value, myTree.root);
      break;


    default: exit(1);
    }
  }
}