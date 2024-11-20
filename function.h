#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdexcept>

template <typename item__Type>
class myQueue {
private:
    // Node structure to store data
    struct Node {
        item__Type data;
        Node* next;

        // Constructor for Node
        Node(const item__Type& value, Node* nextNode = nullptr)
            : data(value), next(nextNode) {}
    };

    Node* front_of_queue = nullptr; // Pointer to the front of the queue
    Node* back_of_queue = nullptr;  // Pointer to the back of the queue
    int num_items = 0;              // Number of items in the queue

public:
    // Default constructor
    myQueue() = default;

    // Destructor to free memory
    ~myQueue() {
        while (!empty()) {
            pop();
        }
    }

    // Add an element to the back of the queue
    void push(const item__Type& value) {
        Node* newNode = new Node(value); // Create a new node
        if (back_of_queue == nullptr) { // If the queue is empty
            front_of_queue = back_of_queue = newNode;
        } else {
            back_of_queue->next = newNode; // Link the new node to the end
            back_of_queue = newNode;      // Update the back pointer
        }
        num_items++;
    }

    // Remove an element from the front of the queue
    void pop() {
        if (empty()) {
            std::cerr << "Error: Cannot pop from an empty queue." << std::endl;
            return;
        }
        Node* old_front = front_of_queue;
        front_of_queue = front_of_queue->next;

        // If the queue becomes empty, reset the back pointer
        if (front_of_queue == nullptr) {
            back_of_queue = nullptr;
        }

        delete old_front;
        num_items--;
    }

    // Get the element at the front of the queue
    item__Type front() const {
        if (empty()) {
            throw std::runtime_error("Error: Cannot access front of an empty queue.");
        }
        return front_of_queue->data;
    }

    // Get the number of elements in the queue
    int size() const {
        return num_items;
    }

    // Check if the queue is empty
    bool empty() const {
        return num_items == 0;
    }

    // Move the front element to the rear of the queue
    void move_to_rear() {
        if (empty() || front_of_queue == back_of_queue) {
            std::cout << "Queue is empty or has only one element. No move required." << std::endl;
            return;
        }
        item__Type frontElement = front(); // Get the front element
        pop();                             // Remove the front element
        push(frontElement);                // Add it to the rear
    }

    // Display all elements in the queue
    void display() const {
        if (empty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* current = front_of_queue;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif
