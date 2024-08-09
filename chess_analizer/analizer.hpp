#pragma once
#include<vector>
#include<string>
#include"figure.hpp"
#include<iostream>
#include"chess_board.hpp"

class analizer
{
private:
    std::pair<int, int> KW;
    std::pair<int, int> KB;
    std::vector<std::vector<std::string>> m_chess_board;

public:
    analizer() = delete;

    analizer(chess_board board);

    bool isValidMove(int x, int y);

    bool checkLinearMoves(int x, int y, const std::string& piece, const std::string& targetKing);

    bool checkDiagonalMoves(int x, int y, const std::string& piece, const std::string& targetKing);

    bool checkKnightMoves(int x, int y, const std::string& piece, const std::string& targetKing);

    bool analize_for_check();

    std::pair<bool, bool> analizer_check_mate();

    void analize_lvl_1();
};