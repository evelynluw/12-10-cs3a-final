#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class E : public exception {
public:
    E(const char* s) throw() : msg(s) {}
    const char * what() const throw() {return msg;}
private:
    const char * msg;
    E() {}
};

const E e_divide_by_zero("number is divided by zero");
const E e_argm_error("arguments are incorrect");

//parser errors
const E e_error_input("Your input is incorrect. Please double check.");

#endif // MYEXCEPTION_H
