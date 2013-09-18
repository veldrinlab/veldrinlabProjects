/**
 * File contains Renderer class definition.
 * @file    Renderer.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#include "Renderer.hpp"

using namespace std;
using namespace boost;

namespace engine
{

/** 
 * Class constructor, get pointer to SceneManger to get actual scene tree to render.
 * @param sceneManager is pointer to current sceneManager.
 */
Renderer::Renderer(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}

/**
 * Destructor, noting to do, no memory to deallocate.
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
	glClearAccum(0.0,0.0,0.0,1.0);
	glClearStencil(0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	sceneManager->getCamera()->renderEntity();
	sceneManager->getSkyBox()->renderEntity();
	sceneManager->getPlayerShip()->renderEntity();

	if(sceneManager->getTerrain() != NULL)
		sceneManager->getTerrain()->renderEntity();


	vector< boost::shared_ptr<SceneEntity> >* scene = sceneManager->getWorldScene();

	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = scene->begin(); i != scene->end(); ++i)
		(*i)->renderEntity();

	sceneManager->getSpecialFXManager()->renderEffects();
	sceneManager->getGameHud()->renderGameHud();
	SDL_GL_SwapBuffers();

}

}
