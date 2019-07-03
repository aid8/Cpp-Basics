#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* next;
};

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

//Reversing a linked list
Node* ReverseLinkedList(Node* head){
    if(head == NULL) return NULL;
    stack<Node*> stk;
    Node* temp = head;
    while(temp != NULL){
        stk.push(temp);
        temp = temp->next;
    }
    temp = stk.top();
    head = temp;
    stk.pop(); //get rid of first since its assigned to head
    while(!stk.empty()){
        temp->next = stk.top();
        stk.pop();
        temp = temp->next; //go to next
    }
    temp->next = NULL; //last one
    return head;
}

int main(){
    Node* head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);
    Print(head);
    head = ReverseLinkedList(head);
    Print(head);
    return 0;
}
