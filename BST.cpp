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
///BST of such treenodes
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
    //if tree is empy, make the first value the "Root"
    if (root == NULL) {
      root = temp;
    }
    else {
      TreeNode* slow, * fast;
      slow = fast = root; //start at the top

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
      //This is great! fast has now fallen off the tree
      //we will use "slow" (new parent to be) to add a new value
      if (value < slow->data) {
        slow->left = temp;
      }
      else {
        slow->right = temp;
      }
      cout << "Just added: " << value << " to the BST!" << endl;
    }
  }
  //2. search for a value (primary objective)
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
    //Let's try to find the value (key) and see to delete it
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

    //right outside this loop, we get to see if we have fallen off (not found)
    //or if we have found the value
    if (fast == NULL) {
      cout << "Value not found, can not delete" << endl;
      return;
    }

    //if we are here now, that means the value exists
    //fast points to this node, and slow points to the parent of the node
    //Now we classify what kind of a case we are dealing with

    if (fast->left == NULL && fast->right == NULL) {
      //case 1 Delete
      cout << "Case 1 delete" << endl;
      if (slow->left == fast) {
        //is fast to the left of slow
        slow->left = NULL;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
      else {
        slow->right == NULL;
        cout << "About to delete : " << fast->data << endl;
        delete fast;
      }
    }
    else if (fast->left != NULL && fast->right == NULL) {
      //case 2 delete
      cout << "Case 2 delete " << endl;
      if (slow->left == fast) {
        //take the lone child to the left of fast and give its address to slow->left
        //because fast is to the left of slow
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
      cout << "Case 2 delete " << endl;
      //FINISH
    }
    else {
      //case 3 delete
      cout << "Case 3 delete" << endl;
      int minVal = minValueRightSubTree(fast->right);
      //swap the current node with min value
      fast->data = minVal;
      //we need to delete that minVal from the right subtree right away
      remove(minVal, fast->right);
    }

  }

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
      //base case or anchor value
      return;
    }
    else {
      //recursive step
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