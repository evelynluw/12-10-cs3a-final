#include "fraction.h"

//PUBLIC
//CTORS

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n, int d)
{
   setValue(n,d);
}

fraction::fraction(std::string fracString) { //TESTED
    setValue(fracString);
}

fraction::~fraction()
{
    num = denom = 0;
}
/*
 * The copy constructor is fired whenever
 * 1. You pass by value
 * 2. You use a return statement that
 *    does not got back to a reference
 */
fraction::fraction(const fraction &frac)
{
    num = frac.num;
    denom = frac.denom;
}

fraction::fraction(const double &other)
{
//    DecimaltoFrac(other, num, denom);
//    reduce();
    setValue(other);
}

//OPERATOR FUNCTIONS (NOT FRIENDS)

/*
 * The assignment operator needs to be
 * returned by reference so that you can
 * "chain" operators.
 * e.g.
 * x = y = z;
 */
fraction& fraction::operator=(const fraction &frac)
{
    if(this != &frac)
    {
        num = frac.num;
        denom = frac.denom;
    }
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    *this = *this / other;
    return *this;
}

//PUBLIC FUNCTIONS

int fraction::getNum() const //accessor function for numerator
{
    return num;
}

int fraction::getDenom() const//accessor function for denominator
{
    return denom;
}

void fraction::setValue(int n, int d) //mutator function
{
    if(d == 0)
        throw e_divide_by_zero;
    num = n;
    denom = d;
    reduce();
}

void fraction::setValue(double other) //mutator by double
{
    DecimaltoFrac(other, num, denom);
    reduce();
}

void fraction::setValue(std::string fracString) { //TESTED
    std::stringstream ss;
    ss<<fracString;
    ss>>*this;
}

void fraction::display()
{
    std::cout<<" "<<num;
    if(denom != 1)
       std::cout<<"/"<<denom<<" ";
}


void fraction::getInput()
{
    char junk;
    std::cin>>num>>junk>>denom;
    reduce();
}


void fraction::reduce()
{
    bool neg = num < 0 || denom < 0,
         both = num < 0 && denom < 0;
    int divisor = gcd(abs(num), abs(denom));
    num = abs(num) / divisor;
    denom = abs(denom) / divisor;
    if(!both) //Asking is both == false
        if(neg)
            num *= -1;
}

fraction fraction::reduceFraction() {
    fraction temp(num, denom);
    temp.reduce();
    return temp;
}

double fraction::evaluate() const //TESTED
{
     return num*1./denom;
}

double fraction::pow(fraction base, fraction power) { //TESTED
    return std::pow(base.evaluate(), power.evaluate());
}

bool fraction::isExactlyTheSame(fraction other) {
    return (num == other.num && denom == other.denom);
}

//PRIVATE
//PRIVATE UTILITY FUNCTIONS

int fraction::gcd(int p, int q)
{
   return !q ? p : gcd(q, p%q);  //!q is the same as asking q == 0;
}

/*
 *  Remainder Theorem
 *
 *  P = nQ + R;
 *
 * 36 = (1)(24) + 12  Question, is 12 == 0?
 * 24 = (2)(12) + 0   If no, move Q into P, and R into Q and continue
 *                    until R == 0;
 * If R== 0, that means Q is the GCD of the original numbers provided
 *
 */


bool fraction::allDecimalsTheSame(const std::string &fracPart)
{
    if(fracPart.size()<3)
        return false;
    bool yes = true;
    for(unsigned int i = 1; yes && i < fracPart.size(); ++i)
        yes = (fracPart[0] == fracPart[i]);
    return yes;
}

int fraction::makeDenom(int digits, bool same)
{
    std::string result("1");
    for(int i = 0; i < digits; ++i)
        result += "0";
    return std::stoi(result) - (int)same * 1;
    //stoi: convert string to integer
}

void fraction::DecimaltoFrac(const double &other, int &_num, int &_denom) {
    /*
        std::string wholePart, fractionPart;
        std::stringstream ss;
        ss<<other;
        getline(ss,wholePart,'.');
        getline(ss,fractionPart);
        int numDigits = fractionPart.size();
        denom = makeDenom(numDigits, allDecimalsTheSame(fractionPart));
        num = denom * abs(std::stoi(wholePart)) + abs(std::stoi(fractionPart));
        num *= std::stoi(wholePart)/abs(std::stoi(wholePart));
    */

    //new method. maybe not as efficient. maybe don't use stringstream?
    /*
    std::string str;
    std::stringstream ss, part;
    int whole, frac;
    ss<<other;
    getline(ss,str,'.'); //wholePart; treat '.' as a delimination char
    if(!str.empty()) {
        part<<str;
        part>>whole;
    }
    getline(ss, str, '\n'); //fracPart
    part<<str;
    part>>frac;
    int numDigits = str.size();
    _denom = makeDenom(numDigits, allDecimalsTheSame(fractionPart));
    _num = _denom * whole + frac;
    */

    //simple string method
    std::string decimal = std::to_string(other),
            fracPart = decimal.substr(decimal.find('.')+1);
    int digits = fracPart.size();
    _denom = makeDenom(digits, allDecimalsTheSame(fracPart));
    _num = other * _denom;
}

double fraction::makeDouble(int intPart, int deciPart) {
    std::stringstream ssdouble;
    ssdouble<<intPart<<'.'<<deciPart;
    double temp;
    ssdouble>>temp;
    return temp;
}

