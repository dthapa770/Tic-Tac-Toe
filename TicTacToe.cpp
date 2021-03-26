// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

//Displays grid of the game
void displayBoard(char board[][3]) {
    cout << "-------------\n";
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "-------------\n";
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "-------------\n";
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "-------------\n";
}


void makeAMove(char board[][3], char input) {
    int row;
    int column;
  
        cout << "Enter a row (0, 1, 2) for player " << input << ":";
        cin >> row;
    
        cout << "Enter a column (0, 1, 2) for player " << input << ":";
        cin >> column;
      
        if (isblank(board[row][column])) {
            board[row][column] = input;
        }
        else {
            cout << "This cell is already occupied. Try a different cell \n";
            makeAMove(board, input);
        }
    
}

//returns true if there is no space in rows and columns
bool isDraw(char board[][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (isblank(board[i][j]))
                return false;
        }
    }
    return true;
}

// check the columns and diagonals to determine winner
bool isWon(char input, char board[][3]) {
        if (board[0][0] == input && board[0][1] == input && board[0][2] == input)
            return true;
        if (board[1][0] == input && board[1][1] == input && board[1][2] == input)
            return true;
        if (board[2][0] == input && board[2][1] == input && board[2][2] == input)
            return true;
        if (board[0][0] == input && board[1][0] == input && board[2][0] == input)
            return true;
        if (board[0][1] == input && board[1][1] == input && board[2][1] == input)
            return true;
        if (board[0][2] == input && board[1][2] == input && board[2][2] == input)
            return true;
        if (board[2][0] == input && board[1][1] == input && board[0][2] == input)
            return true;
        if (board[0][0] == input && board[1][1] == input && board[2][2] == input)
            return true;
        if (board[0][2] == input && board[1][1] == input && board[2][0] == input)
            return true;
 
    return false;
}


int main() {
    //
    //	PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

