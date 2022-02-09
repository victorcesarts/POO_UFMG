#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
    private:
        int Password;
        double Balance;
   
        struct StatementInfos{
            string NameInfo;
            int NAccount;
            string Operation;
            double BalanceAtTime;
            double value;
            double BalanceAfterOP;
        };
        int numberStatement = 0;
        vector<StatementInfos> s;

    public:
       BankAccount(int& password, int& numberaccount, string& titularname);
        virtual ~BankAccount() = 0;

        int NumberAccount;
        string TitularName;
        
        void changePassword(int);
        bool verify(int id);
        virtual void withdraw(double value) = 0;
        virtual void deposit(double value) = 0;
        

        //Some getters and setters
        int GetNumberAccount() const;
        int GetNumberStatement() const;
        string GetTitularName() const;
        double GetBalance() const;
        

        void SetBalance(int id, double value);
        void SetStatement(int id,  double Bat, double value);
        void PrintingStatement();
        virtual void PrintSpecialInfos() = 0;
};
#endif