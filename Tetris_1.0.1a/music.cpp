#include "music.h"



void music::musics(sf::RenderWindow &window,sf::Sound *sound,sf::SoundBuffer *buffer)
{
	sound->setBuffer(*buffer); // �������� �� �������
	sound->setLoop(true); // ����������� ������
	sound->play(); // �������������
}


