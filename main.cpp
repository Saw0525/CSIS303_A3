#include <iostream>
#include "function.h" // Ensure this file exists in the same directory or provide the correct path
using namespace std;

int main() {
    myQueue<int> q;// create a queue of integers
    int valEntered;
    //part (a) instantiate the queue with integers and push 10 values into the queue
    cout << "Enter 10 values in the Queue " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> valEntered;
        q.push(valEntered);
    }

    //part (b) display all the elements in the queue using just the queue functions
    cout << "Queue elements after pushing 10 values: ";
    q.display();
    cout << "Queue size after pushing 10 values: " << q.size() << endl;
    cout << endl;


    // Ask the user to enter the number of elements to be popped
    int numToPop;
    cout << "Enter the number of elements(number of index) to pop from the queue: ";
    cin >> numToPop;
    for (int i = 0; i < numToPop; ++i) {
        q.pop();
    }
    q.pop();//pop elements from the queue  
    cout << "Queue elements after poping elements: ";//call the display function
    q.display();
    cout << "Queue size after poping elements: " << q.size() << endl;//call the size function
    cout << endl;


    cout << "Front element of the queue: " << q.front() << endl;//call the front function

    //part (c) move the front element to the rear of the queue
    q.move_to_rear();
    cout << "Queue elements after moving front to rear: " ;
    q.display();


    int exitCode; //my .exe file was closing immediately after the program execution. So, I added this code to keep the console window open.
    cout << " " << endl;
    cout << "Press 0 to Exit from the program: ";
    cin >> exitCode;
    while (exitCode != 0) {
        cout << "Invalid input. Please press 0 to close the program: ";
        cin >> exitCode;
    }

    return 0;
    
}