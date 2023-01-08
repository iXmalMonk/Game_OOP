#ifndef _MAIN_H
#define _MAIN_H

#include <fstream>
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <Windows.h>

using namespace sf;
using namespace std;

// C
#define COLOR_BLACK Color(0, 0, 0, 255)
#define COLOR_GRAY Color(50, 50, 50, 255)
#define COLOR_GREEN_TRANSPARENT Color(0, 255, 0, 155)
#define COLOR_RED Color(255, 0, 0, 255)
#define COLOR_RED_TRANSPARENT Color(255, 0, 0, 155)
#define COLOR_WHITE Color(255, 255, 255, 255)
#define COLOR_WHITE_TRANSPARENT Color(255, 255, 255, 55)

// true - show console
// false - hide console
#define CONSOLE true

// E
#define ENEMY_MAX_COOLDOWN_TIME_FOR_RANDOM_DIRECTION 1.0f
#define ENEMY_SHOT_CHANCE 10 // the higher the value, the less chance
#define ENEMY_VELOCITY 250.0f

// F
#define FILENAME_FONT_SAMSON "fonts/samson.ttf"
#define FILENAME_MAP_1 "maps/map1.txt"
#define FILENAME_MAP_2 "maps/map2.txt"
#define FILENAME_MAP_3 "maps/map3.txt"
#define FILENAME_TEXTURE_BRICKWALL "textures/brickWall.png"
#define FILENAME_TEXTURE_CONCRETEWALL "textures/concreteWall.png"
#define FILENAME_TEXTURE_ENEMY "textures/enemy.png"
#define FILENAME_TEXTURE_FLAG "textures/flag.png"
#define FILENAME_TEXTURE_FOREST "textures/forest.png"
#define FILENAME_TEXTURE_HEADQUARTERS "textures/headquarters.png"
#define FILENAME_TEXTURE_PLAYER "textures/player.png"
#define FILENAME_TEXTURE_PROJECTILE "textures/projectile.png"
#define FILENAME_TEXTURE_WATER "textures/water.png"

// G
#define GAMECONTROLLER_MAX_NUMBER_OF_LIVES_A_ENEMY 0
#define GAMECONTROLLER_MAX_NUMBER_OF_LIVES_A_PLAYER 10

#define GAMEMENU_MAX_DRAWING_TIME_FOR_LEVEL 2.5f
#define GAMEMENU_MAX_DRAWING_TIME_FOR_LOSE_OR_WIN 7.5f

#define GAMEWINDOW_WIDTH 1920
#define GAMEWINDOW_HEIGHT 1080
#define GAMEWINDOW_TITLE "Game_OOP"
#define GAMEWINDOW_FPS 60

// M
#define MAP_AMOUNT 3
#define MAP_SIZE 30
#define MAP_UP (GAMEWINDOW_HEIGHT - TEXTURE_WIDTH_AND_HEIGHT_32 * MAP_SIZE) / 2
#define MAP_DOWN MAP_UP + TEXTURE_WIDTH_AND_HEIGHT_32 * MAP_SIZE
#define MAP_LEFT (GAMEWINDOW_WIDTH - TEXTURE_WIDTH_AND_HEIGHT_32 * MAP_SIZE) / 2
#define MAP_RIGHT MAP_LEFT + TEXTURE_WIDTH_AND_HEIGHT_32 * MAP_SIZE

// P
#define PLAYER_VELOCITY 350.0f

#define PROJECTILE_DAMAGE 100
#define PROJECTILE_VELOCITY 450.0f

// S
#define SPRITE_FRAME_UP 0
#define SPRITE_FRAME_DOWN 2
#define SPRITE_FRAME_LEFT 1
#define SPRITE_FRAME_RIGHT 3

#define STATICOBJECT_COLLISION_RANGE 15

// T
#define TANK_COLLISION_RANGE 10
#define TANK_MAX_COOLDOWN_TIME_FOR_SHOOTING 0.5f
#define TANK_HEALTHPOINTS 100

#define TEXT_BIG_SIZE 192
#define TEXT_SMALL_SIZE 64
#define TEXT_SPACING_BEETWEEN_TEXT_AND_TEXT_FOR_COUNTER 5

#define TEXTURE_WIDTH_AND_HEIGHT_64 64
#define TEXTURE_WIDTH_AND_HEIGHT_32 32
#define TEXTURE_WIDTH_AND_HEIGHT_16 16

#endif // !_MAIN_H