// Program: factorial.cpp
// Description: Test and develop the factorial function - main() has test
// code to check and see if the factorial() function works properly.

#include <iostream>
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

int main() {
    
    cout << fixed << "factorial(0) is " << factorial(0) << " should be 1" << endl;
    cout << fixed << "factorial(1) is " << factorial(1) << " should be 1" << endl;
    cout << fixed << "factorial(2) is " << factorial(2) << " should be 2" << endl;
    cout << fixed << "factorial(5) is " << factorial(5) << " should be 120" << endl;
    cout << fixed << "factorial(10) is " << factorial(10) << " should be 3628800" << endl;
    // this may not work
    cout << fixed << "factorial(20) is " << factorial(20) << " should be 1307674368000" << endl;
    
    
    return 0;
}
