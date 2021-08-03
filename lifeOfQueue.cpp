//Christopher James Kruger
//I pledge my honor that I have abided by the Stevens honor system
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int storeClock = 0;
int inLineTotal = 0;
int minWaitTime = 0;
int TimeOfMinWait = 0;
int maxWaitTime = 0;
int TimeOfMaxWait = 0;
int minServiceTime = 0;
int TimeOfMinService = 0;
int maxServiceTime = 0;
int TimeOfMaxService = 0;
int minQueueLength = 0;
int TimeOfMinQueue = 0;
int maxQueueLength = 0;
int TimeOfMaxQueue = 0;

class Customer {
public:
  int inTime;
  int outTime;
  int waitTime;
  int orderTime;
  Customer* next;

  Customer() {
    inTime = storeClock;
    outTime = 0;
    waitTime = 0;
    orderTime = rand() % 6 + 1;
    next = NULL;
  }
};

class Queue {
public:
  Customer* head;


  void enqueue() {
    Customer* temp = new Customer();
    //Min Max Wait Time
    if (storeClock == 0) {
      return;
    }
    if (customerWaitTime(head) < minWaitTime) {
      minWaitTime = customerWaitTime(head);
      TimeOfMinWait = storeClock;
    }
    if (customerWaitTime(head) > maxWaitTime) {
      maxWaitTime = customerWaitTime(head);
      TimeOfMaxWait = storeClock;
    }

    //Min Max Service Time
    if (minServiceTime == 0) {
      minServiceTime = customerWaitTime(head) + temp->orderTime;
      TimeOfMinService = storeClock;
    }
    else {
      if ((customerWaitTime(head) + temp->orderTime) <= minServiceTime) {
        minServiceTime = customerWaitTime(head) + temp->orderTime;
        TimeOfMinService = storeClock;
      }
      if ((customerWaitTime(head) + temp->orderTime) > maxServiceTime) {
        maxServiceTime = customerWaitTime(head) + temp->orderTime;
        TimeOfMaxService = storeClock;
      }
    }

    //Min Max Line Length
    if (numberOfCustomersInLine(head) < minQueueLength) {
      minQueueLength = numberOfCustomersInLine(head);
      TimeOfMinQueue = storeClock;
    }
    if (numberOfCustomersInLine(head) > maxQueueLength) {
      maxQueueLength = numberOfCustomersInLine(head);
      TimeOfMaxQueue = storeClock;
    }


    //code for enqueue.. add this customer to the Queue
    cout << "Just added a new customer to the line : " << temp->inTime << " and order : " << temp->orderTime << endl;

    if (head == NULL)
    {
      head = temp;
    }
    else {
      Customer* another;
      another = head;
      while (another->next != NULL) {
        another = another->next;
      }
      another->next = temp;
      temp->next = NULL;
    }
  }
  void dequeue() {
    if (head == NULL)
    {
      cout << "Empty queue, nothing to deqeueue" << endl;
    }
    else {
      Customer* temp;
      temp = head;
      head = head->next;
    }
  }

  /*
  int queueSize() {
     return 1;

  }
*/

  int numberOfCustomersInLine(Customer* head) {
    if (head == NULL) {
      return 0;
    }
    else {
      int counter = numberOfCustomersInLine(head->next);
      return (counter + 1);
    }

  }

  int customerWaitTime(Customer* head) {
    int total = 0;
    if (head == NULL) {
      return 0;
    }
    else {
      int total = customerWaitTime(head->next);
      return total += head->orderTime;
    }
  }

};

int main() {
  srand(time(NULL));
  Queue myStore;
  int customerCount = 0;
  int queue_length = 0;
  int wait_time_sum = 0;
  int service_time_sum = 0;
  int min_wait_time = 9999;
  int max_wait_time = -1;
  int min_service_time = 9999;
  int max_service_time = -1;
  int random_number;
  while (storeClock < 1020)
  {
    storeClock++;
    inLineTotal += myStore.numberOfCustomersInLine(myStore.head);
    //1. Is a new customer to arrive this minute?
    if (storeClock <= 120) //8 - 10 am
    {
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 30) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);

      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }
    else if (storeClock > 120 && storeClock <= 210) //10 - 1130 am
    {
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 10) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);
      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }
    else if (storeClock > 210 && storeClock <= 330) //1130 - 130 pm
    {
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 40) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);
      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }
    else if (storeClock > 330 && storeClock <= 570)//130 - 530 pm
    {
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 10) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);
      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }
    else if (storeClock > 570 && storeClock <= 720) //530 - 8 pm
    {
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 25) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);
      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }
    else if (storeClock > 720 && storeClock <= 900) //8 - 11 pm
    {
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 20) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);
      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }
    else { // 11 - 1am
      //check if a new customer is to arrive
      random_number = rand() % 100 + 1;
      if (random_number <= 10) {
        //this is success: meaning, we have a new customer arrive
        cout << "At time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        wait_time_sum += myStore.customerWaitTime(myStore.head);
        myStore.enqueue();
        service_time_sum += myStore.customerWaitTime(myStore.head);
      }
      else {
        cout << "At time: " << storeClock << " no new customer arrived " << endl;
      }
    }

    //2. Is a new customer done with an order this minute
    if (myStore.head != NULL) {
      if (myStore.head->orderTime == 0)
      {
        cout << "Customer departing" << endl;
        myStore.dequeue();
      }
      else {
        myStore.head->orderTime--;
      }
    }

  }
  //3. Let's check on our vital stats real quick: wait time, service time, queue length
  cout << "The average queue length : " << inLineTotal / 1020 << endl;
  cout << "Average customer wait time : " << wait_time_sum / customerCount << endl;
  cout << "Average customer service time : " << service_time_sum / customerCount << endl;

  cout << "Min wait time : " << minWaitTime << " at time: " << TimeOfMinWait << endl;
  cout << "Max Wait time : " << maxWaitTime << " at time : " << TimeOfMaxWait << endl;
  cout << "Min service time : " << minServiceTime << " at time : " << TimeOfMinService << endl;
  cout << "Max service time : " << maxServiceTime << " at time : " << TimeOfMaxService << endl;
  cout << "Min queue length : " << minQueueLength << " at time : " << TimeOfMinQueue << endl;
  cout << "Max queue length : " << maxQueueLength << " at time : " << TimeOfMaxQueue << endl;


  //this is where we print the final states 
  //1. average customer wait time
  //2. average customer service time
  //3. average queue length
  //4. best and worst case scenario and when it happened: wait time, service time, qeueu length


}