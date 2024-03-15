#include <iostream>
#include <cstdlib>
#include<stack>
struct Node *head;

struct Node
{

    struct Node *next;
    int data;
};

void reverse()
{
    std::stack<struct Node *> s;
    if (head == NULL)
        return;
    struct Node *temp = head;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = NULL;
}

void insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = head;
    head = temp;
    std::cout << "\n inserted \n";
}

void print()
{

    struct Node *temp = head;

    while (temp != NULL)
    {

        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{

    head = NULL;
    insert(5);
    insert(10);
    print();
    return 0;
}