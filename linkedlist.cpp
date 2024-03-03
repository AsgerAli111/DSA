#include <iostream>

struct Node
{
    Node *link;
    int data;
};

    struct Node* insert(int x){

        std::cout<<"insert called \n";
    }
    
    
int main()
{   
    int n,i;
    std::cout<<" how many number you want to insert: ";
    std::cin>>n;
    int v;

    for(i=0;i<n;i++){

        std::cout<<" enter "<<i<<"th value\n";
        std::cin>>v;
        insert(n);
    }

    //print();

    return 0;
}