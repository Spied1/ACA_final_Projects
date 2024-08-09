#include"figure.hpp"

figure::figure(std::string name, bool color, char cord_x, int cord_y)
{
	m_name = name;
	m_color = color;
	m_cord_x = cord_x;
	m_cord_y = cord_y;
}

std::string figure::get_n_c()
{
	return std::string(1, m_name[0]) + (m_color == 0 ? "B" : "W");
}

int figure::get_x()
{
	char cx = std::toupper(m_cord_x);

	return cx - 'A';
}

int figure::get_y()
{
	return m_cord_y - 1;
}