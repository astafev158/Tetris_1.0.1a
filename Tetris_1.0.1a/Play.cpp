#include "Play.h"


bool Play::GameTetris(sf::RenderWindow &window) { // логический аналог ф-ции main используется для возможности перезагрузки игры
	srand((unsigned int)time(NULL));
	GameZone field[10][22]; // объявляем массив поля
	GetMemory Memory; // объявляем переменную памяти
	for (int i = 0; i < 10; i++) { //Если не использовать изночально будет отображаться экран заполненный 12ую строками+ посчитает очки, которые надо будет отнять
		for (int j = 0; j < 22; j++) {
			field[i][j].setOff(); // ставим клеткам пустой статус
		}
	}

	window.setVerticalSyncEnabled(true); // включаем вертикальную синхранизацию для устранение подёргивания изображения
	window.setFramerateLimit(10); // ограничение частоты кадров
	Block theBlock(randomBlock()); // создаём объект класса Block
	theBlock.initBlock(field); // вызвали инициализацию
	int acceleration = 0;
	int score = 0;


	while (window.isOpen()) { // Бесконечный цикл, пока окно открыто
		CheckAndCreate create, check;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) //если нажат крестик(закрыть)
				window.close(); // прощай программа
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { return true; }//если таб, то перезагружаем игру
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return false; }//если эскейп, то выходим из игры

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // действие при нажатии левой клавиши
			theBlock.update(field, LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // действие при нажатии правой клавиши
			theBlock.update(field, RIGHT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // действие при нажатии клавиши вверх
			theBlock.turn(field);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // действие при нажатии клавиши вниз
			acceleration = 0; // замедление после отпускания
			check.frameCheck(score, theBlock, field, Memory, window);
		}

		if (acceleration == GAME_SPEED) { //наростание и затухание скорости(рывки)
			acceleration = 0;
			check.frameCheck(score, theBlock, field, Memory, window);
		}
		else {
			acceleration++;
		}

		window.clear(sf::Color::Black); //очистка окна
		create.drawField(field, window); //рисует объект поле

		window.display(); // выводит на дисплей
		
	}
	return 0;
}

void Play::RunGame(sf::RenderWindow &window) { //запускает игру
	while (GameTetris(window)) GameTetris(window); //перезагрузка игры
}
