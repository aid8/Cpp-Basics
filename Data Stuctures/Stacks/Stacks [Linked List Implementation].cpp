//Stacks - Linked List Implementation

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *top = NULL; //HEAD

bool IsEmpty(){
    return top == NULL;
}

void Push(int x){
    Node* temp = new Node();
    temp->data = x;
    if(top == NULL){
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}

void Pop(){
    if(IsEmpty()){
        cout << "Stack is Empty!\n";
        return;
    }
    Node* temp = top->next;
    delete top;
    top = temp;
}

void Print(){
    Node* temp = top;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Push(1);
    Push(2);
    Push(3);
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Push(5);
    if(IsEmpty()) cout << "Empty\n";
    else cout << "Not Empty\n";
    Print();
    return 0;
}
