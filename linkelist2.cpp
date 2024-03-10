#include <iostream>
#include <cstdlib>
struct Node *head;

struct Node
{

    int data;
    struct Node *next;
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

    Node *temp2 = head;

    for (int i = 0; i < p - 2; i++)
    {

        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print()
{

    Node *temp3 = head;
    while (temp3 != NULL)
    {

        std::cout << temp3->data << " ";
        temp3 = temp3->next;
    }
    std::cout << std::endl;
}

int main()
{

    insert(1, 1);
    insert(2, 2);
    insert(4, 1);
    print();

    return 0;
}