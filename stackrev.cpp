#include <iostream>
#include <cstdlib>
#define maxSize 100
int top = -1;
char stack[maxSize];

void reverse(char arr[])
{
    int i = 0;
    

    while (arr[i] != '\0')
    {
        stack[top+1 ] = arr[i];
        top++;
        i++;
    }

    i=0;
    while (top >=0)
    {
        arr[i] = stack[top];
        i++;
        top--;
    }

    std::cout << arr;
}

int main()
{
    char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    reverse(arr);
    return 0;
}