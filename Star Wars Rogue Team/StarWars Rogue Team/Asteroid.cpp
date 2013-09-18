/**
 * File contains definition of Asteroid class.
 * @file    Asteroid.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-19
 * @version 1.0
 */
	
#include "Asteroid.hpp"

namespace game
{

/**
 * Default, private constructor.
 */
Asteroid::Asteroid()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   meshFileName is Asteroid mesh file name.
 * @param   textureFileName is Asteroid mesh texture file name.
 * @param	position is origin position vector.
 */
Asteroid::Asteroid(const char* meshFileName, const char* textureFileName,const Vector3D& position)
{
	this->position = position;
	isDead = false;
	healthPoints = 1;
	faction = ASTEROID; //INDEPENDENT; 

	velocity = Vector3D(2.0f,2.0f,2.0f);
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(std::string("AsteroidText"), std::string(textureFileName), TEXTURE);
	mesh = resManager->getResource(std::string("AsteroidMesh"), std::string(meshFileName), MESH);
	Mesh* tempMesh = static_cast<Mesh*>(mesh.get());
	collisionBox = new BoundingBox(tempMesh->getVerts(),tempMesh->getPoints());

	if(Extensions::vboSupported)
		entityVBO = new VBO(*tempMesh);
	
	if(Extensions::shaderSupported)
		shader.initializeShader("Shaders/texture.vert","Shaders/texture.frag");
}

/**
 * Method used to clone object in EnemyPrototypeFactory.
 * @return copy of current object.
 */
EnemyPrototype* Asteroid::clone()
{
	return new Asteroid(*this);
}

/**
 * Class destructor, free allocated memory.
 */
Asteroid::~Asteroid()
{
	delete collisionBox;
	if(Extensions::vboSupported)
		delete entityVBO;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void Asteroid::updateEntity(const float elapsedTime)
{
	if(healthPoints <= 0)
		isDead = true;
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void Asteroid::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		glTranslatef(position.x,position.y,position.z);
		glScalef(20.0f,20.0f,20.0f);

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

}
