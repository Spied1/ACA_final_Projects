#pragma once
#include<string>
#include<cctype>

class figure
{
private:
	bool m_color;
	char m_cord_x;
	int m_cord_y;
	std::string m_name;
public:
	figure() = delete;

	figure(std::string name, bool color, char cord_x, int cord_y);

	std::string get_n_c();

	int get_x();

	int get_y();
};