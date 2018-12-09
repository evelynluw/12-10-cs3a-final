#ifndef PARSER_H
#define PARSER_H
#include "mixednumber.h"
#include <string>
#include <stack>
#include <regex>

using namespace std;

class Parser
{
public:
    void test();

    Parser();//init all variables
    Parser(string _userIn);//init with userInput & convert
    ~Parser();
    void setUserIn(string _userIn);
    void process(); //convert userIn to rpn string using shunting yard algorithm
    string getUserIn() const;
    string getRpn() const;

private:
    string userIn; //user input, e.g. "3 1/2 + 5.6 * 7/9 / 10"
    string rpn; //output rpn, e.g. "3 1/2 5.6 7/9 * 10 / +"
    enum tokenType { //for the shunting yard algorithm
        NUMBER,
        FUNCTION,
        OPERATOR,
        LEFT_BRACKET,
        RIGHT_BRACKET,
        NOTHING
    };
    tokenType getToken(string &str, string &token); //extract a token from the beginning of str
};

#endif // PARSER_H
