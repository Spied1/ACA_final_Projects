#include<iostream>
#include<vector>
#include<string>
#include"hpps.hpp"

void figure_adding(chess_board& board)
{
    std::string figure_name;
    figure* figu = new pawn(1, 1, 1);
    bool color;
    char x;
    int y;
    std::string position;
    std::cout << "write figures to add, example:" << std::endl;
    std::cout << "(figure name) (color 1-w 0-b) (position (A1))" << std::endl;

    while (true)
    {
        std::cin >> figure_name;

        if (figure_name == "stop")
        {
            break;
        }
        std::cin >> color >> position;

        x = position[0];
        y = position[1] - '0';

        if (!(x >= 'A' && x <= 'H'))
        {
            std::cout << "bad cords 1" << std::endl;
        }
        else if (!(y >= 1 && y <= 8))
        {
            std::cout << "bad cords 2" << std::endl;
        }
        else
        {
            if (figure_name == "pawn")
            {
                figu = new pawn(color, x, y);
                board.add_figure(figu);
            }
            else if (figure_name == "knight")
            {
                figu = new knight(color, x, y);
                board.add_figure(figu);
            }
            else if (figure_name == "bishop")
            {
                figu = new bishop(color, x, y);
                board.add_figure(figu);
            }
            else if (figure_name == "rook")
            {
                figu = new rook(color, x, y);
                board.add_figure(figu);
            }
            else if (figure_name == "queen")
            {
                figu = new queen(color, x, y);
                board.add_figure(figu);
            }
            else if (figure_name == "king")
            {
                figu = new king(color, x, y);
                board.add_figure(figu);
            }
            else
            {
                std::cout << "unknown figure" << std::endl;
            }

            //std::cout << figu->get_n_c() << " " << figu->get_x() << " " << figu->get_y() << std::endl;
            delete figu;
        }
    }
}

void test1(chess_board& board)
{
    //color x y
    
    figure* fig = new rook(1, 'D', 8);
    
    fig = new rook(1, 'D', 1);
    board.add_figure(fig);
    delete fig;
    
    fig = new rook(1, 'B', 2);
    board.add_figure(fig);
    delete fig;
    
    fig = new king(0, 'C', 1);
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'G', 8);
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'G', 7);
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'H', 8);
    board.add_figure(fig);
    delete fig;
    
}

void test2(chess_board& board)
{
    figure* fig;

    fig = new rook(0, 'D', 8); // Place a rook at D8
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'G', 8); // Place a rook at G8
    board.add_figure(fig);
    delete fig;

    fig = new king(0, 'F', 7); // Place a black king at F7
    board.add_figure(fig);
    delete fig;

    fig = new rook(1, 'F', 8); // Place a rook at F8
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'H', 7); // Place a white king at H7
    board.add_figure(fig);
    delete fig;
}

void test3(chess_board& board)
{
    figure* fig;

    fig = new rook(0, 'C', 8); // Place a rook at C8
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'F', 8); // Place a rook at F8
    board.add_figure(fig);
    delete fig;

    fig = new king(0, 'D', 7); // Place a black king at D7
    board.add_figure(fig);
    delete fig;

    fig = new rook(1, 'D', 8); // Place a rook at D8
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'H', 7); // Place a white king at H7
    board.add_figure(fig);
    delete fig;
}

void test4(chess_board& board)
{
    figure* fig;

    fig = new rook(1, 'E', 5); // Place a rook at E5
    board.add_figure(fig);
    delete fig;

    fig = new king(0, 'F', 7); // Place a black king at F7
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'F', 8); // Place a white king at F8
    board.add_figure(fig);
    delete fig;
}

void test5(chess_board& board)
{
    figure* fig;

    fig = new rook(1, 'H', 2); // Place a white rook at H2
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'A', 1); // Place a black rook at A7
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'D', 5); // Place a white king at D5
    board.add_figure(fig);
    delete fig;

    fig = new queen(0, 'A', 5); // Place a black queen at E5
    board.add_figure(fig);
    delete fig;
}

