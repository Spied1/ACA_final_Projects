#pragma once
#include"figure.hpp"

class knight : public figure
{
public:
	knight() = delete;

	knight(bool color, char cord_x, int cord_y);
};