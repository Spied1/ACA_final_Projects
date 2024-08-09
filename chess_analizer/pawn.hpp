#pragma once
#include"figure.hpp"

class pawn : public figure
{
public:
	pawn() = delete;

	pawn(bool color, char cord_x, int cord_y);
};