#include "BusinessTraveler.hpp"

int main(){
    BusinessTraveler BT, BT2("Person"), BT3(BT2);
    cout << "BT: " << BT << endl;
    cout << "BT2: " << BT2 << endl;
    cout << "BT3: " << BT3 << endl;

    BT2 = BT;
    cout << "BT2 = BT: " << BT2 << endl;
    BT = BT3;
    cout << "BT = BT3: " << BT << endl;
    cout << "BT3: " << BT3 << endl;
    return 0;
};