#include "mixednumber.h"

mixedNumber::mixedNumber()
{
}

mixedNumber::~mixedNumber()
{
    nukeEveryone();
}

mixedNumber::mixedNumber(int w, int n, int d)
{
    setValues(w,n,d);
}


mixedNumber::mixedNumber(const double &other)
{
    setValue(other);
}

mixedNumber::mixedNumber(const mixedNumber &other)
{
    copy(other);
}

mixedNumber& mixedNumber::operator=(const mixedNumber &other)
{
    if(this != &other)
       copy(other);
    return *this;
}


mixedNumber& mixedNumber::operator=(const fraction &other)
{
//    num = other.getNum();
//    denom = other.getDenom();
    setValue(other.getNum(), other.getDenom());
    return *this;
}


mixedNumber& mixedNumber::operator=(const int &other)
{
    fraction temp(other);
    *this = temp;
    return *this;
}

mixedNumber& mixedNumber::operator=(const double &other)
{
    fraction temp(other);
    *this = temp;
    return *this;
}

//Accessors

void mixedNumber::getValues(int &w, int &n, int &d)
{
//    w = num/denom;
//    n = num%denom;
//    d = denom;
    w = getNum()/getDenom();
    n = getNum()%getDenom();
    d = getDenom();
}

int mixedNumber::getWhole() const {
    return num/denom;
}

fraction mixedNumber::getFrac() const{
    fraction temp = *this - fraction(getWhole());
    return temp;
}

//Mutators

void mixedNumber::setValues(int w, int n, int d)
{
    fraction::setValue(w*d + n, d);
}

void mixedNumber::copy(const mixedNumber &other)
{
    setValue(other.getNum(), other.getDenom());
}

void mixedNumber::nukeEveryone()
{
//    num = 0;
//    denom = 1;
    setValue(0, 1);
}