void test6(chess_board& board)
{
    figure* fig;

    fig = new rook(1, 'C', 4); // Place a white rook at C4
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'F', 6); // Place a black rook at F6
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'D', 5); // Place a white king at D5
    board.add_figure(fig);
    delete fig;

    fig = new king(0, 'E', 7); // Place a black king at E7
    board.add_figure(fig);
    delete fig;

    fig = new queen(0, 'C', 5); // Place a black queen at C5
    board.add_figure(fig);
    delete fig;

    fig = new pawn(1, 'E', 6); // Place a white pawn at E6
    board.add_figure(fig);
    delete fig;
}

void test7(chess_board& board)
{
    figure* fig;

    fig = new pawn(0, 'E', 7);
    board.add_figure(fig);
    delete fig;

    fig = new queen(0, 'D', 6);
    board.add_figure(fig);
    delete fig;

    fig = new queen(1, 'C', 8);
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'B', 7);
    board.add_figure(fig);
    delete fig;

    fig = new king(0, 'D', 7);
    board.add_figure(fig);
    delete fig;
}

void test8(chess_board& board)
{
    figure* fig;

    fig = new king(1, 'H', 8);
    board.add_figure(fig);
    delete fig;

    fig = new pawn(0, 'G', 7);
    board.add_figure(fig);
    delete fig;

    fig = new pawn(0, 'H', 7);
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'A', 8);
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'H', 1);
    board.add_figure(fig);
    delete fig;
    
    fig = new rook(0, 'A', 8);
    board.add_figure(fig);
    delete fig;

    fig = new bishop(1, 'A', 1);
    board.add_figure(fig);
    delete fig;

}

void test9(chess_board& board)
{
    figure* fig;

    fig = new rook(0, 'H', 8);
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'H', 7);
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'A', 8);
    board.add_figure(fig);
    delete fig;
    //
    fig = new rook(1, 'A', 1);
    board.add_figure(fig);
    delete fig;

    fig = new rook(1, 'A', 2);
    board.add_figure(fig);
    delete fig;

    fig = new king(0, 'H', 1);
    board.add_figure(fig);
    delete fig;
}

void test_full_chess_board(chess_board& board)
{
    figure* fig;

    fig = new rook(1, 'A', 1);
    board.add_figure(fig);
    delete fig;

    fig = new knight(1, 'A', 2); 
    board.add_figure(fig);
    delete fig;

    fig = new bishop(1, 'A', 3);
    board.add_figure(fig);
    delete fig;

    fig = new queen(1, 'A', 4);
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'A', 5);
    board.add_figure(fig);
    delete fig;

    fig = new bishop(1, 'A', 6);
    board.add_figure(fig);
    delete fig;

    fig = new knight(1, 'A', 7);
    board.add_figure(fig);
    delete fig;

    fig = new rook(1, 'A', 8);
    board.add_figure(fig);
    delete fig;

    fig = new rook(0, 'H', 8);
    board.add_figure(fig);
    delete fig;

    fig = new knight(1, 'H', 7);
    board.add_figure(fig);
    delete fig;

    fig = new bishop(1, 'H', 6);
    board.add_figure(fig);
    delete fig;

    fig = new queen(1, 'H', 5);
    board.add_figure(fig);
    delete fig;

    fig = new king(1, 'H', 4);
    board.add_figure(fig);
    delete fig;

    fig = new bishop(1, 'H', 3);
    board.add_figure(fig);
    delete fig;

    fig = new knight(1, 'H', 2);
    board.add_figure(fig);
    delete fig;

    fig = new rook(1, 'H', 1);
    board.add_figure(fig);
    delete fig;

    for (int i = 1; i <= 8; ++i)
    {
        fig = new pawn(1, 'B', i);
        board.add_figure(fig);
        delete fig;
    }

    for (int i = 1; i <= 8; ++i)
    {
        fig = new pawn(0, 'G', i);
        board.add_figure(fig);
        delete fig;
    }
}

int main()
{
    chess_board board;

    //figure_adding(board);

    
    
    //test1(board); //checkmate for white king
    //test2(board); //not checkmate
    //test3(board); //not checkmate
    //test4(board); //illegal move
    //test5(board); //not checkmate
    //test6(board); //not checkmate
    //test7(board); //checkmate for black king
    //test8(board); //checkmate for white king
    //test9(board);
    test_full_chess_board(board);
    board.draw();

    analizer first(board);

    //first.analize_lvl_1();

    first.analize_lvl_1();

}
