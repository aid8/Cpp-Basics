//Inserting a node at the nth position of the linked list.
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

//Get the size of the node
int GetSize(Node* head){
    int c = 0;
    while(head != NULL){
        c++;
        head = head->next;
    }
    return c;
}

//Insert at nth position (0 based)
void InsertAtPos(Node** head, int x, int p){
    if(p < 0 || p > GetSize(*head)) return; //Return if negative is given or is above size

    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(p == 0){
        temp->next = *head;
        *head = temp;
        return;
    }
    Node* temp1 = *head;
    for(int i = 0; i < p-1; ++i){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

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

int main(){
    Node* head = NULL;
    cout << "How many numbers do you want? ";
    int n, i, x, p; cin >> n;
    for(i = 0; i < n; ++i){
        cout << "Enter the numbers: "; cin >> x;
        Insert(&head, x);
    }
    Print(head);
    cout << "Enter a number and position: "; cin >> x >> p;
    InsertAtPos(&head, x, p);
    Print(head);

    return 0;
}


