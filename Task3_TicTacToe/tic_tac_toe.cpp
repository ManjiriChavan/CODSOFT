#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board
char currentPlayer = 'X'; // Player 1 starts with 'X'

// Function to initialize the board
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ch++;
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

// Function to make a move
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check win
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }

    // check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    int position;
    bool gameRunning = true;

    initializeBoard();

    cout << "Welcome to Tic-Tac-Toe (Player 1: X, Player 2: O)\n";

    while (gameRunning) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> position;

        if (!makeMove(position))
            continue;

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw! 🤝\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
