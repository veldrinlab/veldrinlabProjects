/**
 * File contains definition of LaserBlast class.
 * @file    LaserBlast.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */

#include "LaserBlast.hpp"

namespace game
{

/** 
 * Constructor with initialize parameters.
 * @param   meshFileName is LaserBlast mesh file name.
 * @param   textureFileName is LaserBlast mesh texture file name.
 * @param	position is LaseBlast origin position vector.
 * @param	direction is LaserBlast move direction;
 * @param	orientation is LaserBlast initial orientation represented by Quaternion.
 * @param	id is laser blaster id.
 */
LaserBlast::LaserBlast(const char* meshFileName, const char* textureFileName,const Vector3D& position, const Vector3D& direction, const Quaternion& orientation,int id)
{
	this->position = position;
	this->moveDirection = direction;
	this->orientation = orientation;
	this->id = id;

	isDead = false;
	haveCollided = false;
	healthPoints = 1;
	lifeTime = 5.0f;
	acceleration = Vector3D(1.0f,1.0f,1.0f);
	velocity = Vector3D(100.0f,100.0f,100.0f);
	faction = LASER; //INDEPENDENT;

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(std::string(textureFileName), std::string(textureFileName), TEXTURE);
	mesh = resManager->getResource(std::string("LaserBlastMesh"), std::string(meshFileName), MESH);
	Mesh* tempMesh = static_cast<Mesh*>(mesh.get());
	collisionBox = new BoundingBox(tempMesh->getVerts(),tempMesh->getPoints());

	if(Extensions::vboSupported)
		entityVBO = new VBO(*tempMesh);
	
	//if(Extensions::shaderSupported)
	//	shader.initializeShader("Shaders/texture.vert","Shaders/texture.frag");
}

/**
 * Class destructor, free allocated memory.
 */
LaserBlast::~LaserBlast()
{
	delete collisionBox;
	if(Extensions::vboSupported)
		delete entityVBO;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void LaserBlast::updateEntity(const float elapsedTime)
{
	if((lifeTime -= elapsedTime) <= 0.0f)
		healthPoints = 0;

	if(healthPoints <= 0 )
		isDead = true;

	position.x += velocity.x * elapsedTime * moveDirection.x;
	position.y += velocity.y * elapsedTime * moveDirection.y;
	position.z += velocity.z * elapsedTime * moveDirection.z;

}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void LaserBlast::renderEntity()
{
//	shader.bindShader();
	glPushMatrix();
		float theta;
		Vector3D axis;
		orientation.toAxisAngle(axis,theta);
		glTranslatef(position.x,position.y,position.z);
		glRotatef(theta, -axis.x, -axis.y, -axis.z);

		glScalef(0.1f,0.04f,0.1f);
		//odpowiedni dzia³ka - dwa do wyboru
		glTranslatef(-10.0f + id*20.0f,-15.0f,-35.0f);

		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		
		if(Extensions::multiTextureSupported)
		{
			Extensions::glActiveTexture(GL_TEXTURE0);
			int textureLocation = Extensions::glGetUniformLocation(shader.getShaderProgram(), "texture_color");
			Extensions::glUniform1i(textureLocation, 0);
		}
		Texture* tempTexture = static_cast<Texture*>(texture.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
		Mesh* tempMesh = static_cast<Mesh*>(mesh.get());
		if(Extensions::vboSupported)
		{
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB,entityVBO->VBOVertices);
			glVertexPointer(3, GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO->VBONormals);
			glNormalPointer(GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, entityVBO->VBOTextureCoords);
			glTexCoordPointer(2, GL_FLOAT, 0, 0);

		}
		else
		{
			glVertexPointer(3, GL_FLOAT, 0, tempMesh->getVerts());
			glNormalPointer(GL_FLOAT, 0, tempMesh->getNormals());
			glTexCoordPointer(2, GL_FLOAT, 0, tempMesh->getCoords());
		}
		glDrawArrays(GL_TRIANGLES, 0, tempMesh->getPoints());	
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		collisionBox->drawBoundingBox();
	glPopMatrix();
//	shader.unbindShader();
}

}