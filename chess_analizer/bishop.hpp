#pragma once
#include"figure.hpp"

class bishop : public figure
{
public:
	bishop() = delete;

	bishop(bool color, char cord_x, int cord_y);

};