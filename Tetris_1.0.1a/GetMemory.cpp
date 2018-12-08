#include "GetMemory.h"

	int GetMemory::GetRekord() { //функция чтения рекорда из блокнота 
		std::ifstream fin("resurse/myScore.txt"); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)
		//начало не совсем нужной проверки файл в любом случае создаться раньше
		if (!fin.is_open()) // если файл не открыт
			std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
		//конец не совсем нужной проверки файл в любом случае создаться раньше
		else {
			fin >> buff; // считали первое слово из файла
			fin.close();
		}
		Rekord = atoi(buff);
		return Rekord;// возвращаем рекорд
	}

	int  GetMemory::GetScoreCurrent() { //функция чтения текущих очков из блокнота 
		std::ifstream fin("resurse/myScoreCurrent.txt"); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)
		//начало не совсем нужной проверки файл в любом случае создаться раньше
		if (!fin.is_open()) // если файл не открыт
			std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
		//конец не совсем нужной проверки файл в любом случае создаться раньше
		else {
			fin >> buff; // считали первое слово из файла
			fin.close();
		}
		Score = atoi(buff);
		return Score;// возвращаем текущии очки
	}

	void GetMemory::WriteScore(int score) { //функция записи данных об очках и рекордах
		setlocale(LC_ALL, "rus");
		std::ifstream fin("resurse/myScore.txt");
		if (!fin.is_open()) // если файл не открыт
			std::ofstream on("resurse/myScore.txt"); //создаём его в случае отсутствия
		else
		{
			if (fin.peek() == EOF) // если файл пустой
				buff[0] = 0;
			else
				fin >> buff; // считали первое слово из файла
			fin.close();
		}
		if (atoi(buff) < score * 100) {
			std::ofstream fout("resurse/myScore.txt");
			fout << score * 100; // запись строки в файл
			fout.close(); // закрываем файл
		}
		std::ofstream fout("resurse/myScoreCurrent.txt");
		fout << score * 100; // запись строки в файл
		fout.close(); // закрываем файл
	}

