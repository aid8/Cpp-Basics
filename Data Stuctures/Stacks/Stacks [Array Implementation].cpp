//Stack - Array Implementation
#include <iostream>
using namespace std;
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE-1){
        cout << "Stack is full! \n";
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        cout << "Stack is Empty: \n";
        return;
    }
    top--;
}

bool IsEmpty(){
    bool t;
    top == -1 ? t = true : t = false;
    return t;
}

void Print(){
    int temp = top;
    while(temp != -1){
        cout << A[temp] << " ";
        temp--;
    }
    cout << endl;
}

int main(){
    Push(1);
    Push(2);
    Push(3);
    Print();
    Pop();
    Push(5);
    Push(6);
    Pop();
    Print();
    return 0;
}
