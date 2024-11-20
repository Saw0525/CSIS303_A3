#include <iostream>
#include "question3.h"

int main() {
    //create a list of integers
    ListNode* head = new ListNode(20);
    head->next = new ListNode(65);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(10);
    head->next->next->next->next = new ListNode(25);

    cout << "Original list: ";
    display(head);//display the original list
    insertion_sort(head);//call the insertion sort function
    cout << "Sorted list: ";
    display(head);//display the sorted list

    //my .exe file was closing immediately after the program execution. So, I added this code to keep the console window open.
    int exitCode;
    cout << " " << endl;
    cout << "Press 0 to Exit from the program: ";
    cin >> exitCode;
    while (exitCode != 0) {
        cout << "Invalid input. Please press 0 to close the program: ";
        cin >> exitCode;
    }

    return 0;
}
