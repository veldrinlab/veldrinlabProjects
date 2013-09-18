/**
 * File contains definition of SkyBox class.
 * @file    SkyBox.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 2.0
 */

#include "SkyBox.hpp"

using namespace std;

namespace engine
{

/**
 * Class main constrcutor.
 * @param   center is center point vector
 * @param	dimmension is box width, height, length.
 * @remarsk	dodac RM
 */
SkyBox::SkyBox(const Vector3D& center, const Vector3D& dimmension, const int levelID)
{
	this->center = center;
	this->dimmension = dimmension;

	isDead = false;

	ResourceManager* resManager = ResourceManager::getInstance();
	if(levelID == 0)
	{
		front = resManager->getResource(string("SpaceFront"), string("Data/Space/spaceFront.jpg"), TEXTURE);
		back = resManager->getResource(string("SpaceBack"), string("Data/Space/spaceBack.jpg"), TEXTURE);
		bottom = resManager->getResource(string("SpaceBottom"), string("Data/Space/spaceBottom.jpg"), TEXTURE);
		top = resManager->getResource(string("SpaceTop"), string("Data/Space/spaceTop.jpg"), TEXTURE);
		left  = resManager->getResource(string("SpaceLeft"), string("Data/Space/spaceLeft.jpg"), TEXTURE);
		right  = resManager->getResource(string("SpaceRight"), string("Data/Space/spaceRight.jpg"), TEXTURE);
	}
	else
	{
		front = resManager->getResource(string("HothFront"), string("Data/Hoth/Front.jpg"), TEXTURE);
		back = resManager->getResource(string("HothBack"), string("Data/Hoth/Back.jpg"), TEXTURE);
		bottom = resManager->getResource(string("HothBottom"), string("Data/Hoth/Bottom.jpg"), TEXTURE);
		top = resManager->getResource(string("HothTop"), string("Data/Hoth/Top.jpg"), TEXTURE);
		left  =resManager->getResource(string("HothLeft"), string("Data/Hoth/Left.jpg"), TEXTURE);
		right  = resManager->getResource(string("HothRight"), string("Data/Hoth/Right.jpg"), TEXTURE);
	}

	collisionBox = new BoundingBox();
	collisionBox->min = Vector3D(0.0f,0.0f,0.0f);
	collisionBox->max = Vector3D(0.0f,0.0f,0.0f);
	buildSkyBoxList();
}

/**
 * Destructor, free allocated memory. 
 */
SkyBox::~SkyBox()
{

}

/**
 * Method is used to build SkyBox display list
 */
void SkyBox::buildSkyBoxList()
{
	skyBoxList = glGenLists(1);

	glNewList(skyBoxList,GL_COMPILE);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);

		glPushMatrix();
		glScalef(10.0f,10.0f,10.0f);
		float x = center.x - dimmension.x  / 2.0f;
		float y = center.y - dimmension.y / 2.0f;
		float z = center.z - dimmension.z / 2.0f;

		Texture* tempTexture = static_cast<Texture*>(front.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x + dimmension.x, y, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x + dimmension.x, y + dimmension.y, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, y + dimmension.y, z);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, y, z);
		glEnd();

		tempTexture = static_cast<Texture*>(back.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y, z + dimmension.z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y + dimmension.y, z + dimmension.z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + dimmension.x, y + dimmension.y, z + dimmension.z);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + dimmension.x, y, z + dimmension.z);
		glEnd();

		tempTexture = static_cast<Texture*>(bottom.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);		
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y, z + dimmension.z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + dimmension.x, y, z + dimmension.z);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + dimmension.x, y, z);
		glEnd();

		tempTexture = static_cast<Texture*>(top.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + dimmension.x, y + dimmension.y, z);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + dimmension.x, y + dimmension.y, z + dimmension.z);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y + dimmension.y, z + dimmension.z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y + dimmension.y,	z);
		glEnd();

		tempTexture = static_cast<Texture*>(left.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y + dimmension.y, z);	
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, y + dimmension.y, z + dimmension.z); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, y, z + dimmension.z);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y, z);		
		glEnd();

		tempTexture = static_cast<Texture*>(right.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);		
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + dimmension.x, y, z);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x + dimmension.x, y, z + dimmension.z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x + dimmension.x, y + dimmension.y,	z + dimmension.z); 
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + dimmension.x, y + dimmension.y,	z);
		glEnd();
		glPopMatrix();
	glEndList();
}

/**
 * Method is used to render SkyBox. Draw and texture cube.
 * @remarks		use verex list for optimization.
 */
void SkyBox::renderEntity()
{
	glCallList(skyBoxList); 
}

}
