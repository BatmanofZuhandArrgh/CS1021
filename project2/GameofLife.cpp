#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
using namespace std;

//Create a struct of cell for each spot on the board
class cell{
public:
    cell(){
        row = 0;
        col = 0;
        state = '.';
        nearbyneighbors = 0;
    }
    
    cell(int in_x, int in_y){
        row = in_x;
        col = in_y;
        //state = deadoralive;
        //nearbyneighbors = nearby;
    }
    
    void setCordinate(int in_x, int in_y){
        row = in_x;
        col = in_y;
    }
    
    void setState(char deadoralive){
        state = deadoralive;
    }
    
    void setNearbyNeighbors(int nearby){
        nearbyneighbors = nearby;
    }
    
    int getRow(){
        return row;
    }
    
    int getCol(){
        return col;
    }
    
    int getNearbyNeighbors(){
        return nearbyneighbors;
    }
    
    void addNearbyNeighbors(){
        nearbyneighbors = nearbyneighbors + 1;
    }
    int getState(){
        return state;
    }
    
    void Displaystate(){
        cout << state;
    }

private:
    int row, col;
    char state;
    int nearbyneighbors;
};

//(1.) Check if user size input is valid
void checkifvalid(int &metric);

//(4.5.6.) Check if user condition input is valid
void checkifvalid(int &metric, int upperlimit, int lowerlimit);

//(9.III.) Check if user choice is valid
void checkifvalid(char &choice);

//(9.I.) Help function
void helpme(int toofewcondition, int toomanycondition, int birthcondition);
    
int main(){
    //1. User input size of the environment
    int row, col;
    cout << "Please input the number of rows: (Maximum 30, Minimum 7)" << endl;
    cin >> row;
    checkifvalid(row);
    
    cout << "Please in put the number of column: (Maximum 30, Minimum 7)" << endl;
    cin >> col;
    checkifvalid(col);
    
    //2. Set an array to populate the cells with values
    cell board[row][col];
    
   //3. Populate arrays with cells and also set their original state
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            board[i][j].setCordinate(i,j);
            board[i][j].setState('.');
            board[i][j].setNearbyNeighbors(0);
        }
    }
    
    //4. Enter minimum survival condition. If the number of neighbors is lower than this, the cell dies
    int toofewcondition;
    cout << "1. The cell will die because it's too lonely. How few neighbors do you want for it to die? (Prefereably 1 or fewer)"<< endl;
    cout << "Please input this more than the 0 and fewer than 9" << endl;
    cin >> toofewcondition;
    cout << endl;
    checkifvalid(toofewcondition, 9,0 );

    
    //5. Enter maximum survival condition. If the number of neighbors is lower than this, the cell dies
    int toomanycondition;
    cout << "2. The cell will die because the area is too crowded. How many neighbors do you want for it to die? (Preferably 4 or more)" << endl;
    cout << "Please input this more than the minimum survival condition." << endl;
    cin >> toomanycondition;
    cout << endl;
    checkifvalid(toomanycondition, 9, toofewcondition);
    
    //6. Enter perfect birth condition. If the number of neighbors is more than this, the cell dies
    int birthcondition;
    cout << "3. A cell is born when these conditions are satisfied. How many neighbors do you want for it to be born?"<< endl;
    cout << "Please input this more than the minimum survival condition and fewer than the maximum survival condition." << endl;
    cin >> birthcondition;
    cout << endl;
    checkifvalid(birthcondition, toomanycondition, toofewcondition);
    
    //7. Set the original condition using outsider file
    //board[0][0].setState('*');
    //board[4][5].setState('*');
    //board[5][6].setState('*');
    //board[6][4].setState('*');
    //board[6][5].setState('*');
    //board[6][6].setState('*');
    
    vector<int> listofcordinates;
    string input;
    int invar;
    
    //a. Initiate and open file
    ifstream infile;
    infile.open("/Users/MACOS/GameofLifeGlider.txt");
    
    //b. Extract and convert string into int. Pushback into Vector
    while(getline(infile, input)) {
        istringstream( input ) >> invar;
        listofcordinates.push_back(invar);
    }
    
    //for(int i = 0; i < listofcordinates.size(); i++) {
      //  cout << listofcordinates.at(i) << endl;
    //}
    
    //c. Close file
    infile.close();
    
    //d. Set the coordinate for the default living cells
    for (int a = 0; a < listofcordinates.size(); a++){
        if (a%2 == 0){
            board[listofcordinates.at(a)][listofcordinates.at(a+1)].setState('*');
        }
    }
    
    //8. Draws the original board
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            board[i][j].Displaystate();
        }
        cout << endl;
    }
    cout << endl;
    char choice = ' ';
    
    //9. Starting the loop
    while(choice != 'q' && choice != 'Q'){
    
    // I. When the user asks for help
    if (choice == 'h' || choice == 'H'){
        helpme(toofewcondition, toomanycondition, birthcondition);
        }
        
    // II. When the game continues to the next generation
    else if(choice == 'c' || choice == 'C'){
    //a. Iterate across all cell to count Neighbors
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            
            //Reset the Nearbyneighbor count to 0
            board[i][j].setNearbyNeighbors(0);
            
            if (i-1<row && j-1<col){
        if (board[i-1][j-1].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }
            
             if (i-1<row && j<col){
        if (board[i-1][j].getState() == '*')
            board[i][j].addNearbyNeighbors();
             }//N +=1;
            
            if (i-1<row && j+1<col){
        if (board[i-1][j+1].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }//N +=1;
            
            if (i<row && j-1<col){
        if (board[i][j-1].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }//N +=1;
            
            if (i<row && j+1<col){
        if (board[i][j+1].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }// N +=1;
            
            if (i+1<row && j-1<col){
        if (board[i+1][j-1].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }//N +=1;
            
            if (i+1<row && j<col){
        if (board[i+1][j].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }//N +=1;
            
            if (i+1<row && j+1<col){
        if (board[i+1][j+1].getState() == '*')
            board[i][j].addNearbyNeighbors();
            }//N +=1;
        }
    }

        //b. Iterate across all cells to kill and gives birth to cells according to conditions
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (board[i][j].getState() == '.'){
                if (board[i][j].getNearbyNeighbors() == birthcondition)
                    board[i][j].setState('*');
            }
            else{
                if (board[i][j].getNearbyNeighbors() >= toomanycondition || board[i][j].getNearbyNeighbors() <= toofewcondition)
                    board[i][j].setState('.');
        }
    }
    }
    
    //c. Draw board after all iteration
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            board[i][j].Displaystate();
        }
        cout << endl;
    }
    cout << endl;
    }//End of II if else statement
        
        //III. When the user input the wrong choice
    else{
        checkifvalid(choice);
    }
        
        //IV. Prompt the user the choice to do what's next
        cout << "What do you wanna do next? Press c to continue the game, q to quit!" << endl;
        cin >> choice;
    }//End of loop
    
    return 0;
}

