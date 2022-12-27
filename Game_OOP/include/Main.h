#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;
using namespace std;

// minimum MAP_SIZE * MAP_BLOCK
#define WINDOW_W MAP_SIZE * MAP_BLOCK
#define WINDOW_H MAP_SIZE * MAP_BLOCK
#define WINDOW_TITLE "Game"
#define WINDOW_FPS 60

#define VELOCITY_PLAYER 0.015f
#define VELOCITY_ENEMY 0.01f
#define VELOCITY_PROJECTILE 0.03f

#define TIME_COEFFICIENT WINDOW_FPS

#define TANK_W 64
#define TANK_H 64
#define TANK_COOLDOWN 5000
#define TANK_HEALTHPOINTS 100

#define STATICOBJECT_BIG_W 64
#define STATICOBJECT_BIG_H 64
#define STATICOBJECT_SMALL_W 32
#define STATICOBJECT_SMALL_H 32

#define PROJECTILE_W 16
#define PROJECTILE_H 16
#define PROJECTILE_DAMAGE TANK_HEALTHPOINTS / 4
#define PROJECTILE_DIVISION 4
#define PROJECTILE_MULTIPLICATION 0.375
#define PROJECTILE_COEFFICIENT_X_FOR_UP TANK_W * PROJECTILE_MULTIPLICATION
#define PROJECTILE_COEFFICIENT_Y_FOR_UP -(TANK_H / PROJECTILE_DIVISION)
#define PROJECTILE_COEFFICIENT_X_FOR_DOWN TANK_W * PROJECTILE_MULTIPLICATION
#define PROJECTILE_COEFFICIENT_Y_FOR_DOWN TANK_H
#define PROJECTILE_COEFFICIENT_X_FOR_LEFT -(TANK_W / PROJECTILE_DIVISION)
#define PROJECTILE_COEFFICIENT_Y_FOR_LEFT TANK_H * PROJECTILE_MULTIPLICATION
#define PROJECTILE_COEFFICIENT_X_FOR_RIGHT TANK_W
#define PROJECTILE_COEFFICIENT_Y_FOR_RIGHT TANK_H * PROJECTILE_MULTIPLICATION

// true - show messages
// false - hide messages
#define MESSAGES_DEBUG_IN_PROJECTILE false
#define MESSAGES_DEBUG_IN_STATICOBJECT false
#define MESSAGES_DEBUG_IN_TANK true

#define MAP_SIZE 15
#define MAP_BLOCK 64
#define MAP_UP_Y (WINDOW_H-MAP_SIZE*MAP_BLOCK)/2
#define MAP_DOWN_Y MAP_UP_Y+MAP_SIZE*MAP_BLOCK
#define MAP_LEFT_X (WINDOW_W-MAP_SIZE*MAP_BLOCK)/2
#define MAP_RIGHT_X MAP_LEFT_X+MAP_SIZE*MAP_BLOCK

#define FRAME_UP 0
#define FRAME_DOWN 2
#define FRAME_LEFT 1
#define FRAME_RIGHT 3

#define FILENAME_PNG_BRICKWALL "png/brickWall.png"
#define FILENAME_PNG_CONCRETEWALL "png/concreteWall.png"
#define FILENAME_PNG_ENEMY "png/enemy.png"
#define FILENAME_PNG_FLAG "png/flag.png"
#define FILENAME_PNG_FOREST "png/forest.png"
#define FILENAME_PNG_HEADQUARTERS "png/headquarters.png"
#define FILENAME_PNG_PLAYER "png/player.png"
#define FILENAME_PNG_PROJECTILE "png/projectile.png"
#define FILENAME_PNG_WATER "png/water.png"

// true - show console
// false - hide console
#define CONSOLE true

#define COLLISION_RANGE_FOR_STATICOBJECT 15
#define COLLISION_RANGE_FOR_TANK 10

#endif // !_MAIN_H