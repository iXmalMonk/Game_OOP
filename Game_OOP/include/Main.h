#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <list>
using namespace std;

#define WINDOW_W 640
#define WINDOW_H 480
#define WINDOW_TITLE "Game"
#define WINDOW_FPS 60

#define TIME_COEFFICIENT WINDOW_FPS

#define PLAYER_VELOCITY 0.015
#define ENEMY_VELOCITY 0.01
#define PROJECTILE_VELOCITY 0.03

#define PLAYER_FILENAME_PNG "png/playerTank.png"
#define ENEMY_FILENAME_PNG "png/enemyTank.png"
#define PROJECTILE_FILENAME_PNG "png/projectile.png"
#define BRICKWALL_FILENAME_PNG "png/brickWall.png"

#define TANK_W 64
#define TANK_H 64
#define TANK_COOLDOWN 5000
#define TANK_HEALTHPOINTS 100

#define PROJECTILE_W 16
#define PROJECTILE_H 16
#define PROJECTILE_DAMAGE 25

#define STATICOBJECT_W 16
#define STATICOBJECT_H 16

#define FRAME_UP 0
#define FRAME_DOWN 2
#define FRAME_LEFT 1
#define FRAME_RIGHT 3

#define MESSAGES_DEBUG_IN_GAME false
#define MESSAGES_DEBUG_IN_PROJECTILE true
#define MESSAGES_DEBUG_IN_PLAYER false
#define MESSAGES_DEBUG_IN_ENEMY false

#endif // !_MAIN_H
