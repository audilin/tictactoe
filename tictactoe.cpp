// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void board(char x[3][3], char turn) { // 1 for player 1, and 2 for player 2
    cout << "   1   2   3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ") ";
        for (int j = 0; j < 3; j++) {
            if (j) cout << " | ";
            cout << x[i][j];
        }
        cout << endl << "  ---|---|---" << endl;
    }
    cout << "please enter your row and column of choice: ";
}

bool checkWin(char x[3][3], char turn) {
    for (int i = 0; i < 3; i++) { // check each row
        if (x[i][0] == turn && x[i][1] == turn && x[i][2] == turn) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) { // check each column
        if (x[0][j] == turn && x[1][j] == turn && x[2][j] == turn) {
            return true;
        }
    }
    if (x[1][1] == turn) { // centerpiece
        if (x[0][0] == turn && x[2][2] == turn)return true;
        if (x[0][2] == turn && x[2][0] == turn) return true;
    }
    return false;
}

int main()
{
    cout << "Welcome to Audi's tic-tac-toe game! This was created 1/12/2021. Good luck and I hope you enjoy playing against a friend!" << endl;
    int r, c;
    char pl1 = '1', pl2 = '2';
    char x[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            x[i][j] = ' ';
    cout << "do you want to play with special characters? (Y/N): ";
    char ans;
    cin >> ans;
    if (ans == 'Y') {
        do {
            cout << "enter the character for player 1: ";
            cin >> pl1;
            cout << "enter the character for player 2: ";
            cin >> pl2;
        } while (pl1 == pl2);
    }
    else {
        cout << "That's alright, maybe try using special characters next time!" << endl;
    }
    cout << endl;
    char turn = pl1;
    cout << "Directions: players take turns marking a row and column, and the game ends when a player has 3-in-a-row, or when all 9 boxes are filled. In order to input row and column, enter them separated by a space, then hit enter." << endl;
    int count = 0;
    while (count < 9 && !checkWin(x, pl1) && !checkWin(x, pl2)) {
        cout << endl << "It is player ";
        if (turn == pl1)cout << 1;
        else if (turn == pl2)cout << 2;
        else cout << "idk who";
        cout << "'s turn" << endl;
        board(x, turn);
        cin >> r >> c;
        r--; c--;
        while (x[r][c] != ' ') {
            cout << "please try again, this spot is already full." << endl;
            cin >> r >> c;
            r--; c--;
        }
        x[r][c] = turn;
        count++;
        if (turn == pl1)turn = pl2;
        else if (turn == pl2)turn = pl1;
        else cout << "idk whose turn it is" << endl;
    }
    
    if (checkWin(x, pl1))cout << "player 1 won!" << endl;
    else if (checkWin(x, pl2))cout << "player 2 won!" << endl;
    else cout << "DRAW!" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
