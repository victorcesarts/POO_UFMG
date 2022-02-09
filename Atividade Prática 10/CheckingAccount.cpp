#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(int& password, int& numberaccount, string& titularname) : BankAccount(password, numberaccount, titularname){}
CheckingAccount::~CheckingAccount(){}


void CheckingAccount::withdraw(double value){
    bool test = this -> verify(0);
    if (test == true){
        double Bat = this -> GetBalance();
        if (value <= Bat){
            cout << "The value is available to withdraw. Please wait while the money is being counted..." << endl;
            this -> SetBalance(0, value);
            cout << " ----- Money is available, you can take it." << endl << "-----Operations will be finished -----" << endl;
            this -> SetStatement(0, Bat, value);
            this -> SetNumberTransactions();
        } else {
            throw invalid_argument ("----- Insufficient balance. Operation will be finished. -----");
        }
    } else {
        throw invalid_argument ("----- Something went wrong. Operation will be finished. -----");
    }
}

void CheckingAccount::deposit(double value){
    bool test = this -> verify(1);
    if (test == true){
        double Bat = this -> GetBalance();
        this -> SetBalance(1, value);
        cout << "Deposit was sucessfull. Money will be available in your account within 1 working day." << endl;
        cout << "----- Operation will be finished -----" << endl;
        this -> SetStatement(1, Bat, value);
        this -> SetNumberTransactions();
    } else {
        throw invalid_argument("----- Something went wrong. Operation will be finished. -----");
    }
}

void CheckingAccount::SetNumberTransactions(){
    this -> NumberTransactions += 1;
}

inline int CheckingAccount::GetNumberTransactions() const {return NumberTransactions;}

void CheckingAccount::PrintSpecialInfos(){
    this -> PrintingStatement();
    cout << "Number of transactions for this account: " << GetNumberTransactions() << endl;
    cout << "======== END STATEMENT ========" << endl;
} 