#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int randgen(int i){ //Generate random numbers till the upper limit of rand_max
    return (rand() % i);
}

double colderorwarmer(int a, int b, int c, int d){
    double distance2;
    distance2 = (a-c)*(a-c) + (b-d)*(b-d);
    return distance2;
}

int main(){
    char room[15][15];
    srand (time(NULL));
    int placeholder = 1;
    
    cout << "Here's a dark room for ya:" <<endl;
    for (int i = 0; i<15; ++i){
        for (int j = 0; j<15; ++j){
            room[i][j] = '*';
            cout << room[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    //Asign your orginal position, codename A
    int A1 = randgen(15);
    int A2 = randgen(15);
    room[A1][A2] = 'A'; //Player
    
    //Asign Pinto's position
    int P1 = randgen(15);
    int P2 = randgen(15);
    
    if(P1!=A1 && P2!=A2){
    int P1 = randgen(15);
    int P2 = randgen(15);
    }
    room[P1][P2] = '*'; //Pinto
    
    //Asign Roadster's position
    int R1 = randgen(15);
    int R2 = randgen(15);
    
    while((R1==A1 && R2==A2) || (R1==P1 && R2==P2)){
        int R1 = randgen(15);
        int R2 = randgen(15);
    }
    room[R1][R2] = '*'; //Roadster
    
    //Asign Yugo's position
    int Y1 = randgen(15);
    int Y2 = randgen(15);
    
    while((Y1==A1 && Y2==A2) || (Y1==P1 && Y2==P2) || (Y1==R1 && Y2==R2)){
        int Y1 = randgen(15);
        int Y2 = randgen(15);
    }
    room[Y1][Y2] = '*'; //Yugo
    
    //Asign Sleeping Elon's position
    int E1 = randgen(15);
    int E2 = randgen(15);
    
    while((E1==A1 && E2==A2) || (E1==P1 && E2==P2) || (E1==R1 && E2==R2) || (E1==Y1 && E2==Y2)){
        int E1 = randgen(15);
        int E2 = randgen(15);
    }
    room[E1][E2] = '*'; //Elon
    
    
    
    char movement = 'a';
    int result = 100;
    
    cout << "Enter w (forward/north), a (left/west), s (backward/south), d (right/east) for movement directions. Enter q to quit" << endl;
    cout << "Beware of Elon. The monent you took your 3rd step, he will wake up and teleport randomly to find you" << endl;
    
    double distance2 = colderorwarmer(A1, A2, R1, R2);
    vector<double> stringsofdistance;
    stringsofdistance.push_back(distance2);
    string verdict;
    vector<int> timesElontouchme;
    int timesRoadster = 0;
    int timesPinto = 0;
    int timesYugo = 0;
    int timesElon = 0;
    char finalchoice = 'y';
    
    while(finalchoice == 'y'){
    while (movement!= 'q'){

        for (int i = 0; i<15; ++i){
            for (int j = 0; j<15; ++j){
                room[i][j] = '*';
            }
        }
        cout << endl;
        cin >> movement;
        room[A1][A2] = '*'; //Player/ Mask the position again
        room[E1][E2] = '*'; //Elon/ Mask the position again
        
        //Elon boogie man appears randomly
        if (stringsofdistance.size()>3){
            srand (time(NULL));
            E1 = randgen(15);
            E2 = randgen(15);
        room[E1][E2] = 'E'; //Elon
        }
        
        //Coding the movement
        if(movement == 'w'){
            A1 = A1 - 1;
        }
        else if(movement == 'a'){
            A2 = A2 - 1;
        }
        else if(movement == 's'){
            A1 = A1 + 1;
        }
        else if(movement == 'd'){
            A2 = A2 + 1;
        }
        else if(movement == 'q'){
            break;
        }
        else{
            cout << "Please enter the movement again, that ain't valid!"<<endl;
            cin >> movement;
        }
        
        //Make sure noone falls out of the map
        if(A1>=15){
            A1 = 14;
        }
        if (A1<0){
            A1 = 0;
        }
        if (A2>=15){
            A2 = 14;
        }
        if (A2<0){
            A2 = 0;
        }
        
        cout << endl;
        cout << "Player's position: A("<< A1 << "," << A2 << ")." << endl;
        room[A1][A2] = 'A'; //Player/ Display the position
        
        //Determine winning condition
        if(A1==R1 && A2==R2){
            result = 0;
            break;
        }
        if(abs(E1-A1)<=1 && abs(E2-A2)<=1){
            //Allow Elon to get closed to you once, then you get another life
            timesElontouchme.push_back(placeholder);
            if (timesElontouchme.size() == 2){
            result = 1;
                break;}
            cout << "Baahhhhhhh, Elon's right next to you. You got one more chance" << endl;
        }
            if(A1==P1 && A2==P2){
            result = 2;
                break;
        }
        if(A1==Y1 && A2==Y2){
            result = 3;
            break;
        }
        
        //Check if we closer to the roadster
        distance2 = colderorwarmer(A1, A2, R1, R2);
        stringsofdistance.push_back(distance2);
        if (stringsofdistance.at(stringsofdistance.size()-2) < stringsofdistance.at(stringsofdistance.size()-1)){
            cout << "Colder!"<<endl;
        }
        if (stringsofdistance.at(stringsofdistance.size()-2) > stringsofdistance.at(stringsofdistance.size()-1)){
            cout << "Warmer!"<<endl;
        }
        if (stringsofdistance.at(stringsofdistance.size()-2) == stringsofdistance.at(stringsofdistance.size()-1)){
            cout << "Keep moving, you're still there?"<<endl;
        }
            
        //Display the gameplay
        for (int i = 0; i<15; ++i){
            for (int j = 0; j<15; ++j){
                cout << room[i][j];
                    }
            cout << endl;
        }
    }

    //Winnning condition
    switch (result){
        case 0:
            cout << "You got the roadster, baby! Enjoy your free car and freedome from Boogie man Elon Musk" << endl;
            timesRoadster = timesRoadster + 1;
            break;
        case 1:
            cout << "Sorry my dude, you just got captured by Elon Musk and now being forced to work 23 hours/day at a Tesla Gigafactory! R.I.P"<< endl;
            timesElon = timesElon + 1;
            break;
        case 2:
            cout << "Unlucky.You got the Pinto, enjoy your shitty car, mah dude!" << endl;
            timesPinto = timesPinto + 1;
            break;
        case 3:
            cout << "You've seen better days. You got the Yugo, enjoy your shitty car, mad dude!" << endl;
            timesYugo = timesYugo + 1;
            break;
    }
    
    //Reveal all locations!
    room[A1][A2] = 'A'; //Player
    room[P1][P2] = 'P'; //Pinto
    room[R1][R2] = 'R'; //Roadster
    room[Y1][Y2] = 'Y'; //Yugo
    
    cout << "Here's the final map: "<< endl;
    for (int i = 0; i<15; ++i){
        for (int j = 0; j<15; ++j){
            cout << room[i][j];
        }
        cout << endl;
    }
        cout << "Wanna play again?"<<endl;
        cout << "Press 'y' to continue, 'n' to quit." << endl;
        cin >> finalchoice;
        timesElontouchme.empty();
        cout << "Enter w (forward/north), a (left/west), s (backward/south), d (right/east) for movement directions. Enter q to quit" << endl;
        
    }
    cout << "Statistics: "<<endl;
    cout << "Number of times you found the Roadster: "<< timesRoadster << endl;
    cout << "Number of times you found the Pinto: "<< timesPinto << endl;
    cout << "Number of times you found the Yugo: "<< timesYugo << endl;
    cout << "Number of times Elon caught you: "<< timesElon << endl;
    cout << "Endgame. Thanks for play. Support Tesla!"<<endl;
    
    return 0;
    }
