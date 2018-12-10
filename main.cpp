#include <iostream>

using namespace std;


#include "calculate.h"
#include "interface.h"

int main()
{
    try {
        Parser par;
        Calculate cal;

        start();

        while(1) {
            par.setUserIn(prompt());
            cal.setRpn(par.getRpn());
            showLine('.');
            cout<<" RPN:    "<<par.showRpn()<<endl;
            showLine('.');
            cout<<" RESULT: "<<cal.getResult()<<endl;
            showLine('=');
        }
    }
    catch (const regex_error e) {
        cout<<e.what()<<endl;
        cout<<"error code: "<<e.code()<<endl;
        cout<<"error description: ";
        switch( e.code() )
        {
        case regex_constants::error_collate: cout << "The expression contained an invalid collating element name."; break;
        case regex_constants::error_ctype: cout << "The expression contained an invalid character class name."; break;
        case regex_constants::error_escape: cout << "The expression contained an invalid escaped character, or a trailing escape."; break;
        case regex_constants::error_backref: cout << "The expression contained an invalid back reference."; break;
        case regex_constants::error_brack: cout << "The expression contained mismatched brackets ([ and ])."; break;
        case regex_constants::error_paren: cout << "The expression contained mismatched parentheses (( and ))."; break;
        case regex_constants::error_brace: cout << "The expression contained mismatched braces ({ and })."; break;
        case regex_constants::error_badbrace: cout << "The expression contained an invalid range between braces ({ and })."; break;
        case regex_constants::error_range: cout << "The expression contained an invalid character range."; break;
        case regex_constants::error_space: cout << "There was insufficient memory to convert the expression into a finite state machine."; break;
        case regex_constants::error_badrepeat: cout << "The expression contained a repeat specifier (one of *?+{) that was not preceded by a valid regular expression."; break;
        case regex_constants::error_complexity: cout << "The complexity of an attempted match against a regular expression exceeded a pre-set level."; break;
        case regex_constants::error_stack: cout << "There was insufficient memory to determine whether the regular expression could match the specified character sequence."; break;
        }
        cout<<endl;
    }
    catch (E &e) {
        cout << "error: " << e.what() <<endl;
    }
}
