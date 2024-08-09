#include"analizer.hpp"

analizer::analizer(chess_board board)
{
    m_chess_board = board.get_board();

    for (int i = 0; i < m_chess_board.size(); ++i)
    {
        for (int j = 0; j < m_chess_board[i].size(); ++j)
        {
            if (m_chess_board[i][j] == "KW")
            {
                KW = { i, j };
            }
            if (m_chess_board[i][j] == "KB")
            {
                KB = { i, j };
            }
        }
    }
}

bool analizer::isValidMove(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool analizer::checkLinearMoves(int x, int y, const std::string& piece, const std::string& targetKing)
{
    std::vector<std::vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (auto& dir : directions)
    {
        int nx = x + dir[0], ny = y + dir[1];
        while (isValidMove(nx, ny))
        {
            if (m_chess_board[nx][ny] == targetKing)
            {
                //std::cout << "check with " << piece << "->" << targetKing << std::endl;
                return true;
            }
            else if (m_chess_board[nx][ny] != "__")
            {
                break;
            }
            nx += dir[0];
            ny += dir[1];
        }
    }
    return false;
}

bool analizer::checkDiagonalMoves(int x, int y, const std::string& piece, const std::string& targetKing)
{
    std::vector<std::vector<int>> directions = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for (auto& dir : directions)
    {
        int nx = x + dir[0], ny = y + dir[1];
        while (isValidMove(nx, ny))
        {
            if (m_chess_board[nx][ny] == targetKing)
            {
                //std::cout << "check with " << piece << "->" << targetKing << std::endl;
                return true;
            }
            else if (m_chess_board[nx][ny] != "__")
            {
                break;
            }
            nx += dir[0];
            ny += dir[1];
        }
    }
    return false;
}

bool analizer::checkKnightMoves(int x, int y, const std::string& piece, const std::string& targetKing)
{
    std::vector<std::vector<int>> moves = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
    for (auto& move : moves)
    {
        int nx = x + move[0], ny = y + move[1];
        if (isValidMove(nx, ny) && m_chess_board[nx][ny] == targetKing)
        {
            //std::cout << "check with " << piece << "->" << targetKing << std::endl;
            return true;
        }
    }
    return false;
}

bool analizer::analize_for_check()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            // Check each piece type
            if (m_chess_board[i][j] == "PW" && i < 7) // White pawn
            {
                if (j > 0 && m_chess_board[i + 1][j - 1] == "KB") return true;
                if (j < 7 && m_chess_board[i + 1][j + 1] == "KB") return true;
            }
            else if (m_chess_board[i][j] == "PB" && i > 0) // Black pawn
            {
                if (j > 0 && m_chess_board[i - 1][j - 1] == "KW") return true;
                if (j < 7 && m_chess_board[i - 1][j + 1] == "KW") return true;
            }
            else if (m_chess_board[i][j] == "KW" || m_chess_board[i][j] == "KB") // Kings
            {
                for (int x = -1; x <= 1; ++x)
                {
                    for (int y = -1; y <= 1; ++y)
                    {
                        if (x != 0 || y != 0)
                        {
                            if (isValidMove(i + x, j + y) && m_chess_board[i + x][j + y] == "KB") return true;
                        }
                    }
                }
            }
            else if (m_chess_board[i][j] == "RW") // Rooks
            {
                if (checkLinearMoves(i, j, m_chess_board[i][j], "KB")) return true;
            }
            else if (m_chess_board[i][j] == "RB")
            {
                if (checkLinearMoves(i, j, m_chess_board[i][j], "KW")) return true;
            }

            else if (m_chess_board[i][j] == "BW") // Bishops
            {
                if (checkDiagonalMoves(i, j, m_chess_board[i][j], "KB")) return true;
            }
            else if (m_chess_board[i][j] == "BB")
            {
                if (checkDiagonalMoves(i, j, m_chess_board[i][j], "KW")) return true;
            }

            else if (m_chess_board[i][j] == "NW") // Knights
            {
                if (checkKnightMoves(i, j, m_chess_board[i][j], "KB")) return true;
            }
            else if (m_chess_board[i][j] == "NB")
            {
                if (checkKnightMoves(i, j, m_chess_board[i][j], "KW")) return true;
            }

            else if (m_chess_board[i][j] == "QW") // Queens
            {
                if (checkLinearMoves(i, j, m_chess_board[i][j], "KB")) return true;
            }
            else if (m_chess_board[i][j] == "QB")
            {
                if (checkLinearMoves(i, j, m_chess_board[i][j], "KW")) return true;
            }
        }
    }
    return false;
}


std::pair<bool, bool> analizer::analizer_check_mate()
{
    std::pair<bool, bool> state = { false, false };
    std::vector<std::vector<int>> moves = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    // Check for white king
    int counter = 0;
    int possible_m = 0;
    int newX;
    int newY;
    m_chess_board[KB.first][KB.second] = "__";
    for (auto& move : moves)
    {
        
        newX = KW.first + move[0];
        newY = KW.second + move[1];

        if (isValidMove(newX, newY))
        {
            //std::cout << "kwk: " << newX + 1 << " " << newY + 1 << std::endl;
            possible_m++;
            std::swap(m_chess_board[KW.first][KW.second], m_chess_board[newX][newY]);
            if (analize_for_check()) // Checking if the king is in check
            {
                counter++;//meme
            }
            std::swap(m_chess_board[KW.first][KW.second], m_chess_board[newX][newY]); // Restore board
        }
    }
    m_chess_board[KB.first][KB.second] = "KB";
    m_chess_board[KW.first][KW.second] = "__";

    if (counter >= possible_m)
    {
        state.first = true; // White king is in checkmate
    }

    // Reset counter and possible moves for black king check
    counter = 0;
    possible_m = 0;

    
    // Check for black king
    for (auto& move : moves)
    {
        int newX = KB.first + move[0];
        int newY = KB.second + move[1];

        if (isValidMove(newX, newY))
        {
            possible_m++;
            std::swap(m_chess_board[KB.first][KB.second], m_chess_board[newX][newY]);
            if (analize_for_check()) // Checking if the king is in check
            {
                counter++;
            }
            std::swap(m_chess_board[KB.first][KB.second], m_chess_board[newX][newY]); // Restore board
        }
    }
    m_chess_board[KW.first][KW.second] = "KW";
    
    if (counter >= possible_m)
    {
        state.second = true; // Black king is in checkmate
    }

    return state;
}

void analizer::analize_lvl_1()
{
    std::pair<bool, bool> state = analizer_check_mate();

    if (state.first && KW.first != -1)
    {
        std::cout << std::endl << "checkmate for king white" << std::endl;
    }

    if (state.second && KB.first != -1)
    {
        std::cout << std::endl << "checkmate for black king" << std::endl;
    }
}
