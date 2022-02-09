#include "BankAccount.hpp"

BankAccount::BankAccount(int& password, int& numberaccount, string& titularname) : Password(password), Balance(0.0), NumberAccount(numberaccount), TitularName(titularname){}

BankAccount::~BankAccount(){}

void BankAccount::changePassword(int newPassword){
   bool test = verify(2);

   if (test == false) {
       cout << "Something went wrong with the change. Please, try again later" << endl;
       return;
   } else {
       this-> Password = newPassword;
       cout << "Password changed sucessfully" << endl;
   }
}

bool BankAccount::verify(int id){
    int numberAccountIN;
    int passwordIN; 
    bool result;
    string verifyName;
    switch (id){
        case 0: 
            cout << "-------------- WITHDRAW --------------" << endl;
            
            cout << "Pleasse, confirm account's titular name: " << endl;
            cout << GetTitularName() << endl;
            cout << "Is that right? Type Y for 'yes' or N for 'no'" << endl;
            cin >> verifyName;
            if (verifyName == "N"){
                result = false;
            } else {
                if (verifyName == "Y"){
                    int typedPassWord;
                    cout << "Please, type your current password: " << endl;
                    cin >> typedPassWord;
                    if (typedPassWord == Password){
                        result = true;
                    } else result = false;
                } else result = false;
            }
        break;
            
        case 1:
            cout << "-------------- DEPOSIT --------------" << endl;
            cout << "Pleasse, confirm account's titular name: " << endl;
            cout << GetTitularName() << endl;
            cout << "Is that right? Type Y for 'yes' or N for 'no'" << endl;
            cin >> verifyName;
            if (verifyName == "N"){
                result = false;
            } else {
                   if (verifyName == "Y"){
                    result = true;
                } else result = false;
            }
        break;

        case 2:
            cout << "-------------- CHANGING PASSWORD --------------" << endl;
            cout << "Pleasse, confirm account's titular name: " << endl;
            cout << GetTitularName() << endl;
            cout << "Is that right? Type Y for 'yes' or N for 'no'" << endl;
            cin >> verifyName;
            if (verifyName == "N"){
                result = false;
            } else {
                if (verifyName == "Y"){
                    int typedPassWord;
                    cout << "Please, type your current password: " << endl;
                    cin >> typedPassWord;
                    if (typedPassWord == Password){
                        result = true;
                    } else result = false;
                } else result = false;
            }
        break;
        }
    return result;
}

inline int BankAccount::GetNumberAccount() const { return NumberAccount; }
inline string BankAccount::GetTitularName() const { return TitularName; }
inline double BankAccount::GetBalance() const { return Balance; }
inline int BankAccount::GetNumberStatement() const { return numberStatement; }

void BankAccount::SetBalance(int id, double value) { 
    if (id == 0){
        Balance = Balance - value;
    } else if (id == 1){
        Balance = Balance + value;
    }
}

void BankAccount::SetStatement(int id, double Bat, double value){   
    if (id == 0){
        StatementInfos S1;
        S1.NameInfo = this -> GetTitularName();
        S1.NAccount = this -> GetNumberAccount();
        S1.Operation = "Withdraw";
        S1.BalanceAtTime = Bat;
        S1.value = value;
        S1.BalanceAfterOP = this -> GetBalance();
        s.insert(s.begin() + numberStatement, S1);
        this -> numberStatement += 1;
    } else if(id == 1){
        StatementInfos S1;
        S1.NameInfo = this -> GetTitularName();
        S1.NAccount = this -> GetNumberAccount();
        S1.Operation = "Deposit";
        S1.BalanceAtTime = Bat;
        S1.value = value;
        S1.BalanceAfterOP = this -> GetBalance();
        s.insert(s.begin() + numberStatement, S1);
        this -> numberStatement += 1;
    }
}

void BankAccount::PrintingStatement() { 
  int nStatement = this -> GetNumberStatement();
    cout << " ------------ Your Statement is: ------------" <<  endl;
    for (int i = 0; i < nStatement; i++){
        cout << "Account Titular's name: " << s[i].NameInfo << endl; 
        cout << "Number account: " << s[i].NAccount << endl;  
        cout << "Type operation: " << s[i].Operation << endl;
        cout << "Balance before operation: " << s[i].BalanceAtTime << endl;
        cout << "Balance after operation: " << s[i].BalanceAfterOP << endl;
        cout << " --------------------------------------------" << endl;      
    }
        cout << "Current balance: " << this -> GetBalance() << endl;
}
