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

void Parser::process() { //convert userIn to rpn string

}

string Parser::getUserIn() const {
    return userIn;
}

string Parser::getRpn() const {
    return rpn;
}


//PRIVATE
//void Parser::initialize() {
//    if(!mixedStk.empty())
//        mixedStk.pop();
//    if(!opStk.empty())
//        opStk.pop();
//}

Parser::tokenType Parser::getToken() {

}

void Parser::generateRpn() { //when mixedStk and opStk are done, generate Rpn string


}
