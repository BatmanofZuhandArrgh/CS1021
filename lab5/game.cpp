/*Game Rules:
You pick a number from 1 to 6, and call this number your point.  You then roll a die 3 times.  If there is any match with your point, then you win $1; otherwise you pay the house $1.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie(int x){
    int y;
    y = rand() % 6 + 1;
    return y;
}

bool playOneGame(int x){//check if 2 variables are equal
    for (int i = 0; i < 3 ; ++i){
        int y = rollDie(x);
        cout << "Roll #" << i+1 << " is " << y <<endl;
        if (x == y){
            return true;
        }
    }
        return false;
}

double calcStat(double x, double y){
    return (x/y * 100);
}

int increasingBalance(int balance, int wager){
    return (balance + wager);
}

int decreasingBalance(int balance, int wager){
    return (balance - wager);
}

int main(){
    srand(time(NULL));
    int balance = 100;
    int wager;
    cout << "Account balance: " << balance << endl;
    cout << "Enter wager (0 to exit): ";
    cin >> wager;
    int timesWin = 0;
    int timesTotal = 0;
    
    //Check if wager is less than 100
    while (wager > 100 || wager < 1) {
        cout << "Error: You must wager between $1 and $100 (type 0 to exit): ";
        cin >> wager;
    }
    cout << endl;

   //Simulation 1:
    cout << "Enter your point value (1 - 6): ";
    int x;
    cin >> x;
    //check if input is valid
    while (x < 1 || x > 6){
        cout << "Error: Enter your point value, must be between 1 and 6:";
        cin >> x;
    }
    
    cout << rollDie(x) << endl;
    if (x == rollDie(x)){
        cout << "** You Win! **"<<endl;
        balance = increasingBalance(balance, wager);
        cout << "Your final account balance is $"<< balance <<endl;
        timesWin = 1;
    }
    else{
        cout << "** You Lose! **"<<endl;
        balance = decreasingBalance(balance, wager);
        cout << "Your final account balance is $"<< balance <<endl;
    }
    timesTotal = 1;
    
    
    //Real game
    int a; //For switch case later on
    int x1;
        

        while(wager != 0){
            timesTotal = timesTotal + 1;
        cout << "Enter your point value (1 - 6): ";
        cin >> x1;
        //check if input is valid
        while (x1 < 1  || x1 > 6) {
            cout << "Error: Enter your point value, must be between 1 and 6:";
            cin >> x1;
        }
        if (playOneGame(x1)){
            cout << "** You Win! **"<< endl;
            balance = increasingBalance(balance, wager);
            timesWin = timesWin + 1;
        }
        else {
            cout << "** You Lose **" << endl;
            balance = decreasingBalance(balance, wager);
        }
    
        cout << "Account balance: $" << balance << endl;//check if balance is still more than 0
            if(balance <= 0){
                a = 1;
            }
            else{
                a = 2;
            }
        switch (a){
        case 2:
            cout << "Enter wager (0 to exit): ";
            cin >> wager;
            cout << endl;
            break;
        case 1:
            cout << "Game over, you are out of money!"<<endl;
            wager = 0;
            break;
            }
            
        }
    
    cout << "Your final account balance is $"<< balance<< endl;
    //static_cast<double>(timesTotal);
    //static_cast<double>(timesWin);
    double b = calcStat(timesWin, static_cast<double>(timesTotal));
    cout << "You won " << timesWin << " time out of " << timesTotal << " for a winning percentage of " << b << "%" << endl;
    return 0;
}
