#include <iostream>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear < MAX_SIZE - 1) {
        if (front == -1)
            front = 0;
        queue[++rear] = data;
        std::cout << "Enqueued successfully\n";
    } else {
        std::cout << "Queue is full. Cannot enqueue.\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        std::cout << "Queue is empty. Cannot dequeue.\n";
    } else {
        std::cout << "Dequeued successfully\n";
        front++;
    }
}

void print() {
    if (front == -1 || front > rear) {
        std::cout << "Queue is empty\n";
    } else {
        std::cout << "Queue: ";
        for (int i = front; i <= rear; ++i) {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    enqueue(12);
    enqueue(34);
    enqueue(56);
    print();
    dequeue();
    print();
    return 0;
}
