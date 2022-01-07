#include <iostream>
#include <vector>
#include <string>
#include "game_of_life.h"

using namespace std;

int main() {

    GameOfLife game_of_life(5, 5);

    game_of_life.printMenu(cout);

    int choice;
    bool valid;
    // Check to ensure the user input is an integer.
    do{

        valid = true;   // Set valid to true
        cin >> choice;      // User inputs his/her menu choice.

        // If the user input is not of valid data type (int).
        if(cin.fail()){
            cin.clear();                                        // Reset the cin flag.
            cin.ignore(1000,'\n');                              // Ignore the input.
            cout << "Please enter an integer only." << endl;
            valid = false;                                      // Reset valid to false.
        }
        else if ((choice != 1) & (choice != 2)) {
            cin.clear();                                        // Reset the cin flag.
            cin.ignore(1000,'\n');                              // Ignore the input.
            cout << "Please a valid option." << endl;
            valid = false;                                      // Reset valid to false.
        }

    }while(!valid);

    string filename;
    switch(choice) {
        case 1:
            cout << "Enter filename:" << endl;
            cin >> filename;
            game_of_life.initBoard2(filename);
            game_of_life.runSim();
            break;
        case 2:
            int M, N;
            cout << "Enter height (max=200):" << endl;
            do{
                valid = true;   // Set valid to true
                cin >> choice;      // User inputs menu choice
                // If the user input is not of valid data type (int).
                if(cin.fail()){
                    cin.clear();                                        // Reset the cin flag.
                    cin.ignore(1000,'\n');                              // Ignore the input.
                    cout << "Please enter an integer only." << endl;
                    valid = false;                                      // Reset valid to false.
                }
                else if (choice > game_of_life.MAX_ROWS) {
                    cin.clear();                                        // Reset the cin flag.
                    cin.ignore(1000,'\n');                              // Ignore the input.
                    cout << "Please a valid option." << endl;
                    valid = false;                                      // Reset valid to false.
                }

            }while(!valid);
            M = choice;
            cout << "Enter width (max=200):" << endl;
            do{
                valid = true;   // Set valid to true
                cin >> choice;      // User inputs menu choice
                // If the user input is not of valid data type (int).
                if(cin.fail()){
                    cin.clear();                                        // Reset the cin flag.
                    cin.ignore(1000,'\n');                              // Ignore the input.
                    cout << "Please enter an integer only." << endl;
                    valid = false;                                      // Reset valid to false.
                }
                else if (choice > game_of_life.MAX_COLS) {
                    cin.clear();                                        // Reset the cin flag.
                    cin.ignore(1000,'\n');                              // Ignore the input.
                    cout << "Please a valid option." << endl;
                    valid = false;                                      // Reset valid to false.
                }

            }while(!valid);
            N = choice;
            
            cout << "Width: " << N << endl << "Height: " << N << endl;
            game_of_life.genRandomBoard(M, N);
            game_of_life.runSim();
            break;

    }
  
    

    return 0;
}

