#include "calculate.h"

void Calculate::test() {
    setRpn("3 4 2 * 1 5 - 2 3 ^ ^ / +");
    cout<<result<<endl;
}

Calculate::Calculate()
{

}

Calculate::Calculate(string _rpn) {
    setRpn(_rpn);
}

Calculate::~Calculate() {
    rpn = "";
}

void Calculate::process() {
    result = 0;
    vector<string> tkStk = split(rpn);;
    vector<string>::reverse_iterator rit = tkStk.rbegin();
    stack<char> opStk;
    stack<mixedNumber> oprStk;
    tokenType t;
    string token;
    mixedNumber opr, opr1;
    char op;
    bool pendingOpr = false;
    for(;rit!=tkStk.rend(); ++rit) {
        t = checkType((token = *rit));
        if (t == OPERATOR) {
            opStk.push(token[0]);
            pendingOpr = false;
        }
        else if (t == OPERAND) {
            opr = token;
            if(rit==(--tkStk.rend())) {
                if(oprStk.empty()){
                    oprStk.push(opr);
                    opr = 0;
                }
                if(opStk.empty())
                    opStk.push('+');
                pendingOpr = true;
            }
            if(pendingOpr) {
                while(!oprStk.empty() & !opStk.empty()) {
                    opr1 = oprStk.top();
                    oprStk.pop();
                    op = opStk.top();
                    opStk.pop();
                    switch (op) {
                    case '+': opr = opr + opr1; break;
                    case '-': opr = opr - opr1; break;
                    case '*': opr = opr * opr1; break;
                    case '/': opr = opr / opr1; break;
                    default: break;
                    }
                }
            }
            oprStk.push(opr);
            pendingOpr = true;
        }
    }
    if(!oprStk.empty())
        result = oprStk.top();
}

void Calculate::setRpn(string _rpn) {
    rpn = _rpn;
    process();
}

string Calculate::getRpn() const {
    return rpn;
}

mixedNumber Calculate::getResult() const {
    return result;
}

//Private
string Calculate::subMixedSpace(string str) {
    //REPEATED IN PARSER CLASS
    /* subsitute the space in mixed Numbers.
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

vector<string> Calculate::split(string noMixedSp) {
    /* split a rpn string with no mixed spaces into tokens.
     * e.g. noMixedSp = "3 4_5/6 7 + * -"
     * output in a vector<string>, which contains e.g.
     * [ 3,4 5/6,7,+,*,- ]
     */
    stringstream ss;
    string part;
    size_t pos = 0;
    ss<<noMixedSp;
    vector<string> strv;
    while(!ss.eof()) {
        ss>>part;
        if((pos = part.find('_')) != string::npos)
            part[pos]=' '; //here replace '_' back to ' '
        strv.push_back(part);
    }
    strv.pop_back();
    return strv;
}

Calculate::tokenType Calculate::checkType(string token) {
    //check if operator or operand
    if(token.size()==1)
        if(string("+-*/").find(token[0]) != string::npos)
            return OPERATOR;
    return OPERAND;
}
