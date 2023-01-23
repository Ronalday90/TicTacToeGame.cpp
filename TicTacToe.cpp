#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

char board[ROWS][COLS] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void printBoard() {
    cout << "Tic Tac Toe" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char player) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char player = 'X';
    int x, y;
    while (true) {
        printBoard();
        cout << "Player " << player << ", enter x and y coordinates (0-2) to place your mark: ";
        cin >> x >> y;
        board[x][y] = player;

        if (checkWin(player)) {
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        if (checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    return 0;
}
