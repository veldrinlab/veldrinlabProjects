/**
 * File contains definition of SpaceShip class.
 * @file    SpaceShip.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */

#include "SpaceShip.h"
#include "Game.h"

using namespace boost;

/**
 * Constructor with initialize parameters.
 * @param   meshFileName is SpaceShip mesh file name.
 * @param   textureFileName is SpaceShip mesh texture file name.
 */
SpaceShip::SpaceShip(const char* meshFileName, const char *textureFileName, GameState* gameState)
{
	position = Vector3D(0.0f,0.0f,0.0f);
	velocity = Vector3D(5.0f,0.0f,5.0f);
	acceleration = Vector3D(1.0f,0.0f,1.0f);
	moveDirection = Vector3D(0.0f,0.0f,0.0f);
	healthPoints = 3;
	isDead = false;
	isEvil = false;
	haveCollided = false;
	blasterAccumulator = 0.0f;
	this->gameState = gameState;

	mesh = new Mesh(meshFileName);
	texture = new Texture(textureFileName);
	collisionBox = new BoundingBox(mesh->getVerts(),mesh->getPoints());
	entityVBO = new VBO(*mesh);
	shader.initializeShader("Shaders/lighting.vert","Shaders/lighting.frag");
}

/**
 * Class destructor, free allocated memory.
 */
SpaceShip::~SpaceShip()
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
void SpaceShip::updateEntity(const float elapsedTime)
{
	if(healthPoints == 0)
	{
		Game* game = this->gameState->game;
		game->setGameState(new GameOverState(game));
		gameState = game->getActualState();
	}

	position.x += velocity.x * moveDirection.x * elapsedTime;
	position.y += velocity.y * moveDirection.y * elapsedTime;
	position.z += velocity.z * moveDirection.z * elapsedTime;

	blasterAccumulator -= elapsedTime;
	moveDirection.set(0.0f,0.0f,0.0f);

}

/**
 * Method is used to render entity.
 */
void SpaceShip::renderEntity()
{
	shader.bindShader();
	glPushMatrix();
		glTranslatef(position.x,position.y,position.z);
		glRotatef(90.0f,1.0f,0.0f,0.0f);

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

/**
 * Method is used to set direction to move foreward.
 */
void SpaceShip::wKeyPressed()
{
	moveDirection.z = -1.0f;
}

/**
 * Method is used to set direction to move back.
 */
void SpaceShip::sKeyPressed()
{
	moveDirection.z = 1.0f;
}

/**
 * Method is used to set direction to move left.
 */
void SpaceShip::aKeyPressed()
{
	moveDirection.x = -1.0f;
}

/**
 * Method is used to set direction to move right.
 */
void SpaceShip::dKeyPressed()
{
	moveDirection.x = 1.0f;
}

/**
 * Method is used to shoot laser blast.
 */
void SpaceShip::spaceKeyPressed()
{
	if(blasterAccumulator <= 0.0f)
	{
		worldScene->push_back(shared_ptr<SceneEntity>(new LaserBlast("Data/laser.vel","Data/laser.bmp", this->position + Vector3D(0,0,-10),-1.0f)));
		blasterAccumulator = 1.0f;
	}
}

/**
 * Method is used to set pointer to world scene collection.
 * @param   worldScene is pointer to scene entietes collection.
 */
void SpaceShip::setWorldScene(std::vector<boost::shared_ptr<SceneEntity>>* worldScene)
{
	this->worldScene = worldScene;
}
