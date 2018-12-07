#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include "myexception.h"

class fraction
{
    public:
        /*
         * The default constructor makes an "empty"
         * object, and is required ALL the time!
         */
        fraction();
        /*
         * Two item constructor that will pass a numerator
         * and a denominator to the new fraction
         */
        fraction(int n, int d = 1);
        fraction(std::string fracString); //TESTED
        /*
         * How do you destroy a fraction?
         * By the destructor!
         */
        ~fraction();
        /*
         * The copy constructor is fired whenever
         * 1. You pass by value
         * 2. You use a return statement that
         *    does not got back to a reference
         */
        fraction(const fraction &fraction);
        /*
         * The assignment operator needs to be
         * returned by reference so that you can
         * "chain" operators.
         * e.g.
         * x = y = z;
         */
        //Other constructors to "help" make my life easier.
        fraction(const double &other);

        fraction& operator=(const fraction &fraction);
        //Additional assignment operators
        fraction& operator+=(const fraction &fraction);
        fraction& operator-=(const fraction &fraction);
        fraction& operator*=(const fraction &fraction);
        fraction& operator/=(const fraction &fraction);

        /*
         * Friends of a class.
         * Friends are used when you are interacting
         * between two or more other objects; whether
         * it be of the class type or something else.
         *
         * Friends are NOT members of the class, but have
         * access to private member data and functions.
         */
        friend
        std::ostream& operator<<(std::ostream& out, const fraction &frac);

        friend
        std::istream& operator>>(std::istream& out, fraction &frac);

        friend
        fraction operator+(const fraction &x,const fraction &y);

        friend
        fraction operator-(const fraction &x,const fraction &y);

        friend
        fraction operator*(const fraction &x,const fraction &y);

        friend
        fraction operator/(const fraction &x,const fraction &y);

        friend
        fraction operator^(const fraction &x,const fraction &y);

        friend
        bool operator==(const fraction &x,const fraction &y);

        friend
        bool operator>=(const fraction &x,const fraction &y);

        friend
        bool operator<=(const fraction &x,const fraction &y);

        friend
        bool operator!=(const fraction &x,const fraction &y);

        friend
        bool operator%=(const fraction &x,const fraction &y);

        friend
        bool operator<(const fraction &x,const fraction &y);

        friend
        bool operator>(const fraction &x,const fraction &y);

        //public functions

        int getNum() const; //accessor function for numerator
        int getDenom() const;//accessor function for denominator
        void setValue(int n, int d); //mutator function
        void setValue(double other); //mutator by double
        void setValue(std::string fracString); //TESTED
        void display();
        void getInput();
        void reduce();
        fraction reduceFraction();
        double evaluate() const;
        double pow(fraction base, fraction power);
        bool isExactlyTheSame(fraction other);

    protected:
        int num, denom;

    private:
        int gcd(int p, int q);

        bool allDecimalsTheSame(const std::string &fracPart);
        int makeDenom(int digits, bool same);
        void DecimaltoFrac(const double &other, int &_num, int &_denom);
        double makeDouble(int intPart, int deciPart);
};

#endif // FRACTION_H
