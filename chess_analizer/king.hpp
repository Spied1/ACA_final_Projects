#pragma once
#include"figure.hpp"

class king : public figure
{
public:
	king() = delete;

	king(bool color, char cord_x, int cord_y);

};