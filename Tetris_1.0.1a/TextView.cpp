#include "TextView.h"

void TextView::vivvod(sf::RenderWindow & window, float a, float b, std::string str)
{
	
	sf::Font font;
	if (!font.loadFromFile("resurse/FontFile.ttf")) {
		std::cout << "Error loading file" << std::endl; // наврядли пользователь это увидит так-как кансоль я отключил=)
		system("pause");
	}
	sf::Text text; // определяем объект
	text.setPosition(a, b); // указываем позицию
	text.setFont(font); // выбираем шрифт
	text.setString(str); // текст на вывод
	window.draw(text);

}

