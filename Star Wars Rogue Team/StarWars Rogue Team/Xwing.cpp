/**
 * File contains definition of X-wing class.
 * @file    Xwing.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-21
 * @version 1.0
 */

#include "Xwing.hpp"
#include "SceneManager.hpp"

using namespace std;
using namespace boost;

namespace game
{

/** 
 * Constructor with initialize parameters.
 * @param	camera is pointer to scene camera object.
 * @param   meshFileName is Xwing mesh file name.
 * @param   textureFileName is Xwing mesh texture file name.
 */
Xwing::Xwing(Camera* camera, const char* meshFileName, const char* textureFileName)
{
	this->camera = camera;
	isDead = false;
	healthPoints = 1;
	blasterAccumulator = 0.1f;
	currentID = 0;
	faction = REBELION;

	rotation.set(0.0f,0.0f,0.0f);
	velocity.set(50.0f,50.0f,50.0f);
	acceleration.set(0.0f, 0.0f, 0.0f);
	position = camera->getPosition();
	moveDirection = camera->getViewDirection();

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(std::string("X-WingText"), std::string(textureFileName), TEXTURE);
	mesh = resManager->getResource(std::string("X-WingMesh"), std::string(meshFileName), MESH);
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
Xwing::~Xwing()
{
	delete collisionBox;
	if(Extensions::vboSupported)
		delete entityVBO;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void Xwing::updateEntity(const float elapsedTime)
{
	if(healthPoints <= 0)
		exit(0);

	float backUp = 0.0f;
	position = camera->getPosition();
	moveDirection = camera->getViewDirection();
	blasterAccumulator -= elapsedTime;

	backUp = position.x;
	position.x += velocity.x * moveDirection.x * elapsedTime;
	if(position.x <= -800.0f || position.x >= 800.0f)
		position.x = backUp;

	backUp = position.y;
	position.y += velocity.y * moveDirection.y * elapsedTime;
	if(position.y <= -740.0f || position.y >= 1000.0f)
		position.y = backUp;

	backUp = position.z;
	position.z += velocity.z * moveDirection.z * elapsedTime;
	if(position.z <= -700.0f || position.z >= 700.0f)
		position.z = backUp;
	
	camera->setPosition(position);
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void Xwing::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		float theta = 0.0f;
		Vector3D axis;
		camera->getOrientation().toAxisAngle(axis,theta);
		glTranslatef(position.x,position.y,position.z);
		glRotatef(theta, -axis.x, -axis.y, -axis.z);
		glTranslatef(0.0f,-0.3f,-0.5f);
		glRotatef(rotation.x,1.0f,0.0f,0.0f);
		glRotatef(rotation.y,0.0f,1.0f,0.0f);
		glRotatef(rotation.z,0.0f,0.0f,1.0f);
		glScalef(0.001f,0.001f,0.001f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(180.0f,0.0f,1,0.0f);
  
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
 * Method is used to handle accelerate ship signal.
 */
void Xwing::accelerateShip()
{
	velocity = Vector3D(100.0f,100.0f,100.0f);
	scene->getSpecialFXManager()->getMotionBlur()->setBlurRatio(0.9f);
}

/**
 * Method is used to hadnle slow down ship signal.
 */
void Xwing::slowDownShip()
{
	velocity = Vector3D(20.0f,20.0f,20.0f);
	scene->getSpecialFXManager()->getMotionBlur()->setBlurRatio(0.0f);
}

/**
 * Method is used to handle steer ship signal.
 */
void Xwing::steerShip()
{
	camera->mouseMoved();
}

/**
 * Method is used to handle rotate ship left signal.
 */
void Xwing::rotateLeft()
{
	rotation.z += 1.0f;
}

/**
 * Method is used to handle rotate ship right signal.
 */
void Xwing::rotateRight()
{
	rotation.z -= 1.0f;
}

/**
 * Method is used to handle shoot ship lasers signal.
 */
void Xwing::shootLasers()
{
	shootLaserBlast();
}

/**
 * Method is used to shoot laser blast which is used to destroy enemy spaceships. Xwing and Tie-fighet have got
 * two laser blasters.
 */
void Xwing::shootLaserBlast()
{
	if(blasterAccumulator <= 0.0f)
	{
		currentID += 1;
		currentID %= 2;
		this->camera->getOrientation();

		scene->addEntityToScene(new LaserBlast("Data/laser.vel","Data/laser.bmp",position,moveDirection,this->camera->getOrientation(),currentID));
		blasterAccumulator = 0.1f;
	}
}

/**
 * Method is used to set pointer to worldScene.
 * @param	worldScene is pointer to actual game scene.
 */
void Xwing::setScene(SceneManager* worldScene)
{
	this->scene = worldScene;
}

}
