/*
 * Project Title:
 * Memeswiper
 * Description: This is like the original Minesweeper...
 *              but worse...
 * Functionality:
 * This game allows the user to select the dimensions of the
 * square grid and the amount of mines. From here, the user
 * inputs the coordinates of which spot they would like to
 * select and they have the option to place a flag, remove
 * a flag, or open the square. If it is a mine, the game is
 * over and the placement of all of the mines are shown. If
 * it is not a mine, the number of mines within a 3x3 square
 * surrounding the selected spot is shown. The user wins when
 * flags are placed correctly on the mines and all non-mine
 * spots are opened. Each turn, an updated count of flags
 * and mines remaining are shown.
 *
 * Developers:
 * - Grace Owens - owensgr@mail.uc.edu
 * - Anh Nguyen - nguye2aq@mail.uc.edu
 *
 *
 * Developer comments: // Not optional
 * Developer 1: Grace Owens
 * -Created the initial board and populating with asteriks and randomly placed,
 * user specified mines, developed the code to check for mines in the
 * surrounding area and update the open spot with the number of mines along with general
 * debugging and formatting, coded the board to show all mines once game is lost.
 *
 * Developer 2: Anh Nguyen
 * Please describe what tasks you performed and what your learned from your experience
 * Set up initial libraries and int main()
 * Write most of the functions
 * Set up 2 arrays of boards, populated them with asterisks and mines
 * Write 3/4 if else statements (h, f, else) and switch cases
 * Co-write winning condition
 */

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void displayBoardwithallasterisks(int);
//show board with all asterisks

int randgen(int);
//random generator

void helpme();
//Help function

void drawtopRuler(int);
//Draw top ruler, duh! Make sure to do this everytime we display the board

void checkifvalid(int&,int);
//Check if user input is valid against dimensions

void placeorremoveFlag(char&);
//Place or remove flag

int mineCheck(char gameBoardUnderneath);
//counts the amount of mines around spot

void checkchoicevalid(char&);
//Check if choice is valid

//void updatedBoard(vector <char>);
//show board after all options//

//bool checkMine(int, int, int, int);
//checks position of Mine compared to user option to open spot

//int numberOfMinesClose(vector <char>, int, int);
/*check the 3x3 grid around spot*/



