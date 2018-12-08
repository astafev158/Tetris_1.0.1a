#include "Header.h"


int main(){
	sf::RenderWindow window(sf::VideoMode(10 * WINDOWS_SIZE, 20 * WINDOWS_SIZE), "Tetris"); // создаём окно
	// созадъем объекты классов
	music music;
	Play play; 

	// создаём переменные
	sf::SoundBuffer buffer; //создаем переменную буффер
	sf::Sound sound; // создаём переменную звук

	//загружаем звук из файла
    buffer.loadFromFile("resurse/8bit.ogg"); // тут загружаем в буфер музыку

	//вызываем методы объектов
	music.musics(window, &sound, &buffer); // запускаем музыку
	menu(window);// вызываем меню
	play.RunGame(window); // запускаем игру

	return 0;
}

