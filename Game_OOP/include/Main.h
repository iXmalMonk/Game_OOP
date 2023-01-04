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

#define WINDOW_W 1920
#define WINDOW_H 1080
#define WINDOW_TITLE "Game"
#define WINDOW_FPS 60

#define VELOCITY_PLAYER 250.0f
#define VELOCITY_ENEMY 250.0f
#define VELOCITY_PROJECTILE 450.0f

#define TEXT_BIG_SIZE 192
#define TEXT_SMALL_SIZE 64
#define TEXT_SPACING_BEETWEEN_TEXT_AND_TEXT_FOR_COUNTER 5

#define TANK_W 64
#define TANK_H 64
#define TANK_COOLDOWN_MAX_TIME_FOR_SHOOTING 0.35f
#define TANK_HEALTHPOINTS 100

#define STATICOBJECT_BIG_W 64
#define STATICOBJECT_BIG_H 64
#define STATICOBJECT_SMALL_W 32
#define STATICOBJECT_SMALL_H 32

#define PROJECTILE_W 16
#define PROJECTILE_H 16
#define PROJECTILE_DAMAGE TANK_HEALTHPOINTS
#define PROJECTILE_DIVISION 4
#define PROJECTILE_MULTIPLICATION 0.375

#define MAX_NUMBER_OF_LIVES_A_ENEMY 1
#define MAX_NUMBER_OF_LIVES_A_PLAYER 1

#define MAP_BLOCK 32
#define MAP_SIZE 30
#define MAP_UP (WINDOW_H - MAP_BLOCK * MAP_SIZE) / 2
#define MAP_DOWN MAP_UP + MAP_BLOCK * MAP_SIZE
#define MAP_LEFT (WINDOW_W - MAP_BLOCK * MAP_SIZE) / 2
#define MAP_RIGHT MAP_LEFT + MAP_BLOCK * MAP_SIZE
#define MAPS_AMOUNT 2

#define FRAME_UP 0
#define FRAME_DOWN 2
#define FRAME_LEFT 1
#define FRAME_RIGHT 3

#define FILENAME_FONT_SAMSON "fonts/samson.ttf"
#define FILENAME_MAP_1 "maps/map1.txt"
#define FILENAME_MAP_2 "maps/map2.txt"
#define FILENAME_TEXTURE_BRICKWALL "textures/brickWall.png"
#define FILENAME_TEXTURE_CONCRETEWALL "textures/concreteWall.png"
#define FILENAME_TEXTURE_ENEMY "textures/enemy.png"
#define FILENAME_TEXTURE_FLAG "textures/flag.png"
#define FILENAME_TEXTURE_FOREST "textures/forest.png"
#define FILENAME_TEXTURE_HEADQUARTERS "textures/headquarters.png"
#define FILENAME_TEXTURE_PLAYER "textures/player.png"
#define FILENAME_TEXTURE_PROJECTILE "textures/projectile.png"
#define FILENAME_TEXTURE_WATER "textures/water.png"

#define ENEMY_COOLDOWN_MAX_TIME_FOR_RANDOM_DIRECTION 1
#define ENEMY_SHOT_CHANCE 10 // the higher the value, the less chance

// true - show console
// false - hide console
#define CONSOLE false

#define COLOR_BLACK Color(0, 0, 0, 255)
#define COLOR_GRAY Color(50, 50, 50, 255)
#define COLOR_RED Color(255, 0, 0, 255)
#define COLOR_WHITE Color(255, 255, 255, 255)
#define COLOR_WHITE_TRANSPARENT Color(255, 255, 255, 55)

#define COLLISION_RANGE_FOR_STATICOBJECT 15
#define COLLISION_RANGE_FOR_TANK 10

#endif // !_MAIN_H