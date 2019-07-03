//Inserting a node at the beginning of the linked list.
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};


Node* Insert(Node* head, int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}
/* Passing the variable by reference
void Insert(Node** head, int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = *head;
    *head = temp;
}
*/

void Print(Node* head){
    cout << "Heres the list: \n";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node* head = NULL;
    cout << "How many numbers do you want? ";
    int n, i, x; cin >> n;
    for(i = 0; i < n; ++i){
        cout << "Enter the numbers: "; cin >> x;
        //or you coud just pass the variable by reference
        //Insert(&head, x);
        head = Insert(head, x);
    }
    Print(head);
    return 0;
}


