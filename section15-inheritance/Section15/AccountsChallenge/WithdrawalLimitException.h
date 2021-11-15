#ifndef __WITHDRAWALLIMITEXCEPTION__H__
#define __WITHDRAWALLIMITEXCEPTION__H__
#include <iostream>
class WithdrawalLimitException : public std::exception {
public:
    WithdrawalLimitException() = default;
    ~WithdrawalLimitException() = default;
    virtual const char* what() const noexcept override {
        return "Exceeded withdrawal limit";
    }
};
#endif  //!__WITHDRAWALLIMITEXCEPTION__H__