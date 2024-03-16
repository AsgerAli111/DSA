#include <iostream>
#include <cstdlib>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Declare global pointers to track the front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to enqueue (add) an element to the queue
void enqueue(int data) {
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        std::cerr << "Memory allocation failed. Unable to enqueue.\n";
        return;
    }
    // Initialize the new node with the given data
    temp->data = data;
    temp->next = NULL;
    
    // If the queue is empty, both front and rear point to the new node
    if (rear == NULL) {
        front = rear = temp;
    } else {
        // Otherwise, update the next pointer of the current rear node
        // to point to the new node, and then update the rear pointer
        rear->next = temp;
        rear = temp;
    }
    std::cout << "Enqueued successfully: " << data << std::endl;
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    // If the queue is empty (front is NULL), print an error message
    if (front == NULL) {
        std::cerr << "Queue is empty. Unable to dequeue.\n";
        return;
    }
    // Store the front node in a temporary variable
    struct Node *temp = front;
    // Move the front pointer to the next node
    front = front->next;
    // If front becomes NULL, the queue is now empty, so update rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }
    // Free the memory allocated for the dequeued node
    free(temp);
    std::cout << "Dequeued successfully.\n";
}

// Function to print the elements of the queue
void print() {
    // Start from the front of the queue
    struct Node *temp = front;
    // Traverse the queue and print each element
    std::cout << "Queue: ";
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Enqueue some elements to the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    // Print the queue
    print();
    // Dequeue an element from the queue
    dequeue();
    // Print the updated queue
    print();
    // Dequeue remaining elements
    dequeue();
    dequeue();
    // Try to dequeue from an empty queue
    dequeue();
    return 0;
}
