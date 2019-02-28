#include <iostream>

using namespace std;

string determineSubstance(double bp){
    string Z;
    if (bp<=100*1.05 && bp>=100*0.95){
        Z = "Water";
    }
    else if (bp<=357*1.05 && bp>=357*0.95){
        Z = "Mercury";
    }
    else if (bp<=1187*1.05 && bp>=1187*0.95){
        Z = "Copper";
    }
    else if (bp<=2193*1.05 && bp>=2193*0.95){
        Z = "Silver";
    }
    else if (bp<=2660*1.05 && bp>=2660*0.95){
        Z = "Gold";
    }
    else {
        Z = "Unknown";
    }
    
    return Z;
}

int main() {  //NO NEED TO CHANGE THIS
    double bp = 100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Water" << endl;
    bp = 350;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Mecury" << endl;
    bp = 2100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Silver" << endl;
    bp = 1100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Unknown" << endl;
    bp = 1150;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Copper" << endl;
    bp = 2600;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Gold" << endl;
    bp = 11000;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Known" << endl;
    return 0;
}
