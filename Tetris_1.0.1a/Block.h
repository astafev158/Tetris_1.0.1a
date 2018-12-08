#pragma once
#include "GameZone.h"
#include <stdlib.h>
// ������������� ����
enum BlockType { I_BLOCK, J_BLOCK, L_BLOCK, O_BLOCK, S_BLOCK, T_BLOCK, Z_BLOCK }; // ������ ������������ ��������� ����������
enum �ontrol { UP, RIGHT, DOWN, LEFT }; // ������ �������� ����������
BlockType randomBlock();

class Block // ������ � �������
{
private:
	int coordinates[4][2];
public:
	Block(BlockType type);
	bool testField(int coordinatePair[2]); // ����������� �������� ����� �����, ��� ��� ������� ����� ������ �������� ����� ��� ����������� ��������� �� �����
	bool testField(int coordinatePair[2], �ontrol button); // ����������� ���� ������������ ��� ������ ����
	void reset(BlockType type); // �� ��������� ��������� ���������� type ������ ����� �� ������ enum BlockType
	void initBlock(GameZone field[10][22]); // �������������� �����
	bool update(GameZone field[10][22], �ontrol button); // ���������� false, ���� ������ ��������� �� ���� ��� �� ������ ������. ������������ ��� �������� ������� � ���������� ���������� �����+ �������� ������ 
	bool turn(GameZone field[10][22]);// ������� ���������� ��������
	
};

