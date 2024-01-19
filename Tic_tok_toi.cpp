#include <iostream>
using namespace std;

char board[3][3] = { { '1', '2', '3' },
                    { '4', '5', '6' },
                    { '7', '8', '9' } };

char currentPlayer = 'X';

void displayBoard() {
    cout << "Tic-Tac-Toe Game\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isMoveValid(int move) {
    return (move >= 1 && move <= 9 && board[(move - 1) / 3][(move - 1) % 3] == (char)(move + '0'));
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int move;
    char playAgain;

    do {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (isMoveValid(move)) {
            board[(move - 1) / 3][(move - 1) % 3] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
            } else {
                switchPlayer();
                continue;
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            // Reset the game board
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    board[i][j] = (char)(3 * i + j + 1 + '0');
                }
            }
            currentPlayer = 'X';
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
