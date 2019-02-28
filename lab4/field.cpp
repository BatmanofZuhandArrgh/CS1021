
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int Q = 1;
const int k = 9;

double Efield(double r, double a=1);
double Efield(double r, double a){
    double E;
    if(r<a){
        E = k*Q*r/(a*a*a);
    }
    else{
        E = k*Q/(r*r);
    }
    return E;
}

int main(){
    double r;
    cin>>r;
    double a;
    cin>>a;
    
    cout<< "Efield: " <<setprecision(6)<< Efield(r,a)<<endl;
    return 0;
}
