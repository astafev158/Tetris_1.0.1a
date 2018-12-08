#pragma once
#include "GameZone.h"
#include "GetMemory.h"
#include "Block.h"
#include "Constants.h"
#include <SFML/Graphics.hpp> // библиотека для работы с графикой
#include "Play.h"
bool menu(sf::RenderWindow & window);

class CheckAndCreate
{
public:
	bool checkGameOver(GameZone field[10][22]); // проверка условий окончания игры
	int updateField(GameZone field[10][22], GetMemory Memory);//Функция проверки и обновления завершенных строкок + возвращения результата
	void frameCheck(int& score, Block& theBlock, GameZone field[10][22], GetMemory Memory, sf::RenderWindow& window); // проверка кадров на остановку
	void drawField(GameZone field[10][22], sf::RenderWindow& window); //функция создания поля

	
};

