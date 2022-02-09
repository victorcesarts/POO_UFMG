#include "BankAccount.hpp"
#include "SavingAccount.hpp"
#include "CheckingAccount.hpp"
#include <list>
#include <algorithm>

int main(){
try{
    vector<BankAccount*> Accounts;
    int numberAC;
    cout << "How many accounts do you want to create?" << endl;
    cin >> numberAC;
    Accounts.reserve(numberAC);
    for (int i = 0; i < numberAC; i++){
        string test1;
        cout << "Type 'CA' if you want to create a Checking Account or type 'SA' if you want to create a Saving Account: ";
        cin >> test1;
        if (test1 == "CA"){
            string NameCA;
            int passwordCA, conta1CA;
            cout << "Please, insert the first name of the account owner: ";
            cin >> NameCA;
            cout << "Please, insert the password for this account, numbers only: ";
            cin >> passwordCA;
            cout << "Please, insert the number of this account, numbers only: ";
            cin >> conta1CA;
            cout << endl;
            Accounts.push_back(new CheckingAccount(passwordCA, conta1CA, NameCA));
        } else if (test1 == "SA"){
            string NameSA;
            int passwordSA, conta1SA;
            double yieldSA;
            cout << "Please, insert the first name of the account owner: ";
            cin >> NameSA;
            cout << "Please, insert the password for this account, numbers only: ";
            cin >> passwordSA;
            cout << "Please, insert the number of this account, numbers only: ";
            cin >> conta1SA;
            cout << "Please, insert the yield rate for this account, numbers only: ";
            cin >> yieldSA;
            cout << endl;
            Accounts.push_back(new SavingAccount(passwordSA, conta1SA, NameSA, yieldSA));
        } else {
            return 1;
        }
    }
    for ( ; ;){
        cout << "Select the operation. Deposit, Withdraw, Change Password or Check Statement: ";
        cin.ignore();
        string Op;
        getline(cin, Op);
        int clienteNUMBER;
        cout << "What's the number of the account do you want to " << Op << "?" << endl;
        cin >> clienteNUMBER;

        for (int i = 0; i < numberAC; i++){
            if (Accounts[i] -> NumberAccount == clienteNUMBER){
                if (Op == "Deposit"){
                    double value;
                    cout << "What is the deposit value?" << endl;
                    cin >> value;
                    Accounts[i] -> deposit(value);
                } else if (Op == "Withdraw"){
                    double value;
                    cout << "What is the withdraw value?" << endl;
                    cin >> value;
                    Accounts[i] -> withdraw(value);
                } else if (Op == "Change Password"){
                    int nPassword;
                    cout << "What is the new password?" << endl;
                    cin >> nPassword;
                    Accounts[i] -> changePassword(nPassword);
                } else if (Op == "Check Statement"){
                    Accounts[i] -> PrintSpecialInfos();
                } else throw invalid_argument("---- NOT A VALID OPERATION ----");
            } 
        } 
        cout << "Do you want to do another operation? Type 'Y' for Yes or 'N' for No: ";
        string t;
        cin >> t;
        if (t == "N"){
            throw invalid_argument("---- OPERATION FINISHED ----");
        }
    }
}
    catch(invalid_argument& e){
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}