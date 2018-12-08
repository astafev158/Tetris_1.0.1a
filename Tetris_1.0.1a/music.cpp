#include "music.h"



void music::musics(sf::RenderWindow &window,sf::Sound *sound,sf::SoundBuffer *buffer)
{
	sound->setBuffer(*buffer); // выбираем из буффера
	sound->setLoop(true); // зацикливаем музыку
	sound->play(); // воспроизводим
}


