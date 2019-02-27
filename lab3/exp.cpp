// Program: exp.cpp
// Description: Test and develop a version of the exp() function - main() has test
// code to check and see if this version of exp() function works properly.

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// double factorial(int N) - returns the factorial variable N
// Please add the code necessary to calculate the factorial of the number represented by N

double factorial(int N) {
    double return_val = 1;
    if (N==0){
        return_val = 1;
    }
    else {
        int i;
        for (i=N; i>0; i=i-1){
            return_val = return_val * i;
        }
    }
    return return_val;
}
// A clone of the system exp() function.
// Please do not use the system exp() function in the creation of your function.
double E_to_X(double X){
    double ex = 1;
    int i=1;
    double a;
    
    while (i<21){
        a = pow(X,i)/factorial(i);
        if (a>=0.0001){
        //cout<<"initializing values for i="<<i<<endl;
        //cout<<pow(X,i)<< endl;
        //cout<<factorial(i)<< endl;
            ex = ex + a;//pow(X,i)/factorial(i);
        i = i+1;
        }
    }
    return ex; // Replace return statement with something more proper
}

// You can change main() in anyway you want
int main() {
    
    cout << fixed << "E_to_X(0) is " << E_to_X(0) << " should be 1" << endl;
    cout << fixed << "E_to_X(1) is " << E_to_X(1) << " should be 2.718" << endl;
    cout << fixed << "E_to_X(2) is " << E_to_X(2) << " should be 7.38" << endl;
    cout << fixed << "E_to_X(5) is " << E_to_X(5) << " should be 120" << endl;
    cout << fixed << "E_to_X(10) is " << E_to_X(10) << " should be 22026" << endl;
    
    return 0;
}
