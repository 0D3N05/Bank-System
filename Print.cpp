#include "includes\PrintUI.h"
// Set console to UTF-8 mode

// Defining method here
void printLine(char ch, int count)
{
    for (int i = 0; i < count; ++i)
        cout << ch;
    cout << endl;
}

void Customization(string word)
{
    if (word == "Welcome to the Bank System! Please enter your bank name (or type 'exit' to quit): ")
    {
        printLine('*', word.length());
        // Got from ASCII art onmline
        cout << " ███████████    █████████   ██████   █████ █████   ████" << endl;
        cout << "░░███░░░░░███  ███░░░░░███ ░░██████ ░░███ ░░███   ███░" << endl;
        cout << " ░███    ░███ ░███    ░███  ░███░███ ░███  ░███  ███  " << endl;
        cout << " ░██████████  ░███████████  ░███░░███░███  ░███████   " << endl;
        cout << " ░███░░░░░███ ░███░░░░░███  ░███ ░░██████  ░███░░███  " << endl;
        cout << " ░███    ░███ ░███    ░███  ░███  ░░█████  ░███ ░░███ " << endl;
        cout << " ███████████  █████   █████ █████  ░░█████ █████ ░░████" << endl;
        cout << "░░░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░    ░░░░░ ░░░░░   ░░░░" << endl;
        printLine('*', word.length());
        cout << word << endl;
        printLine('*', word.length());
    }
    else if (word == "Exiting system. Goodbye!")
    {
        cout << word << endl;
    }
}
