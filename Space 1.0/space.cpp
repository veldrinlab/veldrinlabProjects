#include <unistd.h>
#include <ctime>

#include "space.h"

using namespace std;

// Intro class implementantion
Intro::Intro(char* logoFileName, char* logo2FileName)
{
	setLogoImage(logoFileName);
	setLogo2Image(logo2FileName);
	setTime(2);
}

Intro::~Intro()
{

}

void Intro::init()
{
	oslStartDrawing();
	oslDrawImage(logo);
	sleep(getTime());
	oslEndDrawing();
	oslSyncFrame();
	sleep(getTime());

	oslStartDrawing();
	oslDrawImage(logo2);
	sleep(getTime());
	oslEndDrawing();
	oslSyncFrame();
	sleep(getTime());
}

OSL_IMAGE* Intro::getLogoImage()
{
	return logo;
}

void Intro::setLogoImage(char* logoFileName)
{
	logo = oslLoadImageFile(logoFileName, OSL_IN_RAM, OSL_PF_5551);
	if (!logo)
		oslDebug("File error occurred!");
}

OSL_IMAGE* Intro::getLogo2Image()
{
	return logo2;
}

void Intro::setLogo2Image(char* logo2FileName)
{
	logo2 = oslLoadImageFile(logo2FileName, OSL_IN_RAM, OSL_PF_5551);
	if (!logo2)
		oslDebug("File error occurred!");
}

int Intro::getTime()
{
	return time;
}

void Intro::setTime(int time)
{
	this->time = time;
}

// Spaceship class implementation
Spaceship::Spaceship(char* spriteFileName)
{
	setSpriteImage(spriteFileName);
	setSpritePosition(0);
	setxPosition(0);
	setyPosition(0);
}

Spaceship::~Spaceship()
{

}

OSL_IMAGE* Spaceship::getSpriteImage()
{
	return sprite;
}

void Spaceship::setSpriteImage(char* spriteFileName)
{
	sprite = oslLoadImageFile(spriteFileName, OSL_IN_RAM, OSL_PF_5551);
	if (!sprite)
		oslDebug("File error occurred!");
}

int Spaceship::getSpriteMarch()
{
	return spriteMarch;
}

void Spaceship::setSpriteMarch(int spriteMarch)
{
	this->spriteMarch = spriteMarch;
}

int Spaceship::getSpritePosition()
{
	return spritePosition;
}

void Spaceship::setSpritePosition(int spritePosition)
{
	this->spritePosition = spritePosition;
}

void Spaceship::setxPosition(int xPosition)
{
	this->xPosition = xPosition;
	this->getSpriteImage()->x = xPosition;
}

int Spaceship::getxPosition()
{
	return xPosition;
}

void Spaceship::setyPosition(int yPosition)
{
	this->yPosition = yPosition;
	this->getSpriteImage()->y = yPosition;
}

int Spaceship::getyPosition()
{
	return yPosition;
}

// Meteor class implementation
Meteor::Meteor(char* meteorFileName, int xPosition, int yPosition)
{
	setMeteorImage(meteorFileName);
	setxPosition(xPosition);
	setyPosition(yPosition);
}

Meteor::Meteor()
{

}

Meteor::~Meteor()
{

}

OSL_IMAGE* Meteor::getMeteorImage()
{
	return meteor;
}

void Meteor::setMeteorImage(char* meteorFileName)
{
	meteor = oslLoadImageFile(meteorFileName, OSL_IN_RAM, OSL_PF_5551);
	if (!meteor)
		oslDebug("File error occurred!");
}

void Meteor::setxPosition(int xPosition)
{
	this->xPosition = xPosition;
	this->getMeteorImage()->x = xPosition;
}

int Meteor::getxPosition()
{
	return xPosition;
}

void Meteor::setyPosition(int yPosition)
{
	this->yPosition = yPosition;
	this->getMeteorImage()->y = yPosition;
}

int Meteor::getyPosition()
{
	return yPosition;
}

int Meteor::getStartPositionX()
{
	return startPositionX;
}

void Meteor::setStartPositionX(int startPositionX)
{
	this->startPositionX = startPositionX;
}

int Meteor::getStartPositionY()
{
	return startPositionY;
}

void Meteor::setStartPositionY(int startPositionY)
{
	this->startPositionY = startPositionY;
}


// Explosion class implementation
Explosion::Explosion(char* explosionFileName, int xPosition, int yPosition)
{
	setExplosionImage(explosionFileName);
	setxPosition(xPosition);
	setyPosition(yPosition);
	setSpritePosition(0);
}

Explosion::~Explosion()
{

}

void Explosion::init()
{

}

OSL_IMAGE* Explosion::getExplosionImage()
{
	return explosion;
}

