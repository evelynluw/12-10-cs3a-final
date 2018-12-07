#include "mixednumber.h"

std::ostream& operator<<( std::ostream &out, const mixedNumber &m)
{
    int whole = m.num/m.denom, numerator = m.num % m.denom;
    if(numerator == 0)
        out<<whole;
    else
        if(whole == 0)
            out<<numerator<<"/"<<m.denom;
       else
            out<<whole<<" "<<abs(numerator)<<"/"<<m.denom;
    return out;
}

std::istream& operator>>( std::istream &in, mixedNumber &m)
{ //TESTED
    fraction part1;
    in>>part1;
    if(in.peek()==' ') {
        in>>m;
        m += part1;
    }
    else {
        m = part1;
    }
    return in;
}
