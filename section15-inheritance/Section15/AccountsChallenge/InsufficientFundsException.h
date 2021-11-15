#ifndef __INSUFFICIENTFUNDSEXCEPTION__H__
#define __INSUFFICIENTFUNDSEXCEPTION__H__
#include <iostream>
class InsufficientFundsException : public std::exception {
public:
    InsufficientFundsException() = default;
    ~InsufficientFundsException() = default;
    virtual const char* what() const noexcept override {
        return "Insufficient funds";
    }
};
#endif  //!__INSUFFICIENTFUNDSEXCEPTION__H__