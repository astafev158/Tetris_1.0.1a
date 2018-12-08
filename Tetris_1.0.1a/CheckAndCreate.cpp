#include "CheckAndCreate.h"


bool CheckAndCreate:: checkGameOver(GameZone field[10][22]) { // �������� ������� ��������� ����
	for (int i = 0; i < 10; i++) {
		if (field[i][1].getStatusOn()) {
			return true;
		}
	}
	return false;
}

int CheckAndCreate::updateField(GameZone field[10][22], GetMemory Memory) {//������� �������� � ���������� ����������� ������� + ����������� ����������

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
						if (field[k][j - 1].getStatusOn()) { // ���� �� ����������� ���� ������� ������
							field[k][j - 1].setOff();
							field[k][j].setOn();
						}
						else
							field[k][j].setOff(); // ������ ���� �������
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

void CheckAndCreate::frameCheck(int& score, Block& theBlock, GameZone field[10][22], GetMemory Memory, sf::RenderWindow& window) { // �������� ������ �� ���������

	if (!theBlock.update(field, DOWN)) {
		score += updateField(field, Memory);
		if (checkGameOver(field)) { // �������� �� ��������� ��������� ����

			Memory.WriteScore(score);
			drawField(field, window); //������ ������ ����
			menu(window);// �������� ����
			Play play;
			play.RunGame(window);
		}
		theBlock.reset(randomBlock()); // ��������� ����
		theBlock.initBlock(field); // �������������� ���
	}
}

void CheckAndCreate::drawField(GameZone field[10][22], sf::RenderWindow& window) { //������� �������� ����
	sf::RectangleShape rectangle(sf::Vector2f(WINDOWS_SIZE, WINDOWS_SIZE)); // ����������� �������������� �� ��������� SFML
	float xPos = 0;
	float yPos = -2 * WINDOWS_SIZE;// ��� ������ "���������" ��� ��������� ������

	for (int j = 0; j < 22; j++) {
		xPos = 0;
		for (int i = 0; i < 10; i++) {
			if (field[i][j].getStatusOn()) { //��������� �����������
				rectangle.setFillColor(sf::Color(255, 0, 0)); // ������������� ���� ��������������
				rectangle.setPosition(xPos, yPos); // ������������� ������� ��������������
				window.draw(rectangle); // ������� �� �����
			}
			xPos += WINDOWS_SIZE;
		}
		yPos += WINDOWS_SIZE;
	}
}