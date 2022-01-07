#ifndef GAME_OF_LIFE
#define GAME_OF_LIFE

#include <vector>

using namespace std;

class GameOfLife {
    public:
        int M, N;
        static const int MAX_ROWS, MAX_COLS;
        vector<vector<int> > board;
    
        GameOfLife(int, int);
        ~GameOfLife();
        
        void initBoard(string filename);
        void initBoard2(string filename);
        void printMenu(ostream&) const;
        void printBoard(ostream&) const;
        void increment();
        void runSim();
        void genRandomBoard(int M, int N);
};

#endif