#include "Header.h"


int main(){
	sf::RenderWindow window(sf::VideoMode(10 * WINDOWS_SIZE, 20 * WINDOWS_SIZE), "Tetris"); // ������ ����
	// �������� ������� �������
	music music;
	Play play; 

	// ������ ����������
	sf::SoundBuffer buffer; //������� ���������� ������
	sf::Sound sound; // ������ ���������� ����

	//��������� ���� �� �����
    buffer.loadFromFile("resurse/8bit.ogg"); // ��� ��������� � ����� ������

	//�������� ������ ��������
	music.musics(window, &sound, &buffer); // ��������� ������
	menu(window);// �������� ����
	play.RunGame(window); // ��������� ����

	return 0;
}

