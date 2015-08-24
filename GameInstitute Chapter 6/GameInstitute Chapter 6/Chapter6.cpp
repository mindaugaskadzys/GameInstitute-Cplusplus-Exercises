#include <iostream>
#include <string>

using namespace std;

void main() {
	//Ex 6.10.1 - String reverse
	/*cout << "Enter a string: ";
	string text;
	getline(cin, text);
	string reversed;
	int stringLength = text.length();
	reversed.resize(stringLength);
	for (int i = 0; i < stringLength; i++) {
		reversed[i] = text[stringLength - 1 - i];
	}
	cout << "Reversed string: " << reversed << endl*/;

	//Ex 6.10.2 - ToUpper
	/*string s;
	cout << "Enter a string: ";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] > 96 && s[i] < 123)
			s[i] -= 32;
	}
	cout << "Upper-case string: " << s << endl;*/

	//Ex 6.10.3 - ToLower
	/*string s;
	cout << "Enter a string: ";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
	}
	cout << "Upper-case string: " << s << endl;*/

	//Ex 6.10.4 - Palindrome
	/*string s;
	cout << "Enter a string: ";
	getline(cin, s);
	//get middle point of string
	int midPoint = s.size() / 2;
	if (s.size() % 2 == 1)
		midPoint++;

	bool isPalindrome = true;
	for (int i = 0; i < midPoint; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}

	cout << s << (isPalindrome ? " is a palindrome." : " is not a palindrome.") << endl;*/

}