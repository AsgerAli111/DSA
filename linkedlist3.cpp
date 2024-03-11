#include <iostream>
#include <cstdlib>

struct Node *head;

struct Node
{

    int data;
    struct Node *next;
};

void insert(int data)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(Node));
    temp1->data = data;
    temp1->next = head;
    head = temp1;
}

void print()
{

    struct Node *temp1 = head;

    while (temp1 != NULL)
    {
        std::cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    std::cout << std::endl;
}
void deleteat(int pos)
{

    struct Node *temp1 = head;
    struct Node *temp2 = head;

    if (pos == 1)
    {
        head = head->next;
        std::cout << "\ndeleted at index 1 successfully \n";
        return;
    }

    int i = 0;
    for (i; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    // free(temp2);

    std::cout << "\ndeleted successfully\n";
    /* in this code let i want to delete element at fifth position so first it will iterate till
     just before the fifth element then it will copy the address of the fifth element
     from 4th node link part then it will assign it to temp2 which acts here as temporary node 5
      and then it updates the link part of node 4 by putting the link address of node 6 which was copied
       from temporarily made node named temp2.
       */
}

void reverse()
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *pre = NULL;

    while (current != NULL)
    {

        /*
        1. copy the next node address
        2. assign pre add to current node
        3. make pre node as current
        4.make current node as next
        */
        next = current->next;
        current->next = pre;

        pre = current;
        current = next;
    }
    std::cout << "\nReversed List\n";
    head = pre;
}

void recursivePrint(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    recursivePrint(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{

    insert(5);
    insert(1);
    insert(11);
    insert(6);
    insert(3);
    insert(4);
    print();
    // reverse();

    recursivePrint(head);
    print();
    std::cout << "\n end of main \n";

    return 0;
}