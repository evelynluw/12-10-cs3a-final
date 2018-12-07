#ifndef MIXEDNUMBER_H
#define MIXEDNUMBER_H
#include <iostream>
#include <fstream>
#include "fraction.h"
#include <sstream>

class mixedNumber : public fraction
{
    public:
        mixedNumber();
        ~mixedNumber();
        mixedNumber(int w, int n, int d);
        mixedNumber(const mixedNumber &other);
        mixedNumber(const double &other);
        mixedNumber(const fraction &other) : fraction(other) {}
        mixedNumber& operator=(const mixedNumber &other);
        mixedNumber& operator=(const fraction &other);
        mixedNumber& operator=(const int &other);
        mixedNumber& operator=(const double &other);

        void getValues(int &w, int &n, int &d);
        int getWhole() const;
        fraction getFrac() const;
        void setValues(int w, int n, int d);

        friend
        std::ostream& operator<<( std::ostream &out, const mixedNumber &m);

        friend
        std::istream& operator>>( std::istream &in, mixedNumber &m); //TESTED

    private:

        void copy(const mixedNumber &other);
        void nukeEveryone();
};

#endif // MIXEDNUMBER_H
