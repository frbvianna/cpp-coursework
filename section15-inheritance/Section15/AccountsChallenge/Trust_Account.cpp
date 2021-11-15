#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate, int withdrawals)
    : Savings_Account{name, balance, int_rate}, withdrawals{withdrawals} {
}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000.0) {
        amount += def_bonus;
    }
    return Savings_Account::deposit(amount);
}

void Trust_Account::withdraw(double amount) {
    if (withdrawals >= 3) {
        throw WithdrawalLimitException{};
    }
    if (amount > 0.2*balance) {
        throw InsufficientFundsException{};
    }
    increment_withdrawals();
    Account::withdraw(amount);
}

void Trust_Account::increment_withdrawals() {
    withdrawals++;
}

void Trust_Account::print(std::ostream &os) const {
    os << "[Trust_Account: " 
    << name << ": " 
    << balance << ", " 
    << int_rate << "%, "
    << withdrawals << "]";
}