#include "Play.h"


bool Play::GameTetris(sf::RenderWindow &window) { // ���������� ������ �-��� main ������������ ��� ����������� ������������ ����
	srand((unsigned int)time(NULL));
	GameZone field[10][22]; // ��������� ������ ����
	GetMemory Memory; // ��������� ���������� ������
	for (int i = 0; i < 10; i++) { //���� �� ������������ ���������� ����� ������������ ����� ����������� 12�� ��������+ ��������� ����, ������� ���� ����� ������
		for (int j = 0; j < 22; j++) {
			field[i][j].setOff(); // ������ ������� ������ ������
		}
	}

	window.setVerticalSyncEnabled(true); // �������� ������������ ������������� ��� ���������� ����������� �����������
	window.setFramerateLimit(10); // ����������� ������� ������
	Block theBlock(randomBlock()); // ������ ������ ������ Block
	theBlock.initBlock(field); // ������� �������������
	int acceleration = 0;
	int score = 0;


	while (window.isOpen()) { // ����������� ����, ���� ���� �������
		CheckAndCreate create, check;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) //���� ����� �������(�������)
				window.close(); // ������ ���������
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { return true; }//���� ���, �� ������������� ����
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return false; }//���� ������, �� ������� �� ����

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // �������� ��� ������� ����� �������
			theBlock.update(field, LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // �������� ��� ������� ������ �������
			theBlock.update(field, RIGHT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // �������� ��� ������� ������� �����
			theBlock.turn(field);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // �������� ��� ������� ������� ����
			acceleration = 0; // ���������� ����� ����������
			check.frameCheck(score, theBlock, field, Memory, window);
		}

		if (acceleration == GAME_SPEED) { //���������� � ��������� ��������(�����)
			acceleration = 0;
			check.frameCheck(score, theBlock, field, Memory, window);
		}
		else {
			acceleration++;
		}

		window.clear(sf::Color::Black); //������� ����
		create.drawField(field, window); //������ ������ ����

		window.display(); // ������� �� �������
		
	}
	return 0;
}

void Play::RunGame(sf::RenderWindow &window) { //��������� ����
	while (GameTetris(window)) GameTetris(window); //������������ ����
}
