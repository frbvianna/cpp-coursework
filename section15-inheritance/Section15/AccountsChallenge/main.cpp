// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Vector of accounts
    vector<Account*> accounts;
    Account *acc_1, *acc_2, *acc_3, *acc_4 {nullptr};
    
    // Savings Accounts
    Savings_Account sav_1 {};
    Savings_Account sav_2 {"Superman"};
    Savings_Account sav_3 {"Batman", 2000};
    Savings_Account sav_4 {"Wonderwoman", 5000, 5.0};
    accounts.push_back(&sav_1);
    accounts.push_back(&sav_2);
    accounts.push_back(&sav_3);
    accounts.push_back(&sav_4);

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Checking Accounts
    Checking_Account chk_1 {};
    Checking_Account chk_2 {"Larry"};
    Checking_Account chk_3 {"Moe", 2000};
    Checking_Account chk_4 {"Curly", 5000};
    accounts.at(0) = &chk_1;
    accounts.at(1) = &chk_2;
    accounts.at(2) = &chk_3;
    accounts.at(3) = &chk_4;

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    // Trust Account
    Trust_Account tru_1 {};
    Trust_Account tru_2 {"Superman"};
    Trust_Account tru_3 {"Batman", 2000};
    Trust_Account tru_4 {"Wonderwoman", 5000, 5.0};
    accounts.at(0) = &tru_1;
    accounts.at(1) = &tru_2;
    accounts.at(2) = &tru_3;
    accounts.at(3) = &tru_4;

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    deposit(accounts, 1000);
    withdraw(accounts, 1000);
    deposit(accounts, 1000);
    withdraw(accounts, 1000);

    std::cout << std::endl;
    std::cout << "=== Throwing exceptions ===" << std::endl;
    try {
        // IllegalBalanceException
        //std::unique_ptr<Account> sav_5 {make_unique<Savings_Account>("Flash", -2000, 5.0)};

        // InsufficientFundsException
        std::unique_ptr<Account> sav_6 {make_unique<Savings_Account>("Superhero", 100, 5.0)};
        sav_6->withdraw(200);

    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl; 
    }
   
    return 0;
}

