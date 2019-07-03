//Print a linked list using recursion (FOWARD AND REVERSE)
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
    if(head == NULL) return;
    cout << head->data << " ";
    Print(head->next);
}

void PrintReverse(Node* head){
    if(head == NULL) return;
    PrintReverse(head->next);
    cout << head->data << " ";
}

int main(){
    Node* head = NULL;
    cout << "How many numbers do you want? ";
    int n, i, x, p; cin >> n;
    for(i = 0; i < n; ++i){
        cin >> x;
        Insert(&head, x);
    }
    cout << endl;
    Print(head);
    cout << endl;
    PrintReverse(head);
    return 0;
}
