/**
 * File contains definition of LaserBlast class.
 * @file    LaserBlast.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */

#include "LaserBlast.h"

/** 
 * Constructor with initialize parameters.
 * @param   meshFileName is LaserBlast mesh file name.
 * @param   textureFileName is LaserBlast mesh texture file name.
 */
LaserBlast::LaserBlast(const char* meshFileName, const char* textureFileName,const Vector3D& position, float direction)
{
	this->position = position;
	this->isDead = false;
	haveCollided = false;
	healthPoints = 1;
	acceleration = Vector3D(0.0f,0.0f,5.0f);
	velocity = Vector3D(0.0f,0.0f,30.0f);
	moveDirection = Vector3D(0.0f,0.0f,direction);

	if(direction > 0.0f)
		this->isEvil = true;
	else
		this->isEvil = false;

	mesh = new Mesh(meshFileName);
	texture = new Texture(textureFileName);
	collisionBox = new BoundingBox(mesh->getVerts(),mesh->getPoints());
	entityVBO = new VBO(*mesh);
	shader.initializeShader("Shaders/lighting.vert","Shaders/lighting.frag");
}

/**
 * Class destructor, free allocated memory.
 */
LaserBlast::~LaserBlast()
{
	delete texture;
	delete mesh;
	delete collisionBox;
	delete entityVBO;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void LaserBlast::updateEntity(const float elapsedTime)
{
	if(position.z >= 10.0f || position.z <= -150.0f ||  healthPoints == 0 )
		isDead = true;

	position.z += velocity.z * elapsedTime * moveDirection.z;
}

/**
 * Method is used to render entity.
 */
void LaserBlast::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		glTranslatef(position.x,position.y,position.z-1);
		glScalef(1.0f,0.4f,1.0f);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		Extensions::glActiveTexture(GL_TEXTURE0);
		int textureLocation = Extensions::glGetUniformLocation(shader.getShaderProgram(), "texture_color");
		Extensions::glUniform1i(textureLocation, 0);
		glBindTexture(GL_TEXTURE_2D, *texture->getTexture());
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
		Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB,entityVBO->VBOVertices);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO->VBONormals);
		glNormalPointer(GL_FLOAT, 0, 0);
		Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO->VBOTextureCoords);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, mesh->getPoints());
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glPopMatrix();
	shader.unbindShader();
}
