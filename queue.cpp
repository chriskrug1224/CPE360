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

class Queue {
public:
  Chunk* head;

  Queue() { head = NULL; }

  void enqueue(int x) {
    Chunk* temp;
    temp = new Chunk;
    temp->value = x;
    if (head == NULL) {
      head = temp;
    }
    else {
      Chunk* another;
      another = head;
      while (another->next != NULL) {
        another = another->next;
      }

      another->next = temp;
      temp->next = NULL;
      cout << "Just added: " << x << endl;
    }
  }

  void dequeue() {
    if (head == NULL) {
      cout << "Empty qeueue" << endl;
    }
    else {
      Chunk* temp;
      temp = head;
      head = head->next;
      cout << "About to delete: " << temp->value << endl;
      delete temp;
    }
  }

  void displayContents() {
    Chunk* temp;
    temp = head;

    while (temp != NULL) {
      cout << temp->value << "---->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  Queue Q;
  int choice, x;
  while (1) {
    cout << "Press 1 to enqueue" << endl;
    cout << "Press 2 to dequeue" << endl;
    cout << "Press 3 to display" << endl;
    cout << "Press anything else to quit!" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Add what?" << endl;
      cin >> x;
      Q.enqueue(x);
      break;

    case 2:
      Q.dequeue();
      break;

    case 3:
      Q.displayContents();
      break;

    default:
      cout << "Goodbye!" << endl;
      exit(1);
    }
  }
}