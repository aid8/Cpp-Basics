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

Node* ReverseLinkedList(Node* head){
    if(head->next == NULL){
        return head;
    }
    Node* temp = ReverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main(){
    Node* head = NULL;
    cout << "How many numbers do you want? ";
    int n, i, x, p; cin >> n;
    for(i = 0; i < n; ++i){
        cin >> x;
        Insert(&head, x);
    }
    Print(head);
    head = ReverseLinkedList(head);
    //head = reverse(head);
    Print(head);
    return 0;
}
