#include <iostream>
using namespace std;

int main()
{
	string s1, s2;
	cout << "Type your 1st word: "; cin >> s1;
	cout << "Type the word to search in 1st word: " cin >> s2;
	size_t f = s1.find(s2);
	f != string::npos ? cout << "Word found in 1st word\n" : cout << "Word not found in 1st word\n";
	return 0;
}