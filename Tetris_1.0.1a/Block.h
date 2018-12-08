#pragma once
#include "GameZone.h"
#include <stdlib.h>
// перечисляемые типы
enum BlockType { I_BLOCK, J_BLOCK, L_BLOCK, O_BLOCK, S_BLOCK, T_BLOCK, Z_BLOCK }; // храним перечисление возможных кирпичиков
enum Сontrol { UP, RIGHT, DOWN, LEFT }; // храним варианты управления
BlockType randomBlock();

class Block // Работа с блоками
{
private:
	int coordinates[4][2];
public:
	Block(BlockType type);
	bool testField(int coordinatePair[2]); // ограничваем вращение фигур внизу, так как клавиша вверх делает смешение вверх для визуального переворта на месте
	bool testField(int coordinatePair[2], Сontrol button); // ограничение воли пользователя для границ поля
	void reset(BlockType type); // на основании рандомной переменной type делаем выбор из нашего enum BlockType
	void initBlock(GameZone field[10][22]); // инициализируем блоки
	bool update(GameZone field[10][22], Сontrol button); // Возвращает false, если фигура находится на полу или на другой фигуре. Используется для принятия решение о блокировки управления блока+ движение фигуры 
	bool turn(GameZone field[10][22]);// функция реализации вращения
	
};

