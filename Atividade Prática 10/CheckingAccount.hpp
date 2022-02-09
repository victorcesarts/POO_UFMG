#ifndef CHECKACCOUNT_H
#define CHECKACCOUNT_H
#include "BankAccount.hpp"

class CheckingAccount : public BankAccount{

    private:
        int NumberTransactions = 0;

    public:
        CheckingAccount(int& password, int& numberaccount, string& titularname);
        ~CheckingAccount();

        void withdraw(double value);
        void deposit(double value);
        void SetNumberTransactions();
        int GetNumberTransactions() const;
        void PrintSpecialInfos();
};



#endif
