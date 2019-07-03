//Doubly Linked list
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* GetNewNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(Node** head, int x){
    Node* newNode = GetNewNode(x);
    Node* temp = *head;
    if(temp == NULL){
        *head = newNode;
        return;
    }
    temp->prev = newNode;
    *head = temp;
    newNode->next = *head;
    *head = newNode;
}

void InsertAtTail(Node* head, int x){
    Node* newNode = GetNewNode(x);
    if(head == NULL) return;
    //Go to last
    while(head->next != NULL){
        head = head->next;
    }
    newNode->prev = head;
    head->next = newNode;
}

void Print(Node* head){
    cout << "Heres the list: \n";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void ReversePrint(Node* head){
    if(head == NULL) return; //Empty list

    //Go to last
    while(head->next != NULL){
        head = head->next;
    }
    cout << "Heres the reversed list: \n";
    while(head != NULL){
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    InsertAtHead(&head, 2);
    InsertAtHead(&head, 4);
    InsertAtHead(&head, 6);
    InsertAtTail(head, 8);
    Print(head);
    ReversePrint(head);
    return 0;
}