void Explosion::setExplosionImage(char* explosionFileName)
{
	explosion = oslLoadImageFile(explosionFileName, OSL_IN_RAM, OSL_PF_5551);
	if (!explosion)
		oslDebug("File error occurred!");
}

int Explosion::getSpritePosition()
{
	return spritePosition;
}

void Explosion::setSpritePosition(int spritePosition)
{
	this->spritePosition = spritePosition;
}

int Explosion::getxPosition()
{
	return xPosition;
}

void Explosion::setxPosition(int xPosition)
{
	this->xPosition = xPosition;
	this->getExplosionImage()->x = xPosition;
}

int Explosion::getyPosition()
{
	return yPosition;
}

void Explosion::setyPosition(int yPosition)
{
	this->yPosition = yPosition;
	this->getExplosionImage()->y = yPosition;
}

// Game class implementation
Game::Game(char* backgroundFileName, int meteorsNumber)
{
	setBackgroundImage(backgroundFileName);
	setSpaceship();
	setMeteorsNumber(meteorsNumber);
	setMeteors(getMeteorsNumber());
	setScore(0);
}

Game::~Game()
{
	free(player);
	free(meteors);
}

void Game::init()
{
	int skip = 0;
	
	setCollisionDetected(false);


	while (!isCollisionDetected())
	{
		if(!skip)
		{
			oslStartDrawing();
			updatePlayerSprite();
			playerMovement();
			updateMeteors();
			updateScreen();
			oslEndDrawing();
		}
		
        oslReadKeys();
    	skip = oslSyncFrame();	
	}

	Explosion explosion("explosion.png",player->getxPosition(),player->getyPosition());
	skip = 0;
	oslCls();

	while(!osl_quit)
	{
		if(!skip)
		{
			oslStartDrawing();
			updateMeteors();

			oslDrawImage(background);
			for(int i = 0; i < getMeteorsNumber(); i++)
			{
				oslDrawImage(meteors[i].getMeteorImage());
			}

			oslSetImageTileSize(explosion.getExplosionImage(),(explosion.getSpritePosition())*32,0,32,26);
			explosion.setSpritePosition(explosion.getSpritePosition()+1);
			if(explosion.getSpritePosition()==5)
				break;

			oslDrawImage(explosion.getExplosionImage());
			oslEndDrawing();
		}
		
        oslReadKeys();
    	skip = oslSyncFrame();

	}
}

void Game::playerMovement()
{
	if (osl_keys->held.up && player->getyPosition() != 0)
		player->setyPosition(player->getyPosition() - 6); 

	else if(osl_keys->held.down && player->getyPosition() <= 220 )
		player->setyPosition(player->getyPosition() + 6);

	else if (osl_keys->held.left && player->getxPosition() != 0)
		player->setxPosition(player->getxPosition() - 6); 

	else if (osl_keys->held.right && player->getxPosition() <= 438)
		player->setxPosition(player->getxPosition() + 6);
}

void Game::collision(OSL_IMAGE *img1, float img1posX, float img1posY, OSL_IMAGE *img2, float img2posX, float img2posY ) 
{
   int img1width  = img1->stretchX;
   int img1height = img1->stretchY;
   int img2width  = img2->stretchX;
   int img2height = img2->stretchY;
   
   if ((img1posX + img1width > img2posX) && (img1posX < img2posX + img2width) && (img1posY + img1height > img2posY) &&
       (img1posY < img2posY + img2height) ) 
   {
         setCollisionDetected(true);              
   }
}

/*
bool Game::collisionDetection()
{
	//ship rectangle
	int shipWidth  = player->getSpriteImage()->stretchX;
	int shipHeight = player->getSpriteImage()->stretchY;
	int shipX1 = player->getxPosition(); 
	int shipX2 = shipX1 + shipWidth;
	int shipY1 = player->getyPosition();
	int shipY2 = shipY1 + shipHeight;

	for(int i = 0; i<getMeteorsNumber(); i++)
	{
		//meteor rectangle
		int meteorWidth = meteors[i].getMeteorImage()->stretchX;
		int meteorHeight = meteors[i].getMeteorImage()->stretchY;
		int meteorX1 = meteors[i].getxPosition();
		int meteorX2 = meteorX1 + meteorWidth;
		int meteorY1 = meteors[i].getyPosition();
		int meteorY2 = meteorX2 + meteorHeight;

		//zamienic meteor z shipem

		if( (shipX1 > meteorX1) && (shipX1 < meteorX2) && (shipY1 > meteorY1) && (shipY1 < meteorY2) )
			return true;
		else if( (shipX1 > meteorX1) && (shipX1 < meteorX2) && (shipY2 > meteorY1) && (shipY2 < meteorY2) )
			return true;
		else if( (shipX2 > meteorX1) && (shipX2 < meteorX2) && (shipY2 > meteorY1) && (shipY2 < meteorY2) )
			return true;
			return true;
	}

   return false;

}
*/

