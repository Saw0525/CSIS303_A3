#include <iostream>
using namespace std;
struct ListNode {//structure to store data
    int data;//
    ListNode* next;//pointer to the next node
    ListNode(int val) : data(val), next(nullptr) {}//constructor to initialize the data and next pointer
};
void insertion_sort(ListNode* &head) {
    if (head == nullptr || head->next == nullptr) {//check if the list is empty or 1 element
        return;
    }
    ListNode* sorted = nullptr;
    ListNode* current = head;
    while (current != nullptr) {//sort the elements in ascending order
        ListNode* next = current->next;
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            ListNode* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}
void display(ListNode* head) {//display the elements in the list
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}