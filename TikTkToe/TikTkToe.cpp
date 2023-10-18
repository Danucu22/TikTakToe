#include "tictactoe.h"
#include <iostream>
#include <vector>
#include <cstdlib>
class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        std::system("cls");
        std::cout << "  1 2 3" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << " ";
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void playGame() {
        int row, col;

        while (true) {
            printBoard();

            std::cout << "Player " << currentPlayer << ", Introdu randul (1-3) si coloana (1-3): ";
            std::cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                std::cout << "Nu este asa miscare,incearca din nou" << std::endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin()) {
                printBoard();
                std::cout << "Player " << currentPlayer << " a cistigat!" << std::endl;
                break;
            }
            else if (checkDraw()) {
                printBoard();
                std::cout << "Egalitate!" << std::endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true; 
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true; 
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true; 
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true; 
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false; 
                }
            }
        }
        return true; 
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
