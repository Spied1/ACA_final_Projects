#pragma once
#include"figure.hpp"

class rook : public figure
{
public:
	rook() = delete;

	rook(bool color, char cord_x, int cord_y);
};