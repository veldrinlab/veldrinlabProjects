/**
 * File contains definition of GameHud class.
 * @file    GameHud.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-02-28
 * @version 2.0
 */

#include "GameHud.hpp"

using namespace Resource;
using namespace std;

namespace Game
{

/**
 * Class default constructor.
 */
GameHud::GameHud()
{
	ResourceManager* resManager = ResourceManager::getInstance();
	hpTexture = resManager->getResource(string("HpTexture"), string("Data/hpTexture.png"), TEXTURE);
	warningEnbale = true;
	up = true;

	points = 200;
	blendAccumulator = 0.0f;
	danger = resManager->getResource(string("Danger"), string("Data/danger.png"), TEXTURE);
	scoreTexture = resManager->getResource(string("Score"), string("Data/digitalscore.png"), TEXTURE);

	score[0] = 0;
	score[1] = 0;
	score[2] = 2;
	score[3] = 0;
	score[4] = 0;
}

/**
 * Destructor, free allocated memory.
 */
GameHud::~GameHud()
{

}




/**
 * Method is used to render Game Hud.
 */
void GameHud::renderGameHud()
{
	for(vector<HealthBar*>::const_iterator i = bars.begin(); i != bars.end(); ++i)
	{
		glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(hpTexture.get())->getTexture());
		(*i)->renderHealthBar();
	}

	glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glTranslatef(1024/2,768/2,0.0f);
		glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(danger.get())->getTexture());
		glColor4f(1.0f,1.0f,1.0f,blendAccumulator);
		glBegin(GL_QUADS);
			glTexCoord2i(0,0);
			glVertex2f(0.0f, 0.0f);
			glTexCoord2i(1,0);
			glVertex2f(267.0f, 0.0f);
			glTexCoord2i(1,1);
			glVertex2f(267.0f,67.0f);
			glTexCoord2i(0,1);
			glVertex2f(0.0f,67.0f);
		glEnd();
		//glDisable(GL_BLEND);
		glColor4f(1,1,1,1);
	glPopMatrix();

	////mp
	//glPushMatrix();
	//	glTranslatef(42.0f,507.0f,0.0f);
	//	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(mpTexture.get())->getTexture());
	//	glBegin(GL_QUADS);
	//		glTexCoord2i(0,0);
	//		glVertex2f(0.0f, 0.0f);
	//		glTexCoord2i(1,0);
	//		glVertex2f( 4.8f * mpAmount, 0.0f);
	//		glTexCoord2i(1,1);
	//		glVertex2f( 4.8f * mpAmount, 28.0f);
	//		glTexCoord2i(0,1);
	//		glVertex2f(0.0f,28.0f);
	//	glEnd();
	//glPopMatrix();

	////stat bar
	//glPushMatrix();
	//	glTranslatef(10.0f,500.0f,0.0f);
	//	glEnable(GL_BLEND);
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(statTexture.get())->getTexture());
	//	glBegin(GL_QUADS);
	//		glTexCoord2i(0,0);
	//		glVertex2f(0.0f, 0.0f);
	//		glTexCoord2i(1,0);
	//		glVertex2f( 160.0f, 0.0f);
	//		glTexCoord2i(1,1);
	//		glVertex2f( 160.0f,70.0f);
	//		glTexCoord2i(0,1);
	//		glVertex2f(0.0f,70.0f);
	//	glEnd();
	//	glDisable(GL_BLEND);
	//glPopMatrix();

	for(int i = 0; i < 5; ++i)
	{
		glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glTranslatef(450.0f+i*40.0f,700.0f,0.0f);
			glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(scoreTexture.get())->getTexture());
			glBegin(GL_QUADS);
				glTexCoord2f(score[i]*0.1f,0.0f);
				glVertex2f(0.0f, 0.0f);
				glTexCoord2f(score[i]*0.1f + 0.1f,0.0f);
				glVertex2f( 30.0f, 0.0f);
				glTexCoord2f(score[i]*0.1f+0.1f,1.0f);
				glVertex2f( 30.0f,30.0f);
				glTexCoord2f(score[i]*0.1f,1.0f);
				glVertex2f(0.0f,30.0f);
			glEnd();	
			glDisable(GL_BLEND);
		glPopMatrix();
	}
}
//
///**
// * Setter of private hpAmount member.
// * @param	hpAmount is new health points amount.
// */
//void GameHud::setHpAmount(const int hpAmount)
//{
//	this->hpAmount = hpAmount;
//}
///**
// * Setter of private mpAmount member.
// * @param	mpAmount is new magic points amount.
// */
//
//void GameHud::setMpAmount(const int mpAmount)
//{
//	this->mpAmount = mpAmount;
//}
//
///**
// * Method is used to increase score about random amount and call calculateScore method.
// */
//void GameHud::increaseScore()
//{
//	points = rand() % 10 + 1;
//	calculateScore();
//}
//
///**
// * Method is used to reset score points.
// */
//void GameHud::resetScore()
//{
//	srand (static_cast<unsigned int>(time(NULL)));
//	for(int i = 0; i<5; ++i)
//		score[i] = 0;
//}
//
///**
// * Method is used to calculate score.
// */
void GameHud::calculateScore()
{
	score[4] += points;
	for(int i = 4; i >0; --i)
	{
		if(score[i] >=10)
		{
			score[i] = score[i]%10;
			score[i-1]++;
		}
	}
}
//
//}

}