//(1.) Check if user size input is valid
void checkifvalid(int &metric){
    while (metric < 7 || metric > 30) {
        cout << "Invalid, please input the number again"<<endl;
        cin >> metric;
        cout << endl;
    }
}

//(4.5.6.) Check if user condition input is valid
void checkifvalid(int &metric, int upperlimit, int lowerlimit){
    while (metric <= lowerlimit || metric > upperlimit) {
        cout << "Invalid, please input the number again"<<endl;
        cin >> metric;
        cout << endl;
    }
}

//(9.III.) Check if user choice is valid
void checkifvalid(char &choice){
    while (choice != 'h' && choice != 'H' && choice != 'q' && choice != 'Q' && choice != 'c' && choice != 'C'){
        cout << "Invalid, please input the choice again. Please press c to continue, h for help and q to quit"<<endl;
        cin >> choice;
    }
}

//(9.I.) Help function
void helpme(int toofewcondition, int toomanycondition, int birthcondition){
    cout << "The Game of Life is not your typical computer game. It is a 'cellular automaton', and was invented by Cambridge mathematician John Conway. This game became widely known when it was mentioned in an article published by Scientific American in 1970. It consists of a collection of cells which, based on a few mathematical rules, can live, die or multiply. Depending on the initial conditions, the cells form various patterns throughout the course of the game. " << endl;
    cout << "For a space that is 'populated': " << endl;
    cout << "Each cell with " << toofewcondition << " or fewer neighbors dies, as if by solitude." << endl;
    cout << "Each cell with " << toomanycondition << " or more neighbors dies, as if by overpopulation."<< endl;
    cout << "For a space that is 'empty' or 'unpopulated': " << endl;
    cout << "Each empty cell with " << birthcondition << " neighbors becomes populated." << endl;
}
