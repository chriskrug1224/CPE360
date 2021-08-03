#include <iostream>
using namespace std;


class Chunk {
public:
  int info;
  Chunk* next;

  Chunk() {
    info = 0;
    next = NULL;
  }
};

class LinkedList {
public:
  Chunk* head;
  int count;

  LinkedList() {
    head = NULL;
    count = 0;
  }

  void insertAtHead(int value)
  {
    Chunk* temp;
    temp = new Chunk;
    temp->info = value;
    temp->next = head;
    head = temp;
    count++;
    cout << "Just added " << value << " at position 1" << endl;
  }

  void insertAtPos(int value, int pos) {

    if (pos > 0 && pos <= count + 1) {
      Chunk* temp;
      temp = new Chunk;
      temp->info = value;
      if (pos == 1) {

        temp->next = head;
        head = temp;
        count++;
        cout << "Just added " << value << " at position 1" << endl;
      }
      else {
        Chunk* helper = head;
        for (int i = 1; i < pos - 1; i++) {
          cout << helper->info << " ";
          helper = helper->next;
        }

        temp->next = helper->next;
        helper->next = temp;
        count++;
        cout << "Just added " << value << " at position " << pos << endl;
      }
    }
    else {
      cout << "Invalid position, can't add this item" << endl;
    }
  }
  void removeFromPosition(int position)
  {
    if (head == NULL)
    {
      cout << "Empty list, nothing to remove :) " << endl;
      return;
    }
    if (position > 0 && position <= count)
    {
      if (position == 1)
      {
        Chunk* temp;
        temp = head;
        head = head->next;
        cout << "About to delete " << temp->info << endl;
        delete temp;
        count--;

      }
      else {
        Chunk* chase, * follow;
        chase = follow = head;
        for (int i = 1; i < position; i++)
        {
          follow = chase;
          chase = chase->next;
        }
        follow->next = chase->next;
        count--;
      }

    }
  }
  void displayContents() {
    Chunk* temp;
    temp = head;
    while (temp != NULL) {
      cout << temp->info << " ----> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
int main() {
  LinkedList LL;
  int value, position, choice;

  while (1) {
    cout << "Press 1 to add at the top of the list " << endl;
    cout << "Press 2 to add at a desired position " << endl;
    cout << "Press 3 to delete " << endl;
    cout << "Press 4 to display " << endl;
    cout << "Press anything else to quit " << endl;
    cin >> choice;
    switch (choice) {

    case 1:
      cout << "What would you like to add to the top of the head of the list? " << endl;
      cin >> value;
      LL.insertAtHead(value);
      break;
    case 2:
      cout << "Add what? " << endl;
      cin >> value;
      cout << "What position? " << endl;
      cin >> position;
      LL.insertAtPos(value, position);
      break;

    case 3:
      cout << "Remove from what position? " << endl;
      cin >> position;
      LL.removeFromPosition(position);
      break;

    case 4:
      LL.displayContents();
      break;

    default:
      cout << "Goodbye :) " << endl;
      exit(1);
    }
  }
}