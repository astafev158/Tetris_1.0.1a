#include "GetMemory.h"
#include "TextView.h"

bool menu(sf::RenderWindow & window) {

	GetMemory Memory; // создаём объект памяти
	
	sf::Texture menuTexture1, menuTexture2; // объекты текстур
	menuTexture1.loadFromFile("resurse/images/111.png"); // загружаем текстуру
	menuTexture2.loadFromFile("resurse/images/333.png"); // загружаем текстуру

	sf::Sprite menu1(menuTexture1), menu2(menuTexture2); // объект спрайтов
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 250); // устанавливаем позицию спрайта 1
	menu2.setPosition(100, 300); // устанавливаем позицию спрайта 2

	while (isMenu) // пока открыто меню
	{
		sf::Event event; // объект события
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) //если нажат крестик(закрыть)
				exit(0); // прощай программа
		}
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(0, 0, 0));

		if (sf::IntRect(0, 200, 1200, 75).contains(sf::Mouse::getPosition(window)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) { menu1.setColor(sf::Color::Blue); menuNum = 1; } // если ткнули мышкой на кнопку 1
		if (sf::IntRect(100, 300, 1200, 75).contains(sf::Mouse::getPosition(window)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) { menu2.setColor(sf::Color::Blue); menuNum = 2; } // если ткнули мышкой на кнопку 2

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))){ // условие нажатие левой кнопкой мыши
			if (menuNum == 1) {  return(true);} // действие при нажатии на кнопку 1 (начать новую игру)
			if (menuNum == 2) {exit(0);} //действие при нажатии на кнопку 2 (выход)
		}

	

	TextView a,b,c,d; // создаем объекты для вывода
	a.vivvod(window,10,10, "Record:"); // выводим слово рекорд
	b.vivvod(window, 60, 10, std::to_string(Memory.GetRekord())); // выводим значение
	c.vivvod(window, 10, 50, "Last Points:");// выводим слово последнии очки
	d.vivvod(window, 80, 50, std::to_string(Memory.GetScoreCurrent())); // выводим значение

	window.draw(menu1);
	window.draw(menu2);
	window.display(); // выводим на экран
	}
	return 0;
}

