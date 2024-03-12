#include <iostream>
#include <cstdlib>
#define maxSize 100
int top = -1;

int stack[maxSize];

void push(int data)
{
    if (top == maxSize - 1)
        std::cout << " Stack Overflow\n";
    else
        stack[top + 1] = data;
    top++;
    std::cout << "pushed successfully\n";
}
void pop()
{
    if (top == -1)
        std::cout << "Stack Underflow \n";
    else
        stack[top--];
    std::cout << "\npopped successsfully\n";
}

void print(int topflag)
{

    while (topflag != -1)
    {
        std::cout << stack[topflag] << " ";
        topflag--;
    }
}

int main()
{

    push(34);
    push(45);
    push(78);
    print(top);
    pop();
    print(top);

    return 0;
}
