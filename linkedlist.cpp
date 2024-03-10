#include<iostream>
#include<cstdlib>

struct Node* head;

struct Node{
    int data;
    struct Node* next;
};

void insert(int d){

    struct Node* temp=(Node*)malloc(sizeof(Node));

    temp->data=d;
    temp->next=head; 
    head=temp;
}

void print(){

    struct Node* temp=head;

    while(temp!=NULL){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

int main(){

    int i,n,d;
    head=NULL;
    std::cout<<" How many elements you wanna insert?: ";
    std::cin>>n;

    for(i=0;i<n;i++){

        std::cin>>d;
        insert(d);
        print();
    }

    return 0;
}
