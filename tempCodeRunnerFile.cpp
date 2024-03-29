#include <iostream>

struct Node *head; // globally accessible

struct Node
{
    struct Node *next;
    int data;
};

void insert(int v, int p)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = v;
    temp1->next = NULL;

    if (p == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node *temp2 = head;

    for (int i = 0; i < p - 2; i++)
    {
        if (temp2 == NULL)
        {
            std::cout << "Invalid position\n";
            return;
        }
        temp2 = temp2->next;
    }

    if (temp2 == NULL)
    {
        std::cout << "Invalid position\n";
        return;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main()
{
    head = NULL;
    insert(1, 5);
    insert(2, 4);
    insert(3, 3);
    insert(4, 2);
    insert(11, 1);

    print();

    return 0;
}
