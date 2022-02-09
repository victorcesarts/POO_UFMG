#include "SavingAccount.hpp"

SavingAccount::SavingAccount(int& password, int& numberaccount, string& titularname, double& yield) : YieldRate(yield), BankAccount(password, numberaccount, titularname){}
SavingAccount::~SavingAccount(){}

void SavingAccount::withdraw(double value) {
     bool test = this -> verify(0);
    if (test == true){
        double Bat = this -> GetBalance();
        if (value <= Bat){
            cout << "The value is available to withdraw. Please wait while the money is being counted..." << endl;
            this -> SetBalance(0, value);
            cout << " ----- Money is available, you can take it." << endl << "-----Operations will be finished -----" << endl;
            this -> SetStatement(0, Bat, value);
            return;
        } else {
            throw invalid_argument("----- Insufficient balance. Operation will be finished. -----");
        }
    } else {
        throw invalid_argument ("----- Something went wrong. Operation will be finished. -----");
    }
}

void SavingAccount::deposit(double value) {
    bool test = this -> verify(1);
    if (test == true){
        double Bat = this -> GetBalance();
        this -> SetBalance(1, value);
        cout << "Deposit was sucessfull. Money will be available in your account within 1 working day." << endl;
        cout << " ----- Operation will be finished -----" << endl;
        this -> SetStatement(1, Bat, value);
    } else {
        throw invalid_argument("----- Something went wrong. Operation will be finished. -----");
    }
}

inline double SavingAccount::GetYieldRate() const{ return YieldRate; }

void SavingAccount::PrintSpecialInfos(){
    this -> PrintingStatement();
    cout << "Yield Rate for this account: " << GetYieldRate() << endl;
    cout << "======== END STATEMENT ========" << endl;
} 
