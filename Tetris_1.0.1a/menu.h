#include "GetMemory.h"
#include "TextView.h"

bool menu(sf::RenderWindow & window) {

	GetMemory Memory; // ������ ������ ������
	
	sf::Texture menuTexture1, menuTexture2; // ������� �������
	menuTexture1.loadFromFile("resurse/images/111.png"); // ��������� ��������
	menuTexture2.loadFromFile("resurse/images/333.png"); // ��������� ��������

	sf::Sprite menu1(menuTexture1), menu2(menuTexture2); // ������ ��������
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 250); // ������������� ������� ������� 1
	menu2.setPosition(100, 300); // ������������� ������� ������� 2

	while (isMenu) // ���� ������� ����
	{
		sf::Event event; // ������ �������
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) //���� ����� �������(�������)
				exit(0); // ������ ���������
		}
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(0, 0, 0));

		if (sf::IntRect(0, 200, 1200, 75).contains(sf::Mouse::getPosition(window)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) { menu1.setColor(sf::Color::Blue); menuNum = 1; } // ���� ������ ������ �� ������ 1
		if (sf::IntRect(100, 300, 1200, 75).contains(sf::Mouse::getPosition(window)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) { menu2.setColor(sf::Color::Blue); menuNum = 2; } // ���� ������ ������ �� ������ 2

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))){ // ������� ������� ����� ������� ����
			if (menuNum == 1) {  return(true);} // �������� ��� ������� �� ������ 1 (������ ����� ����)
			if (menuNum == 2) {exit(0);} //�������� ��� ������� �� ������ 2 (�����)
		}

	

	TextView a,b,c,d; // ������� ������� ��� ������
	a.vivvod(window,10,10, "Record:"); // ������� ����� ������
	b.vivvod(window, 60, 10, std::to_string(Memory.GetRekord())); // ������� ��������
	c.vivvod(window, 10, 50, "Last Points:");// ������� ����� ��������� ����
	d.vivvod(window, 80, 50, std::to_string(Memory.GetScoreCurrent())); // ������� ��������

	window.draw(menu1);
	window.draw(menu2);
	window.display(); // ������� �� �����
	}
	return 0;
}

