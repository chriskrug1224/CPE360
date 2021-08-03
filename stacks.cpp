#include <iostream>
using namespace std;

class Chunk {
public:
  int value;
  Chunk* next;

  Chunk() {
    value = 0;
    next = NULL;
  }
};
class Stack {
public:
  Chunk* top;

  Stack() {
    top = NULL;
  }
  void push(int x) {
    Chunk* temp = new Chunk;
    temp->value = x;

    if (top == NULL) {
      top = temp;
    }
    else {
      temp->next = top;
      top = temp;
    }
    cout << "Just added: " << x << " to the stack" << endl;
  }
  void pop() {
    if (top == NULL) {
      cout << "Nothing to delete :)" << endl;
    }
    else {
      Chunk* temp = new Chunk;
      temp = top;
      top = top->next;
      cout << "About to delete: " << temp->value << endl;
      delete temp;
    }
  }
  void displayContents() {
    Chunk* temp = top;
    while (temp != NULL) {
      cout << temp->value << "---->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  Stack myStack;
  int choice, x;

  while (1) {
    cout << "Press 1 to add (push) to Stack " << endl;
    cout << "Press 2 to remove (pop) from Stack " << endl;
    cout << "Press 3 to display contents of the Stack " << endl;
    cout << "Press anything else to quit! " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Add what?" << endl;
      cin >> x;
      myStack.push(x);
      break;
    case 2:
      myStack.pop();
      break;

    case 3:
      myStack.displayContents();
      break;

    default:
      cout << "Goodbye!" << endl;
      exit(1);
    }
  }
  return 1;
}