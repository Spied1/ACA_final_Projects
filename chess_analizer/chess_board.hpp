#pragma once
#include<vector>
#include<string>
#include"figure.hpp"
#include<iostream>

class chess_board
{
private:
    std::vector<std::vector<std::string>> m_chess_board;

public:
    chess_board();

    bool is_valid_place(int x, int y);

    void add_figure(figure* figure);

    void delete_figure(int x, int y);

    std::vector<std::vector<std::string>> get_board();

    void draw();
};