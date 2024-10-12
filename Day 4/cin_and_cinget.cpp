#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    char firstChar, secondChar;
    string word;

    // Using cin >> to read a single character
    cout << "Enter the first character (cin >>): ";
    cin >> firstChar; // Reads the first non-whitespace character
    cout << "You entered (cin >>): " << firstChar << endl;

    // Using cin.get() to read the next character
    cout << "Enter the second character (cin.get()): ";
    cin.get(secondChar); // Reads the next character, including newline if present
    cout << "You entered (cin.get()): " << secondChar << endl;

    // Ignoring any remaining newline characters before reading a string
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Using cin >> to read a word
    cout << "Enter a word: ";
    cin >> word; // Reads a word (stops at first whitespace)
    cout << "You entered (word): " << word << endl;

    // Ignoring any remaining newline characters before the next input
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Using cin.get() to read an entire line
    cout << "Enter another line: ";
    string line;
    getline(cin, line); // Reads the entire line, including spaces, until newline
    cout << "You entered (line): " << line << endl;

    return 0;
}
