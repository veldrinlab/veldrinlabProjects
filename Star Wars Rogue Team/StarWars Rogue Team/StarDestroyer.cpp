/**
 * File contains definition of StarDestroyer class.
 * @file    StarDestroyer.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-18
 * @version 1.0
 */

#include "StarDestroyer.hpp"

using namespace std;
using namespace boost;

namespace game
{

/** 
 * Constructor with initialize parameters.
 * @param   meshFileName is StarDestroyer mesh file name.
 * @param   textureFileName is StarDestroyer mesh texture file name.
 * @param	moveDirection is StarDestroyer move direction vector.
 * @param	orientation is StarDestroyer initial orientation represented by Quaternion.
 */
StarDestroyer::StarDestroyer(const char* meshFileName, const char* textureFileName,const Vector3D& moveDirection,const Quaternion& orientation)
{
	this->position = Vector3D(0.0f,0.0f,0.0f);
	this->orientation = orientation;
	this->moveDirection = moveDirection;
	isDead = false;
	healthPoints  = 10;
	blasterAccumulator = static_cast<float>(rand() % 5 + 2);

	velocity = Vector3D(0.0f,0.0f,0.0f);
	faction = IMPERIAL;

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(std::string("StarDestroyerText"), std::string(textureFileName), TEXTURE);
	mesh = resManager->getResource(std::string("StarDestroyerMesh"), std::string(meshFileName), MESH);
	Mesh* tempMesh = static_cast<Mesh*>(mesh.get());
	collisionBox = new BoundingBox(tempMesh->getVerts(), tempMesh->getPoints());
	if(Extensions::vboSupported)
		entityVBO = new VBO(*tempMesh);
	if(Extensions::shaderSupported)
		shader.initializeShader("Shaders/texture.vert","Shaders/texture.frag");

}

/**
 * Class destructor, free allocated memory.
 */
StarDestroyer::~StarDestroyer()
{
	delete collisionBox;
	if(Extensions::vboSupported)
		delete entityVBO;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void StarDestroyer::updateEntity(const float elapsedTime)
{
	if(healthPoints <= 0 )
		isDead = true;

	position.x += velocity.x * elapsedTime * moveDirection.x;
	position.y += velocity.y * elapsedTime * moveDirection.y;
	position.z += velocity.z * elapsedTime * moveDirection.z;

	blasterAccumulator -= elapsedTime;

	if(blasterAccumulator <= 0.0f)
	{
		Vector3D direction = *enemyPosition;
		direction -= position;

		LaserBlast* laser = new LaserBlast("Data/laser.vel","Data/laser2.bmp",position,direction,*enemyOrientation,0);
		laser->velocity = Vector3D(1.0f,1.0f,1.0f);
		shootedLasers->getShootedLasers()->push_back(boost::shared_ptr<SceneEntity>(laser));
		blasterAccumulator = static_cast<float>(rand() % 5 + 2);

	}
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void StarDestroyer::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		float theta = 0.0f;
		Vector3D axis;
		orientation.toAxisAngle(axis,theta);
		glTranslatef(position.x,position.y,position.z);
		glRotatef(theta, -axis.x, -axis.y, -axis.z);

		glTranslatef(10,5,0);
		glScalef(5.0f,5.0f,5.0f);

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
		//collisionBox->drawBoundingBox();
	glPopMatrix();
	shader.unbindShader();
}

/**
 * Method is used to set pointer to scene shooted lasers collection.
 * @param	shootedLasers is pointer to scene shooted lasers collection.
 */
void StarDestroyer::setScene(ShootedLasers* shootedLasers)
{
	this->shootedLasers = shootedLasers;
}

/**
 * Method is used to set pointer to enemy position object.
 * @param	position is pointer to enemy position vector.
 */
void StarDestroyer::setEnemyPosition(Vector3D* position)
{
	this->enemyPosition = position;
}

/**
 * Method is used to set pointer to enemy orientation object.
 * @param	orientation is pointer to enemy orientation quaternion.
 */
void StarDestroyer::setEnemyOrientation(Quaternion* orientation)
{
	this->enemyOrientation = orientation;
}

/**
 * Method used to clone object in EnemyPrototypeFactory.
 * @return copy of current object.
 */
EnemyPrototype* StarDestroyer::clone()
{
	return new StarDestroyer(*this);
}

}
