/**
 * File contains definition of Invader class.
 * @file    Invader.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */

#include "Invader.h"
#include "Random.h"

using namespace std;

/** 
 * Constructor with initialize parameters.
 * @param   meshFileName is Invader mesh file name.
 * @param   textureFileName is Invader mesh texture file name.
 */
Invader::Invader(const char* meshFileName,const char* meshFileName2,const char *textureFileName2,const char* textureFileName, const Vector3D& position, std::vector<Vector3D>* shootedLasers)
{
	this->position = position;
	velocity = Vector3D(2.0f,0.0f,1.0f);
	acceleration = Vector3D(1.0f,0.0f,1.0f);
	moveDirection = Vector3D(0.0f,0.0f,1.0f);
	healthPoints = 1;
	isDead = false;
	isEvil = true;
	haveCollided = false;
	rotate = 0;

	animationAccumulator = FRAND + 3;
	shootTimeAccumulator = FRAND + 4;

	mesh1 = new Mesh(meshFileName);
	mesh2 = new Mesh(meshFileName2);


	texture = new Texture[2];
	texture[0].loadTextureFromFile(textureFileName);
	texture[1].loadTextureFromFile(textureFileName2);
	collisionBox = new BoundingBox(mesh1->getVerts(),mesh1->getPoints());

	this->shootedLasers = shootedLasers;
	actualMesh = 1;

	entityVBO1 = new VBO(*mesh1);
	entityVBO2 = new VBO(*mesh2);
	shader.initializeShader("Shaders/lighting.vert","Shaders/lighting.frag");
}

/**
 * Class destructor, free allocated memory.
 */
Invader::~Invader()
{
	delete[] texture;
	delete mesh1;
	delete mesh2;
	delete collisionBox;
	delete entityVBO1;
	delete entityVBO2;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void Invader::updateEntity(const float elapsedTime)
{
	if(healthPoints == 0)
		isDead = true;

	position.z += moveDirection.z * velocity.z * elapsedTime; 
	position.x += 0.05f * cos(position.z);

	animationAccumulator -= elapsedTime;
	shootTimeAccumulator -= elapsedTime;

	if(animationAccumulator <= 0.0f)
	{
		actualMesh += 1;
		actualMesh = actualMesh % 2;
		animationAccumulator = FRAND + 3;
	}

	if(shootTimeAccumulator <= 0.0f)
	{
		shootedLasers->push_back(position);
		shootTimeAccumulator = FRAND + 4;
	}
}

/**
 * Method is used to render entity.
 */
void Invader::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		glTranslatef(position.x,position.y,position.z);
		glRotatef(-90.0f,1.0f,0.0f,0.0f);
		//glRotatef(rotate,1.0f,0.0f,0.0f); //delete 
		//++rotate;

		if(actualMesh == 1)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			Extensions::glActiveTexture(GL_TEXTURE0);
			int textureLocation = Extensions::glGetUniformLocation(shader.getShaderProgram(), "texture_color");
			Extensions::glUniform1i(textureLocation, 0);
			glBindTexture(GL_TEXTURE_2D, *texture[1].getTexture());
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB,entityVBO1->VBOVertices);
			glVertexPointer(3, GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO1->VBONormals);
			glNormalPointer(GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO1->VBOTextureCoords);
			glTexCoordPointer(2, GL_FLOAT, 0, 0);
			glDrawArrays(GL_TRIANGLES, 0, mesh1->getPoints());
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		else
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			Extensions::glActiveTexture(GL_TEXTURE0);
			int textureLocation = Extensions::glGetUniformLocation(shader.getShaderProgram(), "texture_color");
			Extensions::glUniform1i(textureLocation, 0);
			glBindTexture(GL_TEXTURE_2D, *texture[0].getTexture());
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB,entityVBO2->VBOVertices);
			glVertexPointer(3, GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO2->VBONormals);
			glNormalPointer(GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO2->VBOTextureCoords);
			glTexCoordPointer(2, GL_FLOAT, 0, 0);
			glDrawArrays(GL_TRIANGLES, 0, mesh2->getPoints());
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		}
	glPopMatrix();
	shader.unbindShader();
}

