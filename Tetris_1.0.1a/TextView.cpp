#include "TextView.h"

void TextView::vivvod(sf::RenderWindow & window, float a, float b, std::string str)
{
	
	sf::Font font;
	if (!font.loadFromFile("resurse/FontFile.ttf")) {
		std::cout << "Error loading file" << std::endl; // �������� ������������ ��� ������ ���-��� ������� � ��������=)
		system("pause");
	}
	sf::Text text; // ���������� ������
	text.setPosition(a, b); // ��������� �������
	text.setFont(font); // �������� �����
	text.setString(str); // ����� �� �����
	window.draw(text);

}

