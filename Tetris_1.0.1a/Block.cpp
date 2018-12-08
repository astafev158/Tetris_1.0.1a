#include "Block.h" // ������ � �������

BlockType randomBlock() { // ���������� ��������� ���� �� enum BlockType
	return static_cast<BlockType>(rand() % 7); //����� ���������� ���������� ���� ������
}

Block::Block(BlockType type) {
	reset(type); 
}

bool Block::testField(int coordinatePair[2]) { // ����������� �������� ����� �����, ��� ��� ������� ����� ������ �������� ����� ��� ����������� ��������� �� �����
	if (coordinatePair[0] >= 10 or coordinatePair[0] < 0 or coordinatePair[1] >= 22 or coordinatePair[1] < 0)
		return false;
	return true;
}

bool Block::testField(int coordinatePair[2], �ontrol button) { // ����������� ���� ������������ ��� ������ ����
	int updateX, updateY;
	if (button == DOWN) { // ���� ������ ������� ����
		updateX = 0;
		updateY = 1;
	}
	else if (button == RIGHT) { // ���� ������ ������� ������
		updateX = 1;
		updateY = 0;
	}
	else if (button == LEFT) { // ���� ������ ������� �����
		updateX = -1;
		updateY = 0;
	}
	else if (button == UP) { // ���� ������ ������� �����
		updateX = 0;
		updateY = -1;
	}
	// �� ������� �� ������� ����, ��������� ��  �� ��� ����� ������������
	if (coordinatePair[0] + updateX >= 10 or coordinatePair[0] + updateX < 0 or coordinatePair[1] + updateY >= 22 or coordinatePair[1] + updateY < 0)
		return false;
	return true;
}

void Block::reset(BlockType type) { // �� ��������� ��������� ���������� type ������ ����� �� ������ enum BlockType
		//���������� 4-����� �������� ������, ����� �������� (O-����). �.�. � ����� ������� ��� �������� ������������ ������
	if (type == I_BLOCK) { //I_BLOCK
		coordinates[0][0] = 3;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 1;

		coordinates[2][0] = 5;
		coordinates[2][1] = 1;

		coordinates[3][0] = 4;
		coordinates[3][1] = 1;
	}
	else if (type == J_BLOCK) { //J_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 0;

		coordinates[1][0] = 6;
		coordinates[1][1] = 1;

		coordinates[2][0] = 6;
		coordinates[2][1] = 0;

		coordinates[3][0] = 5;
		coordinates[3][1] = 0;
	}
	else if (type == L_BLOCK) { //L_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 0;

		coordinates[2][0] = 6;
		coordinates[2][1] = 1;

		coordinates[3][0] = 5;
		coordinates[3][1] = 1;
	}
	else if (type == O_BLOCK) { //O_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 0;

		coordinates[1][0] = 5;
		coordinates[1][1] = 0;

		coordinates[2][0] = 4;
		coordinates[2][1] = 1;

		coordinates[3][0] = 5;
		coordinates[3][1] = 1;
	}
	else if (type == S_BLOCK) {//S_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 0;

		coordinates[2][0] = 5;
		coordinates[2][1] = 0;

		coordinates[3][0] = 5;
		coordinates[3][1] = 1;
	}
	else if (type == T_BLOCK) {//T_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 0;

		coordinates[1][0] = 5;
		coordinates[1][1] = 1;

		coordinates[2][0] = 6;
		coordinates[2][1] = 0;

		coordinates[3][0] = 5;
		coordinates[3][1] = 0;
	}

	else { //Z_BLOCK
		coordinates[0][0] = 4;
		coordinates[0][1] = 1;

		coordinates[1][0] = 6;
		coordinates[1][1] = 0;

		coordinates[2][0] = 5;
		coordinates[2][1] = 1;

		coordinates[3][0] = 5;
		coordinates[3][1] = 0;
	}
}

void Block::initBlock(GameZone field[10][22]) { // �������������� �����
	for (int i = 0; i < 4; i++) {
		field[coordinates[i][0]][coordinates[i][1]].setOn();
	}
}

bool Block::update(GameZone field[10][22], �ontrol button) {
	// ���������� false, ���� ������ ��������� �� ���� ��� �� ������ ������. ������������ ��� �������� ������� � ���������� ���������� �����
	//+ �������� ������ 

	int updateX, updateY;
	if (button == DOWN) { // ���� ������ ������� ����, ������ ��������
		updateX = 0;
		updateY = 1;
	}
	else if (button == RIGHT) { // ���� ������ ������� ������, ��������� �������� �� ��������� ���������
		updateX = 1;
		updateY = 0;
	}
	else if (button == LEFT) { // ���� ������ ������� �����, ��������� �������� �� ��������� ���������
		updateX = -1;
		updateY = 0;
	}
	else if (button == UP) { // ���� ������ ������� �����, ��������� �������� �� ��������� ���������
		updateX = 0;
		updateY = -1;
	}

	for (int i = 0; i < 4; i++) {
		field[coordinates[i][0]][coordinates[i][1]].setOff();
	}

	bool doUpdate = true;//true -���������, false - ��������� ��� ����
	for (int j = 0; j < 4; j++) {
		if (field[coordinates[j][0] + updateX][coordinates[j][1] + updateY].getStatusOn() or !testField(coordinates[j], button)) {
			doUpdate = false;
		}
	}
	if (doUpdate == true) { // ��������� ���������
		for (int k = 0; k < 4; k++) {
			coordinates[k][0] += updateX; // ������� �������� ������
			coordinates[k][1] += updateY; // �������� ������ ����
		}
	}

	initBlock(field);//�������������� ����
	return doUpdate;
}

bool Block::turn(GameZone field[10][22]) { // ������� ���������� ��������
	int tempCoord[4][2]; // ��������� ������, �������� ������ ������� �����������, �� ��� ������������� ���� � ����� �� ���� ������
	tempCoord[3][0] = coordinates[3][0];
	tempCoord[3][1] = coordinates[3][1];
	for (int i = 0; i < 3; i++) {
		//�������� (x, y) = (y, -x)
		tempCoord[i][0] = coordinates[3][0] + (coordinates[i][1] - coordinates[3][1]);
		tempCoord[i][1] = coordinates[3][1] - (coordinates[i][0] - coordinates[3][0]);
	}

	for (int i = 0; i < 4; i++) {
		field[coordinates[i][0]][coordinates[i][1]].setOff();
	}

	bool doUpdate = true;//true- ��������� ������ , false = �� ��������� �����
	for (int j = 0; j < 4; j++) {
		if (field[tempCoord[j][0]][tempCoord[j][1]].getStatusOn() or !testField(tempCoord[j]))
		{
			doUpdate = false;
		}
	}
	if (doUpdate == true) // 
	{
		for (int k = 0; k < 4; k++) {
			coordinates[k][0] = tempCoord[k][0];
			coordinates[k][1] = tempCoord[k][1];
		}
	}

	initBlock(field);
	return doUpdate;
}

