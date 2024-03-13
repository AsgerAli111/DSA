#include <iostream>
#include <cstdlib>
struct Node *top;
struct Node
{
    struct Node *next;
    int data;
};

void push(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(Node));
    if (top == NULL)
    {
        temp->data = data;
        temp->next = NULL;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
    std::cout << "\n pushed successfully \n";
}
void pop()
{
    if (top == NULL)
        return;
    struct Node *temp = top->next;
    top = temp;
    //free(temp);
    std::cout << "\n  popped successfully \n";
}

void print()
{
    struct Node *temp = top;
    while (temp != NULL)
    {

        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    push(34);
    push(35);
    push(365);
    push(25);
    pop();
    push(35);

    print();

    return 0;
}