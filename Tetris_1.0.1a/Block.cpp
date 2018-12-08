#include "Block.h" // –абота с блоками

BlockType randomBlock() { // √енерируем случайный блок из enum BlockType
	return static_cast<BlockType>(rand() % 7); //€вное допустимое приведение типа данных
}

Block::Block(BlockType type) {
	reset(type); 
}

bool Block::testField(int coordinatePair[2]) { // ограничваем вращение фигур внизу, так как клавиша вверх делает смешение вверх дл€ визуального переворта на месте
	if (coordinatePair[0] >= 10 or coordinatePair[0] < 0 or coordinatePair[1] >= 22 or coordinatePair[1] < 0)
		return false;
	return true;
}

bool Block::testField(int coordinatePair[2], —ontrol button) { // ограничение воли пользовател€ дл€ границ пол€
	int updateX, updateY;
	if (button == DOWN) { // если нажата клавиша вниз
		updateX = 0;
		updateY = 1;
	}
	else if (button == RIGHT) { // если нажата клавиша вправо
		updateX = 1;
		updateY = 0;
	}
	else if (button == LEFT) { // если нажата клавиша влево
		updateX = -1;
		updateY = 0;
	}
	else if (button == UP) { // если нажата клавиша вверх
		updateX = 0;
		updateY = -1;
	}
	// не выходим за границы пол€, насколько бы  не был упр€м пользователь
	if (coordinatePair[0] + updateX >= 10 or coordinatePair[0] + updateX < 0 or coordinatePair[1] + updateY >= 22 or coordinatePair[1] + updateY < 0)
		return false;
	return true;
}

void Block::reset(BlockType type) { // на основании рандомной переменной type делаем выбор из нашего enum BlockType
		// оордината 4-центр вращени€ фигуры, кроме квадрата (O-блок). “.к. у фигры квадрат нет симетрии относительно блоков
	if (type == I_BLOCK) { //I_BLOCK
		coordinates[0][0] = 3;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 1;

		coordinates[2][0] = 5;
		coordinates[2][1] = 1;

		coordinates[3][0] = 4;
		coordinates[3][1] = 1;
	}
	else if (type == J_BLOCK) { //J_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 0;

		coordinates[1][0] = 6;
		coordinates[1][1] = 1;

		coordinates[2][0] = 6;
		coordinates[2][1] = 0;

		coordinates[3][0] = 5;
		coordinates[3][1] = 0;
	}
	else if (type == L_BLOCK) { //L_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 0;

		coordinates[2][0] = 6;
		coordinates[2][1] = 1;

		coordinates[3][0] = 5;
		coordinates[3][1] = 1;
	}
	else if (type == O_BLOCK) { //O_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 0;

		coordinates[1][0] = 5;
		coordinates[1][1] = 0;

		coordinates[2][0] = 4;
		coordinates[2][1] = 1;

		coordinates[3][0] = 5;
		coordinates[3][1] = 1;
	}
	else if (type == S_BLOCK) {//S_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 0;

		coordinates[2][0] = 5;
		coordinates[2][1] = 0;

		coordinates[3][0] = 5;
		coordinates[3][1] = 1;
	}
	else if (type == T_BLOCK) {//T_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 0;

		coordinates[1][0] = 5;
		coordinates[1][1] = 1;

		coordinates[2][0] = 6;
		coordinates[2][1] = 0;

		coordinates[3][0] = 5;
		coordinates[3][1] = 0;
	}

	else { //Z_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 0;

		coordinates[2][0] = 5;
		coordinates[2][1] = 1;

		coordinates[3][0] = 5;
		coordinates[3][1] = 0;
	}
}

void Block::initBlock(GameZone field[10][22]) { // инициализируем блоки
	for (int i = 0; i < 4; i++) {
		field[coordinates[i][0]][coordinates[i][1]].setOn();
	}
}

bool Block::update(GameZone field[10][22], —ontrol button) {
	// ¬озвращает false, если фигура находитс€ на полу или на другой фигуре. »спользуетс€ дл€ прин€ти€ решение о блокировки управлени€ блока
	//+ движение фигуры 

	int updateX, updateY;
	if (button == DOWN) { // если нажата клавиша вниз, делаем действи€
		updateX = 0;
		updateY = 1;
	}
	else if (button == RIGHT) { // если нажата клавиша вправо, принимаем действи€ по изменению координат
		updateX = 1;
		updateY = 0;
	}
	else if (button == LEFT) { // если нажата клавиша влево, принимаем действи€ по изменению координат
		updateX = -1;
		updateY = 0;
	}
	else if (button == UP) { // если нажата клавиша вверх, принимаем действи€ по изменению координат
		updateX = 0;
		updateY = -1;
	}

	for (int i = 0; i < 4; i++) {
		field[coordinates[i][0]][coordinates[i][1]].setOff();
	}

	bool doUpdate = true;//true -обновл€ем, false - оставл€ем как есть
	for (int j = 0; j < 4; j++) {
		if (field[coordinates[j][0] + updateX][coordinates[j][1] + updateY].getStatusOn() or !testField(coordinates[j], button)) {
			doUpdate = false;
		}
	}
	if (doUpdate == true) { // провер€ем изменени€
		for (int k = 0; k < 4; k++) {
			coordinates[k][0] += updateX; // боковое смещение фигуры
			coordinates[k][1] += updateY; // смешение фигуры вниз
		}
	}

	initBlock(field);//инициализируем блок
	return doUpdate;
}

bool Block::turn(GameZone field[10][22]) { // функци€ реализации вращени€
	int tempCoord[4][2]; // временный массив, возможно стоило сделать динамически, но дл€ читабельности кода € этого не стал делать
	tempCoord[3][0] = coordinates[3][0];
	tempCoord[3][1] = coordinates[3][1];
	for (int i = 0; i < 3; i++) {
		//¬ращение (x, y) = (y, -x)
		tempCoord[i][0] = coordinates[3][0] + (coordinates[i][1] - coordinates[3][1]);
		tempCoord[i][1] = coordinates[3][1] - (coordinates[i][0] - coordinates[3][0]);
	}

	for (int i = 0; i < 4; i++) {
		field[coordinates[i][0]][coordinates[i][1]].setOff();
	}

	bool doUpdate = true;//true- обновл€ем фигуру , false = не обновл€ем фигру
	for (int j = 0; j < 4; j++) {
		if (field[tempCoord[j][0]][tempCoord[j][1]].getStatusOn() or !testField(tempCoord[j]))
		{
			doUpdate = false;
		}
	}
	if (doUpdate == true) // 
	{
		for (int k = 0; k < 4; k++) {
			coordinates[k][0] = tempCoord[k][0];
			coordinates[k][1] = tempCoord[k][1];
		}
	}

	initBlock(field);
	return doUpdate;
}

