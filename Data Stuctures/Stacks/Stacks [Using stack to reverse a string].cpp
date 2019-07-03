#include<iostream>
#include<stack>
using namespace std;

//Reversing a string
string ReverseString(string s){
    string rs = "";
    stack<char> stk;
    //Loop for input
    for(int i = 0; i < s.length(); ++i) stk.push(s[i]);

    //Loop for output
    while(!stk.empty()){
        rs += stk.top();
        stk.pop();
    }
    return rs;
}

int main(){
    string s;
    cout << "Enter a word: "; cin >> s;
    s = ReverseString(s);
    cout << s << endl;
    return 0;
}
