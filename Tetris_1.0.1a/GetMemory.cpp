#include "GetMemory.h"

	int GetMemory::GetRekord() { //������� ������ ������� �� �������� 
		std::ifstream fin("resurse/myScore.txt"); // (����� �� ���������� ��� �����)
		//������ �� ������ ������ �������� ���� � ����� ������ ��������� ������
		if (!fin.is_open()) // ���� ���� �� ������
			std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
		//����� �� ������ ������ �������� ���� � ����� ������ ��������� ������
		else {
			fin >> buff; // ������� ������ ����� �� �����
			fin.close();
		}
		Rekord = atoi(buff);
		return Rekord;// ���������� ������
	}

	int  GetMemory::GetScoreCurrent() { //������� ������ ������� ����� �� �������� 
		std::ifstream fin("resurse/myScoreCurrent.txt"); // (����� �� ���������� ��� �����)
		//������ �� ������ ������ �������� ���� � ����� ������ ��������� ������
		if (!fin.is_open()) // ���� ���� �� ������
			std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
		//����� �� ������ ������ �������� ���� � ����� ������ ��������� ������
		else {
			fin >> buff; // ������� ������ ����� �� �����
			fin.close();
		}
		Score = atoi(buff);
		return Score;// ���������� ������� ����
	}

	void GetMemory::WriteScore(int score) { //������� ������ ������ �� ����� � ��������
		setlocale(LC_ALL, "rus");
		std::ifstream fin("resurse/myScore.txt");
		if (!fin.is_open()) // ���� ���� �� ������
			std::ofstream on("resurse/myScore.txt"); //������ ��� � ������ ����������
		else
		{
			if (fin.peek() == EOF) // ���� ���� ������
				buff[0] = 0;
			else
				fin >> buff; // ������� ������ ����� �� �����
			fin.close();
		}
		if (atoi(buff) < score * 100) {
			std::ofstream fout("resurse/myScore.txt");
			fout << score * 100; // ������ ������ � ����
			fout.close(); // ��������� ����
		}
		std::ofstream fout("resurse/myScoreCurrent.txt");
		fout << score * 100; // ������ ������ � ����
		fout.close(); // ��������� ����
	}

