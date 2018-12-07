#ifndef PARSER_H
#define PARSER_H
#include "mixednumber.h"
#include <string>
#include <stack>

using namespace std;

class Parser
{
public:
    Parser();//init all variables
    Parser(string _userIn);//init with userInput & convert
    ~Parser();
    void setUserIn(string _userIn);
    void process(); //convert userIn to rpn string
    string getUserIn() const;
    string getRpn() const;
private:
    stack<mixedNumber> mixedStk; //mixed number stack
    stack<char> opStk; //operator stack
    string userIn; //user input, e.g. "3 1/2 + 5.6 * 7/9 / 10"
    string rpn; //output rpn, e.g. "3 1/2 5.6 7/9 * 10 / +"
    void splitInput(); //split userIn into mixedStk and opStk
    void generateRpn(); //when mixedStk and opStk are done, generate Rpn string
};

#endif // PARSER_H