int main()
{
    srand(time(NULL));
    int dimensions, numMines, row, column, winorlose;
    char choice;
    int winorlosecounter = 0;
    int nearbyminecounter = 0;
    int numMinesBoard = 0;

    //User decide width of the board
    cout << "Enter the width of the square board you would like (5-25): " << endl;
    cin >> dimensions;

    //Check if input is valid
    while (dimensions<5 || dimensions>25) {
        cout << "Oops, invalid input. Please input the width of the board again!"<<endl;
        cin >> dimensions;
    }

    //User decide number of mines
    cout << "Enter the MAXIMUM number of mines you would like: " << endl;
    cin >> numMines;

    //Check if the number of mines is valid
    while (numMines>=dimensions*dimensions || numMines<1) {
        cout << "Oops, invalid input. Please input the number of mines again!" << endl;
        cin >> numMines;
    }
//Make sure you stretch your terminal
    displayBoardwithallasterisks(dimensions);

    //This is the one where user see everytime they choose something
    char gameBoardsurface[dimensions][dimensions];

    //This is the one underneath where mines are shown
    char gameBoardunderneath[dimensions][dimensions];

    //Populating them with asterisks
    for (int r = 0; r<dimensions;r++){
        for (int c = 0; c<dimensions; c++){
            gameBoardsurface[r][c] = '*';
            gameBoardunderneath[r][c] = '*';
            //cout <<
        }
    }


    //randomly places mines on board, make sure no mines are in the same spot

    for (int i = 0; i<numMines; i++){
        gameBoardunderneath[randgen(dimensions)][randgen(dimensions)] = 'm';
    }

    for (int r = 0; r<dimensions;r++){
     for (int c = 0; c<dimensions;c++){
     if (gameBoardunderneath[r][c] == 'm'){
     numMinesBoard +=1;}
     }
     }
    //Testing
                             //   cout << endl;
                             // cout << numMinesBoard<< endl;
    choice = ' ';
    cout << "Input \"q\" to quit"<<endl;
    cout << "Choose O to Open spot if you think there's no mine there; F to Place flag if you think there's a mine there, and to Remove flag if you think you placed a flag wrong"<<endl;
    cout << "So what do ya wan'na do now, chief?"<<endl;
    cin >> choice;

    //displayBoardwithallasterisks(dimensions);
    while ( choice!='q' && choice!= 'Q'){

        if (choice == 'O' || choice == 'o'){
            cout << "You've chosen to open a slot. Pick the row number!"<<endl;

            //Enter row and check if valid
            cin >> row;
            checkifvalid(row, dimensions);

            cout << "Great choice! Now pick the column number: " << endl;
            //Enter column and check if valid
            cin >> column;
            checkifvalid(column, dimensions);

            //If the spot contains a mine
            if (gameBoardunderneath[row-1][column-1] == 'm'){
                winorlose = 2;
                //choice = 'q';
                drawtopRuler(dimensions);
                for (int r = 0; r<dimensions;r++){
                    for (int c = 0; c<dimensions; c++){
                        cout << gameBoardunderneath[r][c]<< "\t";
                    }
                    cout << endl;
                }
                //choice = 'q';
                break;
            }

            //If the spot doesn't have a mine
            else{
                nearbyminecounter = 0;
                if (row<dimensions && column<dimensions){
                    if (gameBoardunderneath[row][column] == 'm')
                        nearbyminecounter+=1;
                }
                if (row-1<dimensions && column<dimensions){
                    if (gameBoardunderneath[row-1][column] == 'm')
                        nearbyminecounter+=1;
                }
                if (row-2<dimensions && column<dimensions){
                    if (gameBoardunderneath[row-2][column] == 'm')
                        nearbyminecounter+=1;
                }
                if (row-2<dimensions && column-1<dimensions){
                    if (gameBoardunderneath[row-2][column-1] == 'm')
                        nearbyminecounter+=1;
                }
                if (row-2<dimensions && column-2<dimensions){
                    if (gameBoardunderneath[row-2][column-2] == 'm')
                        nearbyminecounter+=1;
                }
                if (row-1<dimensions && column-2<dimensions){
                    if (gameBoardunderneath[row-1][column-2] == 'm')
                        nearbyminecounter+=1;
                }
                if (row<dimensions && column-2<dimensions){
                    if (gameBoardunderneath[row][column-2] == 'm')
                        nearbyminecounter+=1;
                }
                if (row<dimensions && column-1<dimensions){
                    if (gameBoardunderneath[row][column-1] == 'm')
                        nearbyminecounter+=1;
                }
                
                gameBoardsurface[row-1][column-1]=static_cast<char>(nearbyminecounter+48);
            }
        }//End of if 148
        else if ( choice == 'F' || choice == 'f'){
            cout << "You've chosen to place or remove a flag. Pick the row number!" << endl;

            //Enter row and check if valid
            cin >> row;
            checkifvalid(row, dimensions);

            //Enter column and check if valid
            cout << "Great choice, pick the column number now!"<<endl;
            cin >> column;
            checkifvalid(column, dimensions);

            //Place or remove flag
            placeorremoveFlag(gameBoardsurface[row-1][column-1]);
        }

        else if ( choice == 'h' || choice == 'H'){
            helpme();
        }

        else{
                        checkchoicevalid(choice);
        }

        //Draw surface board at the end of every choice
        drawtopRuler(dimensions);
        for (int r = 0; r<dimensions;r++){
            for (int c = 0; c<dimensions; c++){
                cout << gameBoardsurface[r][c]<< "\t";
            }
            cout << "|"<< r+1;
            cout << endl<<endl;
        }


        //Check if won
        winorlosecounter = 0;
        for (int r = 0; r<dimensions;r++){
            for (int c = 0; c<dimensions; c++){
                if((gameBoardunderneath[r][c] == 'm' && gameBoardsurface[r][c] == 'P'))
                    winorlosecounter = winorlosecounter + 1;
            }
        }
    if (winorlosecounter == numMinesBoard){
        winorlose = 1;
break;
    }

    cout << "Input another value?"<<endl;
    cout << "Choose O to Open spot if you think there's no mine there; F to Place flag if you think there's a mine there, and to Remove flag if you think you placed a flag wrong"<<endl;
    cin >> choice;
    } //End of while loop

    switch (winorlose) {
        case 0:
            cout << "Not interested in playing, huh?"<<endl;
            break;
        case 1:
            cout << "Congrats, you won." << endl;
            break;
        case 2:
            cout << "Yikes, you're just blown up. You lost sorry lol"<<endl;
            break;
        default:
            break;
    }
    return 0;
}

//FUNCTION

//show board with all asterisks
void displayBoardwithallasterisks(int dimensions){
    for (int i = 0; i < dimensions; i++){
        cout << i+1<< "\t";
    }
    cout << endl;
    char gameBoard[dimensions][dimensions];
    for (int r = 0; r<dimensions;r++){
        for (int c = 0; c<dimensions; c++){
            gameBoard[r][c] = '*';
            cout << gameBoard[r][c] << "\t";
        }
        cout << "|"<< r+1;
        cout << "\n\n";
    }
    cout << endl;
}

//random generator
int randgen(int x){
    return rand()%x+1;
}

//Help function
void helpme(){
    cout << "This game allows the user to select the dimensions of the square grid and the amount of mines. From  here, the user inputs the coordinates of which spot they would like to select and they have the option to place a flag, remove a flag, or open the square. If it is a mine, the game is over and the placement of all of the mines are shown. If it is not a mine, the number of mines within a 3x3 square surrounding the selected spot is shown. The user wins when flags are placed correctly on the mines and all non-mine spots are opened. Each turn, an updated count of flags and mines remaining are shown."<< endl;
}

//Draw top ruler
void drawtopRuler(int dimensions){
    for (int i = 0; i < dimensions; i++){cout << i+1<<"\t";}
    cout << endl;
}

//Check if user input is valid against dimensions
void checkifvalid(int &metric, int dimensions){
    while (metric-1 > dimensions || metric-1 < 0) {
        cout << "Invalid, please input the number again"<<endl;
        cin >> metric;
    }
}

//Place or remove flag
void placeorremoveFlag(char &character){
    if (character!='P'){
        character= 'P';
    }
    else if(character=='P'){
        character= '*';
    }
}

void checkchoicevalid(char &choice){
    while (choice!='h'&& choice!='H' && choice!='O' && choice!='o'&& choice!='q' && choice!='Q' && choice!='F' && choice!='f'){
        cout << "Invalid move! Input another!" <<endl;
        cin >> choice;
    }
}
