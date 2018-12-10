#include "parser.h"

//PUBLIC

void Parser::test() {
    cout<<delSpace("3 3/4 + 5 - 7.3 + 8 2/3 * 5/6/3 5/6/3.2")<<endl;
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
    string str, token;
    str = delSpace(userIn);
    tokenType t;
    cout<<str<<endl;
    while((t = getToken(str, token))!=NOTHING) {
//        switch (t) {

//        }
        cout<<token<<endl;
    }
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
     *
     * throw error when encounters unexpected input formats
     */
    if(str.size() == 0)
        return NOTHING;

    regex mixedNumber("(^\\d+\\.\\d+|^\\d+\\s\\d+\\/\\d+|^\\d+\\/\\d+|^\\d+|^\\.\\d+)([()*/+-]|$)");
    regex        op("^[*/+-]"), //any operators
            leftBracket("^\\("),
            rightBracket("^\\)");
        //match any mixed number from start of line followed by an operator or bracket
    smatch match;

    if(regex_search(str, match, mixedNumber)) {
        token = match.str(1);
        str.erase(0,match.length(1));
        return NUMBER;
    }

    if(regex_search(str, match, op)) {
        token = match.str();
        str.erase(0,1);
        return OPERATOR;
    }

    if(regex_search(str, match, leftBracket)) {
        token = "(";
        str.erase(0,1);
        return LEFT_BRACKET;
    }

    if(regex_search(str, match, rightBracket)) {
        token = ")";
        str.erase(0,1);
        return RIGHT_BRACKET;
    }

    throw e_error_input; //all other cases should be errors

}

string Parser::subMixedSpace(string str) {
    /* TESTED
     * subsitute the space in mixed Numbers.
     * e.g. str = "3 4 5/6 7 + * -"
     * output = "3 4_5/6 7 + * -"
     * ref: https://www.regular-expressions.info/stdregex.html
     */
    string s = str;
    regex mixedSp("\\d+(\\s)\\d+\\/"); //1st group match the space in mixedNumber
    smatch match;
    while(regex_search(s, match, mixedSp) && match.size() > 1)
        s[match.position(1)] = '_'; //subsitute 1st group match (mixedSpace) to '_'
    return s;
}
string Parser::delSpace(string str) {
    //TESTED
    //delete all spaces except for mixed number space
    size_t pos;
    string s = subMixedSpace(str);
    while((pos = s.find(' '))!=string::npos)
        s.erase(pos,1);
    while((pos = s.find('_'))!=string::npos)
        s[pos]=' ';
    return s;
}
