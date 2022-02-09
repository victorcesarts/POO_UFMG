#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "BankAccount.hpp"

class SavingAccount : public BankAccount{
    private: 
        double YieldRate;
    public:
        SavingAccount(int& password, int& numberaccount, string& titularname, double& yield);
        ~SavingAccount();

        void withdraw(double value);
        void deposit(double value);
        double GetYieldRate() const;
        void PrintSpecialInfos();
};      



#endif