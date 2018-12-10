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
    string showRpn() const; //show rpn with no underscores

private:
    string userIn; //user input, e.g. "3 1/2 + 5.6 * 7/9 / 10"
    string rpn; //output rpn with underscores, e.g. "3_1/2 5.6 7/9 * 10 / +"
    enum tokenType { //for the shunting yard algorithm
        NUMBER,
        OPERATOR,
        LEFT_BRACKET,
        RIGHT_BRACKET,
        NOTHING
    };
    tokenType getToken(string &str, string &token); //extract a token from the beginning of str
    bool highPriority(char op1, char op2); //returns true if op1 has greater or equal precedence
    string subMixedSpace(string str); //subsitute the space in mixed Numbers
    string delSpace(string str); //delete all spaces except for mixed number space

};

#endif // PARSER_H
