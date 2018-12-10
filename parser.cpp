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
    /* TESTED
     * convert userIn to rpn string using shunting yard algorithm
     * from userIn
     * to rpn
     */
    string str, token;
       str = delSpace(userIn);
       tokenType t;
       stack<char> operators;
       //highpriority = true;
       //NUMBER, OPERATOR, LEFT_BRACKET, RIGHT_BRACKET, NOTHING
       while((t = getToken(str, token))!=NOTHING)
       {
   //        switch (t) {
   //        }
   //        cout<<token<<endl;
           if(t==NUMBER)
           {
               rpn+=(token+" ");
           }

           else if(t==OPERATOR)
           {
               //we need a function that compare the operators for priority, I try to start
               //under but not sure how to do correctly
               while(!operators.empty()) {
                   if(highPriority(operators.top(), token[0])
                      & (operators.top()!='(') ) {
                      rpn+=operators.top();
                      rpn+=' ';
                      operators.pop();
                    }
                   break;
               }
               operators.push(token[0]);
           }

           else if(t==LEFT_BRACKET)
           {
               operators.push('(');
           }

           else if(t==RIGHT_BRACKET)
           {
               while(operators.top()!='(')
               {
                   rpn+=operators.top();
                   rpn+=' ';
                   operators.pop();
               }
               operators.pop();
           }
       }

       //not sure about this last part is correct, both the way of format and function
       if(t==NOTHING)
       {
           while(!operators.empty())
           {
               rpn+=operators.top();
               rpn+=' ';
               operators.pop();
           }
       }
   }

   //compare the priority of the operator in top of stack and the one just read in
   /*bool Parser::highpriority(the one that read in, R, char top)
   {
       read in one call r, not sure how to make this into char
       if(top == '*' || top == '/')
       {
           if(R == '*' || R == '/' )
           {
               return false;
           }

           else
           {
               return;
           }
       }

       else if(top == '+' || top == '-')
       {
           if(R == '*' || R == '/' )
           {
               return;
           }

           else
           {
               return false;
           }

       }

   }*/

string Parser::getUserIn() const {
    return userIn;
}

string Parser::getRpn() const {
    return rpn;
}

string Parser::showRpn() const {
    string s = rpn;
    size_t pos;
    while((pos = s.find('_'))!=string::npos)
        s[pos]=' ';
    return s;
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

    regex mixedNumber("^(\\d+\\.\\d+|\\d+\\s\\d+\\/\\d+|\\d+\\/\\d+|\\d+|\\.\\d+)([()*/+-]|$)"),
        //match any mixed number from start of line followed by an operator or bracket or end of string
            op("^[*/+-]"), //any operators
            leftBracket("^\\("),
            rightBracket("^\\)");
    smatch match;

    if(regex_search(str, match, mixedNumber)) {
        token = match.str(1);
        str.erase(0,match.length(1));
        size_t pos;
        while((pos=token.find(' '))!=string::npos)
            token[pos]='_';
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

bool Parser::highPriority(char op1, char op2) {
    //returns true if op1 has greater or equal precedence
    if(op1 == '*' || op1 == '/')
    {
        if(op2 == '*' || op2 == '/' )
            return true;
        return false;
    }

    else if(op1 == '+' || op1 == '-')
    {
        if(op2 == '*' || op2 == '/' )
            return false;
        return true;
    }
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
