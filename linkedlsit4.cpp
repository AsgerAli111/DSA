#include<iostream>
#include<cstdlib>
struct Node *head;

struct Node{

    int data;
    Node* next;
    Node* pre;
};

struct Node* createNode(int d){

    struct Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=d;
    temp->next=NULL;
    temp->pre=NULL;
    return  temp;
}

void insertAtHead(int x){

    struct Node* newNode=createNode(x);

    if(head==NULL){
        head=newNode;
        return;
    }

    head->pre=newNode;
    newNode->next=head;
    head=newNode;


}

void printHead(){
    struct Node* temp=head;
    while(head!=NULL){

        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}


int main(){

    head=NULL;

    insertAtHead(11);
        insertAtHead(32);

    insertAtHead(1);

    insertAtHead(5);

    insertAtHead(8);

    printHead();


    return 0;
}