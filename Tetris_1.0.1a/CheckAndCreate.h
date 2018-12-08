#pragma once
#include "GameZone.h"
#include "GetMemory.h"
#include "Block.h"
#include "Constants.h"
#include <SFML/Graphics.hpp> // ���������� ��� ������ � ��������
#include "Play.h"
bool menu(sf::RenderWindow & window);

class CheckAndCreate
{
public:
	bool checkGameOver(GameZone field[10][22]); // �������� ������� ��������� ����
	int updateField(GameZone field[10][22], GetMemory Memory);//������� �������� � ���������� ����������� ������� + ����������� ����������
	void frameCheck(int& score, Block& theBlock, GameZone field[10][22], GetMemory Memory, sf::RenderWindow& window); // �������� ������ �� ���������
	void drawField(GameZone field[10][22], sf::RenderWindow& window); //������� �������� ����

	
};

