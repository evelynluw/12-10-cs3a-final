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
    void start();
    void test();

private:
    Parser parser;
    string subMixedSpace(string str); //subsitute the space in mixed Numbers
    vector<string> split(string noMixedSp); //split a rpn string with no mixed spaces into tokens
};

#endif // CALCULATE_H
