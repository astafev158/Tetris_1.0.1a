#pragma once
#include <SFML/Graphics.hpp> // библиотека для работы с графикой
#include <iostream>

class TextView // класс вывода текста на экран
{
public:
	void vivvod(sf::RenderWindow & window, float a, float b, std::string str);

};

