/**
 * File contains Renderer class definition.
 * @file    Renderer.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#include "Renderer.h"

using namespace std;
using namespace boost;

/** 
 * Class constructor.
 */
Renderer::Renderer(SceneManager* gameScene)
{
	this->gameScene = gameScene;
}

/**
 * Destrcutor, noting to do, no memory to deallocate.
 */
Renderer::~Renderer()
{

}

/**
 * Main game engine drawing method, used to render scene. Use double-buffering. Clear current buffer,
 * render all entities from current scene and apply special effects.
 */
void Renderer::renderScene()
{
	glEnable(GL_NORMALIZE);
	glClearColor (0.0f,0.0f,0.0f,0.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vector<boost::shared_ptr<SceneEntity>>* scene = gameScene->getWorldScene();

	for(vector<boost::shared_ptr<SceneEntity>>::const_iterator i = scene->begin(); i != scene->end(); ++i)
		(*i)->renderEntity();
		
	vector<boost::shared_ptr<ParticleSystem>>* effects = gameScene->getSpecialEffects();

	for(vector<boost::shared_ptr<ParticleSystem>>::const_iterator i = effects->begin(); i != effects->end(); ++i)
		(*i)->renderEffect();

	gameScene->getGameHud()->renderGameHud();

	glLoadIdentity();
    SDL_GL_SwapBuffers();
}
