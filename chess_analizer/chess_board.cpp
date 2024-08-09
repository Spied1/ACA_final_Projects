#include<vector>
#include<string>
#include"figure.hpp"
#include<iostream>
#include"chess_board.hpp"

chess_board::chess_board()
{
    std::string n = " 1 2 3 4 5 6 7 8";
    std::vector<std::vector<std::string>> matrix(9, std::vector<std::string>(9, "__"));
    for (int i = 0; i < 9; ++i)
    {
        matrix[i][8] = 'A' + i;
        
    }
    matrix[8][0] = " 1";
    matrix[8][1] = " 2";
    matrix[8][2] = " 3";
    matrix[8][3] = " 4";
    matrix[8][4] = " 5";
    matrix[8][5] = " 6";
    matrix[8][6] = " 7";
    matrix[8][7] = " 8";
    matrix[8][8] = " ";
    m_chess_board = matrix;
    
}

bool chess_board::is_valid_place(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void chess_board::add_figure(figure* figure)
{
    int x = figure->get_x();
    int y = figure->get_y();

    

    if (m_chess_board[x][y] != "__")
    {
        std::cout << "error, place already taken" << std::endl;
        return;
    }

    std::vector<std::pair<int, int>> moves = { { -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,0 },{ 1, 1 },{ 1,1 } };
    if (figure->get_n_c() == "KB")
    {
        for (auto move : moves)
        {
            if (is_valid_place(x + move.first, y + move.second))
            {
                if (m_chess_board[x + move.first][y + move.second] == "KW")
                {
                    std::cout << "error, white king near king black" << std::endl;
                    return;
                }
            }
        }
    }
    if (figure->get_n_c() == "KW")
    {
        for (auto move : moves)
        {
            if (is_valid_place(x + move.first, y + move.second))
            {
                if (m_chess_board[x + move.first][y + move.second] == "KB")
                {
                    std::cout << "error, white king near king black" << std::endl;
                    return;
                }
            }
        }
    }

    m_chess_board[x][y] = figure->get_n_c();
}

void chess_board::delete_figure(int x, int y)
{
    m_chess_board[x][y] = "__";
}

std::vector<std::vector<std::string>> chess_board::get_board()
{
    return m_chess_board;
}

void chess_board::draw()
{
    for (int i = 8; i > -1; --i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::cout << m_chess_board[i][j] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
