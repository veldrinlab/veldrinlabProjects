/**
 * space.h - header file of all "Space" classes
 *
 *  Created on: 2010-06-24
 *      Author: Veldrin
 */

#ifndef SPACE_H
#define SPACE_H

#include <oslib/oslib.h>

// Game intro class
class Intro
{
private:
	OSL_IMAGE *logo;
	OSL_IMAGE *logo2;
	int time;

public:
	Intro(char*,char*);
	~Intro();
	void init();
	OSL_IMAGE* getLogoImage();
	void setLogoImage(char*);
	OSL_IMAGE* getLogo2Image();
	void setLogo2Image(char*);
	int getTime();
	void setTime(int);
};


// Spaceship class
class Spaceship
{
private:
	OSL_IMAGE* sprite;
	int spriteMarch;
	int spritePosition;
	int xPosition;
	int yPosition;

public:
	Spaceship(char*);
	~Spaceship();
	OSL_IMAGE* getSpriteImage();
	void setSpriteImage(char*);
	int getSpriteMarch();
	void setSpriteMarch(int);
	int getSpritePosition();
	void setSpritePosition(int);
	void setxPosition(int);
	int getxPosition();
	void setyPosition(int);
	int getyPosition();
};


// Meteor class
class Meteor
{
private:
	OSL_IMAGE* meteor;
	int xPosition;
	int yPosition;
	int startPositionX;
	int startPositionY;

public:
	Meteor(char*, int, int);
	Meteor();
	~Meteor();
	OSL_IMAGE* getMeteorImage();
	void setMeteorImage(char*);
	void setxPosition(int);
	int getxPosition();
	void setyPosition(int);
	int getyPosition();
	int getStartPositionX();
	void setStartPositionX(int);
	int getStartPositionY();
	void setStartPositionY(int);
};

class Explosion
{
private:
	OSL_IMAGE* explosion;
	int spritePosition;
	int xPosition;
	int yPosition;
public:
	Explosion(char*,int,int);
	~Explosion();
	void init();
	OSL_IMAGE* getExplosionImage();
	void setExplosionImage(char*);
	int getSpritePosition();
	void setSpritePosition(int);
	int getxPosition();
	void setxPosition(int);
	int getyPosition();
	void setyPosition(int);
};


// Game Main class
class Game
{
private:
	OSL_IMAGE* background;
	Spaceship* player;
	Meteor* meteors;
	int meteorsNumber;
	int score;
	bool collisionDetected;

public:
	Game(char* backgroundFileName, int meteorsNumber);
	~Game();
	void init();
	void playerMovement();
	void updatePlayerSprite();
	void updateMeteors();
	void updateScreen();
	bool collisionDetection();
	OSL_IMAGE* getBackgroundImage();
	void setBackgroundImage(char*);
	Spaceship* getSpaceship();
	void setSpaceship();
	Meteor* getMeteors();
	void setMeteors(int);
	int getMeteorsNumber();
	void setMeteorsNumber(int);
	int getScore();
	void setScore(int);
	void collision(OSL_IMAGE *img1, float img1posX, float img1posY, OSL_IMAGE *img2, float img2posX, float img2posY );
	void setCollisionDetected(bool collision);
	bool isCollisionDetected();
};

#endif
