/**
 * File contains definition of AT-ST enemy class.
 * @file    ATST.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-01-07
 * @version 1.0
 */

#include "ATST.hpp"

using namespace std;
using namespace boost;

namespace game
{

/**
 * Default, private constructor.
 */
ATST::ATST()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   meshFileName is AT-ST mesh file name.
 * @param   textureFileName is AT-ST mesh texture file name.
 * @param	position is origin position vector.
 */
ATST::ATST(const char* meshFileName, const char* textureFileName,const Vector3D& position)
{
	this->position = position;
	isDead = false;
	healthPoints = 10;
	faction = IMPERIAL;
	velocity = Vector3D(2.0f,2.0f,2.0f);
	blasterAccumulator = static_cast<float>(rand() % 2 + 1);

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(std::string("ATSTText"), std::string(textureFileName), TEXTURE);
	mesh = resManager->getResource(std::string("ATSTMesh"), std::string(meshFileName), MESH);
	Mesh* tempMesh = static_cast<Mesh*>(mesh.get());
	collisionBox = new BoundingBox(tempMesh->getVerts(),tempMesh->getPoints());

	if(Extensions::vboSupported)
		entityVBO = new VBO(*tempMesh);
	
	if(Extensions::shaderSupported)
		shader.initializeShader("Shaders/texture.vert","Shaders/texture.frag");
}

/**
 * Class destructor, free allocated memory.
 */
ATST::~ATST()
{
	delete collisionBox;
	if(Extensions::vboSupported)
		delete entityVBO;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void ATST::updateEntity(const float elapsedTime)
{
	if(healthPoints <=0 )
	{
		isDead = true;
	}
	
	blasterAccumulator -= elapsedTime;

	if(blasterAccumulator <= 0.0f)
	{
		Vector3D direction = *enemyPosition;
		direction -= position;

		LaserBlast* laser = new LaserBlast("Data/laser.vel","Data/laser2.bmp",position,direction,*enemyOrientation,0);
		laser->velocity = Vector3D(1.0f,1.0f,1.0f);

		shootedLasers->getShootedLasers()->push_back(boost::shared_ptr<SceneEntity>(laser));
		blasterAccumulator = static_cast<float>(rand() % 2 + 1);
	}
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void ATST::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		glTranslatef(position.x,position.y,position.z);
		glScalef(2.0f,2.0f,2.0f);

		glRotatef(-90,1.0f,0.0f,0.0f);
		glRotatef(-90,0.0f,0.0f,1.0f);
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
 * Method used to clone object in EnemyPrototypeFactory.
 * @return copy of current object.
 */
EnemyPrototype* ATST::clone(void)
{	
	return new ATST(*this); 
}

/**
 * Method is used to set pointer to scene shooted lasers collection.
 * @param	shootedLasers is pointer to scene shooted lasers collection.
 */
void ATST::setScene(/*std::vector<boost::shared_ptr<SceneEntity>>*/ShootedLasers* shootedLasers)
{
	this->shootedLasers = shootedLasers;
}

/**
 * Method is used to set pointer to enemy position object.
 * @param	position is pointer to enemy position vector.
 */
void ATST::setEnemyPosition(Vector3D* position)
{
	this->enemyPosition = position;
}

/**
 * Method is used to set pointer to enemy orientation object.
 * @param	orientation is pointer to enemy orientation quaternion.
 */
void ATST::setEnemyOrientation(Quaternion* orientation)
{
	this->enemyOrientation = orientation;
}

}