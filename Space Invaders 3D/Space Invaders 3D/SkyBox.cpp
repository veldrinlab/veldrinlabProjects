/**
 * File contains definition of SkyBox class.
 * @file    SkyBox.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 2.0
 */

#include "SkyBox.h"

/**
 * Class main constrcutor.
 * @param   centerX is box center x
 * @param   centerY is box center y
 * @param   cenetrZ is box cnter z
 * @param   width is box width
 * @param   height is box height
 * @param   length is box lengh
 * @remarks zastapic center vectorem i width/height/lengh jednym parameterm - mamy szescian.... 
 *			dodac pointery do struktury/tablicy zasobow
 */
SkyBox::SkyBox(float centerX, float centerY, float centerZ, float width, float height, float length)
{
	this->centerX = centerX;
	this->centerY = centerY;
	this->centerZ = centerZ;
	this->width = width;
	this->height = height;
	this->length = length;
	this->isDead = false;

	front = new Texture("Data/purplenebula_ft.jpg");
	back = new Texture("Data/purplenebula_bk.jpg");
	bottom = new Texture("Data/purplenebula_dn.jpg");
	top = new Texture("Data/purplenebula_up.jpg");
	left  = new Texture("Data/purplenebula_lf.jpg");
	right  = new Texture("Data/purplenebula_rt.jpg");

	buildSkyBoxList();
	shader.initializeShader("Shaders/lighting.vert","Shaders/lighting.frag");
}

/**
 * Destructor, free allocated memory. 
 */
SkyBox::~SkyBox()
{
	delete front;
	delete back;
	delete top;
	delete bottom;
	delete left;
	delete right;
}

/**
 * Method is used to build SkyBox display list
 */
void SkyBox::buildSkyBoxList()
{
	skyBoxList = glGenLists(1);

	glNewList(skyBoxList,GL_COMPILE);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glPushMatrix();
		glScalef(3.0f,1.0f,3.0f);
		float x = centerX - width  / 2.0f;
		float y = centerY - height / 2.0f;
		float z = centerZ - length / 2.0f;

		glBindTexture(GL_TEXTURE_2D, *front->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x + width, y, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x + width, y + height, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, y + height, z);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, y, z);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, *back->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y, z + length);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y + height, z + length);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + width, y + height, z + length);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + width, y, z + length);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, *bottom->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);		
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y, z + length);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + width, y, z + length);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + width, y, z);
		glEnd();

		glBindTexture(GL_TEXTURE_2D,  *top->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + width, y + height, z);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + width, y + height, z + length);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y + height, z + length);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y + height,	z);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, *left->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x, y + height, z);	
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, y + height, z + length); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, y, z + length);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, y, z);		
		glEnd();

		glBindTexture(GL_TEXTURE_2D,  *right->getTexture());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);		
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x + width, y, z);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x + width, y, z + length);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x + width, y + height,	z + length); 
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + width, y + height,	z);
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
	shader.bindShader();
	glCallList(skyBoxList); 
	shader.unbindShader();
}
