#include<iostream>
#include<sstream>
using namespace std;

string int_to_string(int n)
{
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return s;
}

int main()
{
    //Example
    int n;
    string display = "";
    cout << "Enter Number: ";
    cin >> n;
    display += "Your number is " + int_to_string(n) + " lol\n";
    cout << display;
    return 0;
}
