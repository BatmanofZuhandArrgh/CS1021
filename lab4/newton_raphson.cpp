#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

const double TOLERANCE = .001;

double f(double x){ //f(x)
    double F = pow(x,4) + 2 * pow(x,3) - 31 * pow(x,2) - 32 * x + 60;
    //f(x)=x4+2x3-31x2-32x+60
    return F;
}

double fprime(double x) {// f’(x)
    double F = 4 * pow(x,3) + 6 * pow(x,2) - 62 * x - 32;
    //f'(x)=4x3+6x2-62x-32
    return F;
}

double newtonRoot(double r){
        do{
            r = r - f(r)/fprime(r);
        }while(abs(r - (r-f(r)/fprime(r)))>TOLERANCE);
   // }
    return r;
}


int main(){
    cout.precision(4);
    cout.setf(ios::fixed);
    char choice = 'y';
    double guess;
    char i;
    cin >> guess;
    cout << "Root: " << newtonRoot(guess);
    cout << "Enter Another Guess: y/n?" ;
    cin >> choice ;
    
    while (choice == 'y'){
        cin>> guess;
        cout << "Root: " << newtonRoot(guess);
        cout << "Enter Another Guess: y/n?" ;
        cin >> choice ;
    }
  
    return 0;
}
