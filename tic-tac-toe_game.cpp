#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void play() {
        while (!isGameOver()) {
            printBoard();
            makeMove();
            switchPlayer();
        }

        printResult();
    }

private:
    vector<std::vector<char>> board;
    char currentPlayer;

    void printBoard() const {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << ' ';
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void makeMove() {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid move! Try again.\n";
            makeMove();
        }
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isGameOver() const {
        return checkWin() || checkDraw();
    }

    bool checkWin() const {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true; // Row win
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true; // Column win
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true; // Diagonal win (top-left to bottom-right)
        }

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true; // Diagonal win (top-right to bottom-left)
        }

        return false;
    }

    bool checkDraw() const {
        // Check if the board is full
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false; // There is an empty space, game is not a draw
                }
            }
        }
        return true; // All spaces are filled, game is a draw
    }

    void printResult() const {
        printBoard();
        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }
    }
};

int main() {
    char a='y';
    TicTacToe game;
    while(a=='y'){
    game.play();
    while(true){
    cout<<"\nDo you want to play again(y for yes and n for no): ";
    cin>>a;

    if(a!='y' && a!='n'){
        cout<<"\nInvalid Input.Please enter again"<<endl;
        continue;
    }
    else if(a=='y' || a=='n'){
        break;
    }
    }

    }
    return 0;
}
