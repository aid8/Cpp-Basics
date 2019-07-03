//Reverse a linked list (Iterative)
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

//Insert at the beginning
void Insert(Node** head, int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void Print(Node* head){
    cout << "Heres the list: \n";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void ReverseLinkedList(Node** head){
    Node* current = *head, *prev = NULL, *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(){
    Node* head = NULL;
    cout << "How many numbers do you want? ";
    int n, i, x, p; cin >> n;
    for(i = 0; i < n; ++i){
        cout << "Enter the numbers: "; cin >> x;
        Insert(&head, x);
    }
    Print(head);
    ReverseLinkedList(&head);
    Print(head);
    return 0;
}
