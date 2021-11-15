#ifndef __ILLEGALBALANCEEXCEPTION__H__
#define __ILLEGALBALANCEEXCEPTION__H__
#include <iostream>
class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept override {
        return "Illegal balance";
    }
};
#endif  //!__ILLEGALBALANCEEXCEPTION__H__