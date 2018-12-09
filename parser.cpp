#include "parser.h"

//PUBLIC

void Parser::test() {

}


Parser::Parser() {//init all variables
    setUserIn("");
}

Parser::Parser(string _userIn) {//init with userInput & convert
    setUserIn(_userIn);
}

Parser::~Parser() {
    setUserIn("");
}

void Parser::setUserIn(string _userIn) {
    userIn = _userIn;
}

void Parser::process() {
    /* convert userIn to rpn string using shunting yard algorithm
     * from userIn
     * to rpn
     */
}

string Parser::getUserIn() const {
    return userIn;
}

string Parser::getRpn() const {
    return rpn;
}

Parser::tokenType Parser::getToken(string &str, string &token) {
    /* extract a token from the beginning of str
     * e.g. for str = "3 3/4+5-7.3+8 2/3*5/6/3 5/6/3.2"
     * return NUMBER
     * str = "+5-7.3+8 2/3*5/6/3 5/6/3.2"
     * token = "3 3/4"
     * e.g. for str = "+5-7.3+8 2/3*5/6/3 5/6/3.2"
     * return OPERATOR
     * str = "5-7.3+8 2/3*5/6/3 5/6/3.2"
     * token = "+"
     */

}

