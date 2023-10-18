
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

class TicTacToe {
public:
    TicTacToe();

    void playGame();

private:
    void printBoard();
    bool checkWin();
    bool checkDraw();

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
};

#endif // TICTACTOE_H
#pragma once
