#pragma once
#include "checkAndCreate.h"
class Play
{
public:
	bool GameTetris(sf::RenderWindow &window); // логический аналог ф-ции main используется для возможности перезагрузки игры
	void RunGame(sf::RenderWindow &window); //запускает игру

};

