#include "interface.h"

string prompt() {
    cout<<" INPUT:  ";
    if(cin.peek()=='\n')
        exit(0);
    string line;
    getline(cin, line);
    return line;
}

void start() {
    showLine('=');
    showCentered("RPN CALCULATOR");
    showLine('=');
    showCentered("This terminal-based calculator allows you to input an algebraic expression ");
    showCentered("that consists of integers(e.g. 35), decimal numbers(e.g. 7.9), fractions(e.g 12/31),");
    showCentered("or mixed numbers(e.g. 3 4/5) and present the result in a proper form. ");
    showCentered("'+' '-' '*' '/' are allowed operators. ");
    showCentered("You do not have to wrap operators with spaces. ");
    showCentered("Exit with return. ");
    showLine('=');
}

void showLine(char seg) {
    for(int i = 0; i < len; ++i)
        cout<<seg;
    cout<<endl;
}

void showCentered(string centered) {
    int spacing = (len - centered.size())/2;
    for(int i = 0; i < spacing; ++i)
        cout<<' ';
    cout<<centered;
    for(int i = 0; i < spacing; ++i)
        cout<<' ';
    cout<<endl;
}
