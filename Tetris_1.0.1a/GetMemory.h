#pragma once
#include<iostream>
#include <fstream>

class GetMemory
{
private:
	char buff[50]; // ����� �������������� �������� ������
	int Rekord = 0;
	int Score = 0;

public:
	int GetRekord();
	int GetScoreCurrent();
	void WriteScore(int score);	
};

