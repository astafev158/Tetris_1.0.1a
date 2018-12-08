#include "CheckAndCreate.h"


bool CheckAndCreate:: checkGameOver(GameZone field[10][22]) { // проверка условий окончания игры
	for (int i = 0; i < 10; i++) {
		if (field[i][1].getStatusOn()) {
			return true;
		}
	}
	return false;
}

int CheckAndCreate::updateField(GameZone field[10][22], GetMemory Memory) {//Функция проверки и обновления завершенных строкок + возвращения результата

	int score = 0;
	bool check;
	int xPos;
	for (int i = 21; i >= 2; i--) {
		xPos = 0;
		check = true;
		while (check == true) {
			if (xPos == 10) {
				score++;
				for (int j = i; j >= 2; j--) {
					for (int k = 0; k < 10; k++) {
						if (field[k][j - 1].getStatusOn()) { // если не выполнилось надо удалить строку
							field[k][j - 1].setOff();
							field[k][j].setOn();
						}
						else
							field[k][j].setOff(); // строку надо удалить
					}
				}
				i++;
			}
			if (!field[xPos][i].getStatusOn())
				check = false;
			xPos++;
		}
	}

	return score * score;
}

void CheckAndCreate::frameCheck(int& score, Block& theBlock, GameZone field[10][22], GetMemory Memory, sf::RenderWindow& window) { // проверка кадров на остановку

	if (!theBlock.update(field, DOWN)) {
		score += updateField(field, Memory);
		if (checkGameOver(field)) { // действия по успешному окончанию игры

			Memory.WriteScore(score);
			drawField(field, window); //рисует объект поле
			menu(window);// вызываем меню
			Play play;
			play.RunGame(window);
		}
		theBlock.reset(randomBlock()); // вызвываем блок
		theBlock.initBlock(field); // инициализируем его
	}
}

void CheckAndCreate::drawField(GameZone field[10][22], sf::RenderWindow& window) { //функция создания поля
	sf::RectangleShape rectangle(sf::Vector2f(WINDOWS_SIZE, WINDOWS_SIZE)); // конструктор прямоугольника по умолчанию SFML
	float xPos = 0;
	float yPos = -2 * WINDOWS_SIZE;// Две клетки "невидимые" для генерации фигуры

	for (int j = 0; j < 22; j++) {
		xPos = 0;
		for (int i = 0; i < 10; i++) {
			if (field[i][j].getStatusOn()) { //проверяем доступность
				rectangle.setFillColor(sf::Color(255, 0, 0)); // устанавливаем цвет прямоугольника
				rectangle.setPosition(xPos, yPos); // устанавливаем позицию прямоугольника
				window.draw(rectangle); // выводим на экран
			}
			xPos += WINDOWS_SIZE;
		}
		yPos += WINDOWS_SIZE;
	}
}