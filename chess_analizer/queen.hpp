#pragma once
#include"figure.hpp"

class queen : public figure
{
public:
	queen() = delete;

	queen(bool color, char cord_x, int cord_y);
};