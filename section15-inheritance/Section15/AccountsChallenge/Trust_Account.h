#ifndef __TRUST_ACCOUNT__H__
#define __TRUST_ACCOUNT__H__
#include "Savings_Account.h"
#include "WithdrawalLimitException.h"

class Trust_Account: public Savings_Account {
private:
    static constexpr const char *def_name {"Unnamed Savings Account"};
    static constexpr double def_balance {0.0};
    static constexpr double def_int_rate {0.0};
    static constexpr int def_withdrawals {0};
    static constexpr double def_bonus {50.0};
protected:
    int withdrawals;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate, int withdrawals = def_withdrawals);
    virtual bool deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    void increment_withdrawals();
    virtual ~Trust_Account() = default;
};

#endif  //!__TRUST_ACCOUNT__H__