void Game::updatePlayerSprite()
{
	oslSetImageTileSize(player->getSpriteImage(),0,(player->getSpritePosition())*52,42,52);
	player->setSpritePosition(player->getSpritePosition()+1);
	if(player->getSpritePosition() == 3)
		player->setSpritePosition(0);
}

void Game::updateMeteors()
{
	Meteor* meteors;
	int oldPosition = 0;
	int newPosition = 0;
	meteors = getMeteors();

	for(int i = 0; i < getMeteorsNumber(); i++)
	{
		oldPosition = meteors[i].getxPosition();
		newPosition = oldPosition - 4;
		
		meteors[i].setxPosition(newPosition);
		if(newPosition == -20)
		{
			meteors[i].setxPosition(meteors[i].getStartPositionX());
			setScore(getScore()+3);
		}
		collision(player->getSpriteImage(),player->getxPosition(),player->getyPosition(),
			meteors[i].getMeteorImage(),meteors[i].getxPosition(),meteors[i].getyPosition());
	}

}
void Game::updateScreen()
{
	oslDrawImage(background);
	oslDrawImage(player->getSpriteImage());
	for(int i = 0; i < getMeteorsNumber(); i++)
	{
		oslDrawImage(meteors[i].getMeteorImage());
	}
}

OSL_IMAGE* Game::getBackgroundImage()
{
	return background;
}

void Game::setBackgroundImage(char* backgroundFileName)
{
	background = oslLoadImageFile(backgroundFileName, OSL_IN_RAM, OSL_PF_5551);
	if (!background)
		oslDebug("File error occurred!");
}

Spaceship* Game::getSpaceship()
{
	return player;
}

void Game::setSpaceship()
{
	player = new Spaceship("spaceship.png");
}

Meteor* Game::getMeteors()
{
	return meteors;
}

void Game::setMeteors(int number)
{
	meteors = new Meteor[number];

	meteors[0].setMeteorImage("meteor1.png");
	meteors[1].setMeteorImage("meteor2.png");
	meteors[2].setMeteorImage("meteor3.png");
	meteors[3].setMeteorImage("meteor1.png");
	meteors[4].setMeteorImage("meteor2.png");
	meteors[5].setMeteorImage("meteor3.png");
	meteors[6].setMeteorImage("meteor1.png");
	meteors[7].setMeteorImage("meteor2.png");
	meteors[8].setMeteorImage("meteor3.png");
	meteors[9].setMeteorImage("meteor1.png");

	meteors[0].setxPosition(560);
	meteors[0].setyPosition(40);
	meteors[0].setStartPositionX(560);
	meteors[0].setStartPositionY(40);

	meteors[1].setxPosition(560);
	meteors[1].setyPosition(120);
	meteors[1].setStartPositionX(560);
	meteors[1].setStartPositionY(120);

	meteors[2].setxPosition(560);
	meteors[2].setyPosition(170);
	meteors[2].setStartPositionX(560);
	meteors[2].setStartPositionY(170);

	meteors[3].setxPosition(660);
	meteors[3].setyPosition(80);
	meteors[3].setStartPositionX(660);
	meteors[3].setStartPositionY(80);

	meteors[4].setxPosition(780);
	meteors[4].setyPosition(40);
	meteors[4].setStartPositionX(780);
	meteors[4].setStartPositionY(40);

	meteors[5].setxPosition(780);
	meteors[5].setyPosition(180);
	meteors[5].setStartPositionX(780);
	meteors[5].setStartPositionY(180);

	meteors[6].setxPosition(880);
	meteors[6].setyPosition(60);
	meteors[6].setStartPositionX(880);
	meteors[6].setStartPositionY(60);

	meteors[7].setxPosition(880);
	meteors[7].setyPosition(160);
	meteors[7].setStartPositionX(880);
	meteors[7].setStartPositionY(160);

	meteors[8].setxPosition(980);
	meteors[8].setyPosition(40);
	meteors[8].setStartPositionX(980);
	meteors[8].setStartPositionY(40);
	
	meteors[9].setxPosition(980);
	meteors[9].setyPosition(200);
	meteors[9].setStartPositionX(980);
	meteors[9].setStartPositionY(200);
}

int Game::getMeteorsNumber()
{
	return meteorsNumber;
}

void Game::setMeteorsNumber(int meteorsNumber)
{
	this->meteorsNumber = meteorsNumber;
}

int Game::getScore()
{
	return score;
}

void Game::setScore(int score)
{
	this->score = score;
}

void Game::setCollisionDetected(bool collision)
{
	this->collisionDetected = collision;
}

bool Game::isCollisionDetected()
{
	return collisionDetected;
}
