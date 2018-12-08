#pragma once
#include <stdio.h>
#include<iostream>
#include <fstream>
#include <stdlib.h> // используем для функции srand(time(null))
#include <SFML/Graphics.hpp> // библиотека для работы с графикой
#include <SFML/Audio.hpp> // для музыки
#include "menu.h"
#include "GameZone.h"
#include "Block.h"
#include "Constants.h"
#include "checkAndCreate.h"
#include "Play.h"
#include "music.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // отключаем консоль

