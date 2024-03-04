#include <iostream>
struct Node *head; // global in order to acces inside functions
struct Node
{
    struct Node *next; // blueprint for each node
    int data;
};

void insert(int x)
{
    struct Node *temp = (Node *)malloc(sizeof(struct Node)); // creates intance for node

    temp->data = x;
    temp->next = head;
    head = temp;
}

void print()
{

    struct Node *temp = head; // node type pointer pointing to the head
    std::cout << "list is: ";

    while (temp != NULL)
    {

        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    head = NULL; // at beginning setting head as null as empty list
    int n, i;
    std::cout << " how many number you want to insert: ";
    std::cin >> n;
    int v;

    for (i = 0; i < n; i++)
    {

        std::cout << " enter " << i << "th value\n";
        std::cin >> v;
        insert(v);
        print();
    }

    return 0;
}