#ifndef CALCULATE_H
#define CALCULATE_H
#include "parser.h"
#include <stack>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

class Calculate
{
public:
    Calculate();
    Calculate(string rpn);
    void process();

    void test();

private:
    enum tokenType {
        OPERAND,
        OPERATOR
    };
    string rpn;
    string subMixedSpace(string str); //subsitute the space in mixed Numbers
    vector<string> split(string noMixedSp); //split a rpn string with no mixed spaces into tokens
    tokenType checkType(string token); //check if operator or operand
};

#endif // CALCULATE_H
