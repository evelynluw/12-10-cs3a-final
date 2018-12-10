#include "calculate.h"

Calculate::Calculate()
{

}

void Calculate::test() {
    vector<string> strv;
    strv = split(subMixedSpace("3 4 5/6 7 + * -"));
    for(vector<string>::iterator it=strv.begin();
        it!=strv.end();
        ++it)
        cout<<*it<<",";
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
    ss<<subMixedSpace(noMixedSp);
    vector<string> strv;
    while(!ss.eof()) {
        ss>>part;
        if((pos = part.find('_')) != string::npos)
            part[pos]=' '; //here replace '_' back to ' '
        strv.push_back(part);
    }
    ss.clear();
    return strv;
}

Calculate::tokenType Calculate::checkType(string token) {
    //check if operator or operand
    if(string("+-*/").find(token[0]) != string::npos)
        return OPERATOR;
    return OPERAND;
}
