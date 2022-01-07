#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include "game_of_life.h"

using namespace std;

const int GameOfLife::MAX_ROWS = 200;
const int GameOfLife::MAX_COLS = 200;

GameOfLife::GameOfLife(int m, int n) {
    M = m;
    N = n;
}

GameOfLife::~GameOfLife() {
}

void GameOfLife::printMenu(ostream& out) const {
    cout << "Please select an option:" << endl;
    cout << "1. Enter filename to create board from" << endl;
    cout << "2. Generate random board of specified dimensions" << endl;
}

void GameOfLife::printBoard(ostream& out) const {
    for (size_t i=0;i<board.size();i++) {
        for(size_t j=0;j<board[i].size();j++)
        {
            if (board[i][j] == 1)
                out << "\u233E" << " ";
            else
                out << " " << " ";
        }
        out << endl;
    }
}

void GameOfLife::genRandomBoard(int M, int N) {
    vector<int> v;
    srand(time(0));
    for (int i=0; i<M; i++) {
        v.clear();
        for (int j=0; j<N; j++) {
            v.push_back(rand()%2);
        }
        board.push_back(v);
    }
}

void GameOfLife::increment() {
    int cnt;
    int M = board.size();
    int N = board[0].size();
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++){
            cnt = -board[i][j];
            for (int I=max(i-1, 0); I<min(i+2, M); ++I) {
                for (int J=max(j-1, 0); J<min(j+2, N); ++J) {
                    cnt += (board[I][J] & 1);
                }
            }
            if ((cnt | board[i][j]) == 3) {
                board[i][j] |= 2;
            }
        }
    }
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++){
            board[i][j] >>= 1;
        }
    }
    return;
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
}

void GameOfLife::initBoard(string filename) {

    ifstream file;
    string row;
    string cell_str;
    int cell_val;

    vector<int> v;

    file.open(filename);

    if (file.is_open()) {
        //cout << "File: " + filename + " is open!" << endl;
        while (getline(file, row)) {
            stringstream ss(row);
            v.clear();
            while (getline(ss, cell_str, ',')) {
                v.push_back(stoi(cell_str));
            }
            board.push_back(v);
        }
    }
}

void GameOfLife::initBoard2(string filename) {

    ifstream file;
    string row;
    char cell_c;
    int cell_val;

    vector<int> v;

    file.open(filename);

    if (file.is_open()) {
        //cout << "File: " + filename + " is open!" << endl;
        while (getline(file, row)) {
            stringstream ss(row);
            v.clear();
            while (ss.get(cell_c)) {
                if (cell_c == '.') {
                    v.push_back(0);
                }
                else {
                    v.push_back(1);
                }
            }
            board.push_back(v);
        }
    }
}

void GameOfLife::runSim() {
    while (1) {
        printBoard(cout);
        for (int i=0; i<board.size(); i++) {
            cout << "\033[A";
        }
        increment();
        for (int i=0; i<200000000; i++) {
                
        }
    }
}
